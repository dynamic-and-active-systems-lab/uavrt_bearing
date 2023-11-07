function closeStatus = writeToBearingFile(bearingFilePath, parentFileName, tagID, bearing_deg, tau, latitude_deg, longitude_deg, alt_AGL_m, alt_ASL_m, time_start_s, time_end_s)

[fileDirectory, ~, ~] = fileparts(bearingFilePath);

tempBearingFilePath = [fileDirectory, filesep, 'bearings_temp.csv'];

bearingFileAlreadyExists = isfile(bearingFilePath);

tempbearingFileAlreadyExists = isfile(tempBearingFilePath);

%Remove old temp bearing file if it wasn't deleted properly previously
msg0 = 'UAV-RT: Unable to delete existing temp bearing file. System reported';

%See note below near the rename command for why this sprintf command is
%needed. The intermittent error described there would occasionally occur
%here as well. 
newTempFilePath_1 = sprintf('%s',tempBearingFilePath);

if tempbearingFileAlreadyExists
     if coder.target('MATLAB')
        [status0, ~] = system(['rm "', tempBearingFilePath,'"']);
     else
        status0 = int8(-1);%Assigned so coder knowns expected data type. 
        %Causes intermittent error. 
        %status0 = coder.ceval('remove', coder.ref(tempBearingFilePath));
        status0 = coder.ceval('remove', coder.ref(newTempFilePath_1));
        if status0~=0
            coder.ceval('perror',coder.ref(msg0));
        end
     end

end


tag_id_fspec = '%u';
parentFileName_fspec = '%s';
bearing_fspec = '%f';
tau_fspec = '%f';
latitude_fspec = '%f';
longitude_fspec = '%f';
alt_AGL_fspec = '%f';
alt_ASL_fspec = '%f';
startTime_fspec = '%f';
endTime_fspec = '%f';

d = ',';

total_fspec = [tag_id_fspec, d, ...
               parentFileName_fspec, d, ...
               bearing_fspec, d, ...
               tau_fspec, d, ...
               latitude_fspec, d, ...
               longitude_fspec, d, ...
               alt_AGL_fspec, d, ...
               alt_ASL_fspec, d, ...
               startTime_fspec, d, ...
               endTime_fspec,'\n'];

currParentFileName = parentFileName;

if bearingFileAlreadyExists
    %Read bearing file and see if a bearing for this parent file has already been written
    %If so, append new estimate and remove the old ones - then rewrite the
    %bearing file contents
    %If not, simply append new bearing to the end of the entries. 
    
    [tableIn] = readbearingcsv(bearingFilePath);
    
    nTableInRows = size(tableIn, 1);

    %Logical vector - true for all entries with the same parent file as filepath
    alreadyInBearingList = false(nTableInRows,1);
    for i = 1:nTableInRows
        alreadyInBearingList(i) = strcmp(currParentFileName, tableIn.parentFileName{i});
    end
    
    %Build temp table with new entry and append to old table
    parentFileName = {''};%So coder knows the type
    parentFileName{1} = currParentFileName;
    
    variableNames = {'tagID','parentFileName','bearing','tau',...
                'latitude_deg','longitude_deg',...
                'alt_AGL_m','alt_ASL_m',...
                'time_start_s','time_end_s'};

    tableTemp = table(tagID,parentFileName, bearing_deg, tau,...
                      latitude_deg, longitude_deg, ...
                      alt_AGL_m, alt_ASL_m,...
                      time_start_s, time_end_s, ...
                      'VariableNames', variableNames);
    tableOut = [tableIn;tableTemp];

    %Delete any entries that were from this file
    %Append false so we don't delete the entry we just added
    rowDeletionLogic = [alreadyInBearingList; false];
    rowKeepLogic = ~rowDeletionLogic;
    tableOut = tableOut(rowKeepLogic,:);
    
