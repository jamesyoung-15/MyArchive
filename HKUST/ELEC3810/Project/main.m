% remove existing variables
clc;
clear;

% load data
load("ELEC3810_Final_project.mat");

% store original in case need to refer
originalTrainSpike = trainSpike;
originalTrainState = trainState;
originalTestSpike = testSpike;

% 5. Hyper-parameter settings
historySize = 10; % Number of previous spike history to include
learningRate = 0.01;
batchSize = 64;
epochs = 30;
lstmHiddenUnits = 64;


% 1. Remove nan values %
nanIndices = any(isnan(trainSpike), 1) | isnan(trainState);
trainSpike(:, nanIndices) = [];
trainState(nanIndices) = [];



% 2. Data Check w/ PCA and t-SNE %
reshapedSpike = reshape(trainSpike',[],size(trainSpike,1));
[coeff, score, ~,~, explained] = pca(reshapedSpike);
figure;
gscatter(score(:,1), score(:,2),trainState','rb', 'ox');
title('2D PCA of Filtered Training Data');
xlabel('Component 1');
ylabel('Component 2');
legend('State 0', 'State 1');

numDims = 2; % Number of dimensions for the t-SNE plot
perplexity = 30; % Perplexity parameter for t-SNE
tsneData = tsne(trainSpike', 'NumDimensions', numDims, 'Perplexity', perplexity);
figure;
gscatter(tsneData(:, 1), tsneData(:, 2), trainState', 'rb', 'ox');
title('t-SNE Plot of Filtered Training Data');
xlabel('Component 1');
ylabel('Component 2');
legend('State 0', 'State 1');


% 3. Preprocess: include history to input, split dataset to training and validation %

paddedTrainSpike = [zeros(16, historySize), trainSpike]; % Pad trainSpike with zeros to keep vector length when adding history

% Concatenate previous spike history to trainSpike
historyTrainSpike = [];
for i = 0:historySize
    historyTrainSpike = [historyTrainSpike; paddedTrainSpike(:, i+1:end-historySize+i)];
end

% PCA
% reshapedSpike = reshape(historyTrainSpike',[],size(historyTrainSpike,1));
% [coeff, score, ~,~, explained] = pca(reshapedSpike);
% figure;
% gscatter(score(:,1), score(:,2),trainState','rb', 'ox');

% Split the data into training and validation sets
cv = cvpartition(size(historyTrainSpike, 2), 'HoldOut', 0.2);
trainIdx = training(cv);
valIdx = test(cv);

% Training data
trainData = num2cell(historyTrainSpike(:, trainIdx), 1); % Convert to cell array
trainLabels = categorical(trainState(trainIdx)'); % Convert labels to categorical

% Validation data
valData = num2cell(historyTrainSpike(:, valIdx), 1); % Convert to cell array
valLabels = categorical(trainState(valIdx)'); % Convert labels to categorical



%4. Algorithm: LSTM Neural Network %

layers = [
    sequenceInputLayer(size(trainData{1}, 1)) % Use size of individual sequence in cell array
    lstmLayer(64, 'OutputMode', 'last')
    fullyConnectedLayer(32)
    reluLayer()
    fullyConnectedLayer(2)
    softmaxLayer()
    classificationLayer()
];

options = trainingOptions('adam', ...
    'MaxEpochs', epochs, ...
    'InitialLearnRate', learningRate,...
    'MiniBatchSize', batchSize, ...
    'ValidationData', {valData, valLabels'}, ...
    'Verbose', true, ...
    'Plots', 'training-progress');

net = trainNetwork(trainData, trainLabels, layers, options);



% plot network layers
% lgraph = layerGraph(layers);
% figure();
% plot(lgraph);

% Predict labels for validation data
valPredictions = classify(net, valData);

% Calculate the validation accuracy
accuracy = sum(valPredictions == valLabels) / numel(valLabels);
disp("Validation Accuracy:")
disp(accuracy);

% Confusion matrix
figure();
confusionchart(valLabels, valPredictions);

% 6. predict test spikes
paddedTestSpike = [zeros(16, historySize), testSpike]; % Pad testSpike with zeros for history inclusion

% Concatenate previous spike history to testSpike
historyTestSpike = [];
for i = 0:historySize
    historyTestSpike = [historyTestSpike; paddedTestSpike(:, i+1:end-historySize+i)];
end

% Convert test data to a cell array
testData = num2cell(historyTestSpike, 1);

% Predict labels for test data
decodedState = classify(net, testData);

save('result.mat', "decodedState");
