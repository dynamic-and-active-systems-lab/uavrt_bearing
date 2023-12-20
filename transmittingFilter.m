function [pulseTableOut] = transmittingFilter(pulseTable)
%Looks for pulses that are overlapping in time and selects the pulse groupt
%with the higher score, eliminating the one that likely wasn't transmitting

idList = unique(pulseTable.tagID);
pulseTableOut = pulseTable;
totalMask2Pull = false(size(pulseTable,1),1);
if numel(idList)>2
    error('UAV-RT: Pulse transmitting decision logic only works with a pulse table that contains two tagID values.')
elseif numel(idList) == 2
    maskA = pulseTable.tagID == idList(1);
    maskB = pulseTable.tagID == idList(2);
    tableA = pulseTable(maskA, :);
    tableB = pulseTable(maskB, :);
    
    %Round to nearest 0.02 s;
    timeASorted = sort(tableA.time);
    timeBSorted = sort(tableB.time);
    timeASortedRepMat = repmat(timeASorted, 1 , numel(timeBSorted));
    timeBSortedRepMat = repmat(timeBSorted.', numel(timeASorted), 1);

    diffMat = abs( timeASortedRepMat - timeBSortedRepMat);

    similarityMatrix = diffMat <= 0.02;
    
    [Ainds,Binds] = find(similarityMatrix);

    for i = 1:numel(Ainds)
        currAGroupSeqCount = tableA.groupSeqCount(Ainds(i));
        currBGroupSeqCount = tableB.groupSeqCount(Binds(i));

        scoresA = tableA.stftMag2(tableA.groupSeqCount == currAGroupSeqCount);
        scoresB = tableB.stftMag2(tableB.groupSeqCount == currBGroupSeqCount);

        sumScoresA = sum(scoresA);
        sumScoresB = sum(scoresB);

        if sumScoresA > sumScoresB
            mask2Pull = pulseTableOut.groupSeqCount == currBGroupSeqCount & ...
                        maskB;
        elseif sumScoresA < sumScoresB
            mask2Pull = pulseTableOut.groupSeqCount == currAGroupSeqCount & ...
                        maskA;
        else
            mask2Pull = [];
        end

        totalMask2Pull = mask2Pull | totalMask2Pull;

    end

    % groupSeqListA = unique(tableA.groupSeqCount);
    % groupSeqListB = unique(tableB.groupSeqCount);
end
pulseTableOut(totalMask2Pull,:) = [];

% figure;plot(pulseTable.time(maskA), pulseTable.stftMag2(maskA),'.');
% hold on;plot(pulseTable.time(maskB), pulseTable.stftMag2(maskB),'o')
% hold on;plot(pulseTableOut.time, pulseTableOut.stftMag2,'g^')
end