%     if any([alreadyInBearingList; false])
%         tableOut(alreadyInBearingList,:) = [];
%     end
    nTableOutRows = size(tableOut, 1);

    %Write out the table to the temp bearing file. 
    %We use a temp file so that if there is an error or system shutdown
    %during the write, we don't lose the original file. 
    fid = fopen(tempBearingFilePath,'w');
    for i = 1:nTableOutRows
        fprintf(fid, total_fspec, tableOut.tagID(i),...
                                  tableOut.parentFileName{i},...
                                  tableOut.bearing(i),...
                                  tableOut.tau(i), ...
                                  tableOut.latitude_deg(i), ...
                                  tableOut.longitude_deg(i), ...
                                  tableOut.alt_AGL_m(i), ...
                                  tableOut.alt_ASL_m(i), ...
                                  tableOut.time_start_s(i), ...
                                  tableOut.time_end_s(i));
    end

    closeStatus = fclose(fid);

    msg3 = 'UAV-RT: Error opening or closing temporary bearing file during write operation. ';

    if fid == -1 | closeStatus == -1
        if coder.target('MATLAB')
            error(msg3)
        else
            coder.ceval('perror',coder.ref(msg3));
        end
    end


    %Delete the original bearing file, then rename the temp as the primary
    %file
    if coder.target('MATLAB')
        [status1, cmdout1] = system(['rm "', bearingFilePath,'"']);
        [status2, cmdout2] = system(['mv "', tempBearingFilePath,'" "', bearingFilePath, '"']);
    else

        %retVal = coder.ceval('getcwd', coder.ref(untokenizedDir), 200);
        status1 = int8(-1);%Assigned so coder knowns expected data type. 
        status2 = int8(-1);        
        %status1 = coder.ceval('remove', coder.ref(originalBearingPathStringinQuotes));
        
        msg1 = 'UAV-RT: Unable to delete original bearing file. System reported: ';

        %Print out bearing file name to new variable. This is a patch to
        %fix problems in generated code where the rename operation was
        %producing filenames like bearing.csvmpl.csv, which was garble of
        %the bearing.csv and the rotation_example.csv filenames. I couldn't
        %figure out why this was happening (only occured on Linux - not
        %Mac), but assumed it was related to the intermittent rename errors
        %I was getting on the Mac with the rename operation.
        newbearingFilePath = sprintf('%s',bearingFilePath);


        %fprintf('attempting to delete original bearing file...\n')
        status1 = coder.ceval('remove', coder.ref(newbearingFilePath));
        if status1 ~= 0
            coder.ceval('perror',coder.ref(msg1));
        end

        %Debugging code for intermittent rename errors
        %fprintf('%s\n', tempBearingFilePath)
        %fprintf('%s\n', bearingFilePath)
        % fprintf('PAUSING.....\n')
        % pause(10);
        % if isfile(bearingFilePath)
        %     fprintf('Bearing file path is valid\n')
        % else
        %     fprintf('Bearing file path is NOT valid\n')
        % end
        % 
        % if isfile(tempBearingFilePath)
        %     fprintf('Temp bearing file path is valid\n')
        % else
        %     fprintf('Temp bearing file path is NOT valid\n')
        % end


        msg2 = 'UAV-RT: Unable to rename temp bearing file as primary bearing file. System reported: ';

        %For reasons I can't determine, using tempBearingFilePath in the
        %rename commands below would occasionally fail at run time with the
        %error 'No such file or directory'. I excluded issues with
        %temporary write access by looping the rename command if it failed.
        %I also showed that a static path with the same data held in
        %tempBearingFilePath did not reproduce the error. I was unable to
        %determine the cause after looking through bearing.cpp after code
        %gen. Running the sprintf command extracts the text of
        %tempBearingFilePath and the error doesn't reoccur. I don't know
        %why this happen. 
        %newTempFilePath = '/Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_bearing/bearings_temp.csv';
        newTempFilePath_2 = sprintf('%s',tempBearingFilePath);
        %fprintf('%s\n', tempBearingFilePath) %To show these contain the same string
        %fprintf('%s\n', newTempFilePath)
        %Line below will intermittently cause a runtime error. 
        %status2 = coder.ceval('rename', coder.ref(tempBearingFilePath) , coder.ref(bearingFilePath));
        status2 = coder.ceval('rename', coder.ref(newTempFilePath_2) , coder.ref(newbearingFilePath));
        if status2~=0
            coder.ceval('perror',coder.ref(msg2));
        end

        cmdout1 = sprintf('%d',status1);
        cmdout2 = sprintf('%d',status2);
    end
    
    % if status1~=0 | status2~=0
    %     if status1~=0
    %         fprintf('UAV-RT: Unable to delete original bearing file. System reported: %s \n ', cmdout1);
    %     end
    %     if status2~=0
    %         fprintf('UAV-RT: Unable to rename temp bearing file as primary bearing file. System reported: %s \n', cmdout2);
    %     end
    % end

else
    %Create the bearing file and print the data
    fid = fopen(bearingFilePath,'a');
    fprintf(fid, total_fspec, tagID, currParentFileName, bearing_deg, tau,...
                              latitude_deg, longitude_deg, ...
                              alt_AGL_m, alt_ASL_m, ...
                              time_start_s, time_end_s);
    closeStatus = fclose(fid);

    msg4 = 'UAV-RT: Error creating or closing bearing file during write operation. ';

    if fid == -1 | closeStatus == -1
        if coder.target('MATLAB')
            error(msg4)
        else
            coder.ceval('perror',coder.ref(msg4));
        end
    end

end

end