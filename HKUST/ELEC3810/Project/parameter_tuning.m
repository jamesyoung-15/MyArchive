% load data
load("ELEC3810_Final_project.mat");

% store original in case need to refer
originalTrainSpike = trainSpike;
originalTrainState = trainState;
originalTestSpike = testSpike;


% 1. Remove nan values %
nanIndices = any(isnan(trainSpike), 1) | isnan(trainState);
trainSpike(:, nanIndices) = [];
trainState(nanIndices) = [];



% 2. Data Check w/ PCA and t-SNE %
% reshapedSpike = reshape(trainSpike',[],size(trainSpike,1));
% [coeff, score, ~,~, explained] = pca(reshapedSpike);
% figure;
% gscatter(score(:,1), score(:,2),trainState','rb', 'ox');
% title('2D PCA of Filtered Training Data');
% xlabel('Component 1');
% ylabel('Component 2');
% legend('State 0', 'State 1');
% 
% numDims = 2; % Number of dimensions for the t-SNE plot
% perplexity = 30; % Perplexity parameter for t-SNE
% tsneData = tsne(trainSpike', 'NumDimensions', numDims, 'Perplexity', perplexity);
% figure;
% gscatter(tsneData(:, 1), tsneData(:, 2), trainState', 'rb', 'ox');
% title('t-SNE Plot of Filtered Training Data');
% xlabel('Component 1');
% ylabel('Component 2');
% legend('State 0', 'State 1');




% 5. Parameter Tuning
hyperparams = [
    struct('MaxEpochs', 30, 'MiniBatchSize', 64, 'LearningRate', 0.01, 'historySize', 0, 'lstmHiddenUnits', 64);
    struct('MaxEpochs', 30, 'MiniBatchSize', 64, 'LearningRate', 0.01, 'historySize', 1, 'lstmHiddenUnits', 64);
    struct('MaxEpochs', 30, 'MiniBatchSize', 64, 'LearningRate', 0.01, 'historySize', 5, 'lstmHiddenUnits', 64);
    struct('MaxEpochs', 30, 'MiniBatchSize', 64, 'LearningRate', 0.01, 'historySize', 8, 'lstmHiddenUnits', 64);
    struct('MaxEpochs', 30, 'MiniBatchSize', 64, 'LearningRate', 0.01, 'historySize', 10, 'lstmHiddenUnits', 64);
];

figure();
hold on;
k = 0;
for i=1:size(hyperparams, 1)
    % 3. Preprocess: include history to input, split dataset to training and validation %
    historySize = hyperparams(i).historySize;
    paddedTrainSpike = [zeros(16, historySize), trainSpike]; % Pad trainSpike with zeros to keep vector length when adding history
    
    % Concatenate previous spike history to trainSpike
    historyTrainSpike = [];
    for j = 0:historySize
        historyTrainSpike = [historyTrainSpike; paddedTrainSpike(:, j+1:end-historySize+j)];
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
    
    % 4. Algorithm: LSTM
    
    % design layers
    layers = [
        sequenceInputLayer(size(trainData{1}, 1)) % Use size of individual sequence in cell array
        lstmLayer(hyperparams(i).lstmHiddenUnits, 'OutputMode', 'last')
        fullyConnectedLayer(32)
        reluLayer()
        fullyConnectedLayer(2)
        softmaxLayer()
        classificationLayer()
    ];
    
    options = trainingOptions('adam', ...
        'MaxEpochs', hyperparams(i).MaxEpochs, ...
        'InitialLearnRate', hyperparams(i).LearningRate,...
        'MiniBatchSize', hyperparams(i).MiniBatchSize, ...
        'ValidationData', {valData, valLabels'}, ...
        'Verbose', true, ...
        'Plots', 'training-progress');
    
    [net, info] = trainNetwork(trainData, trainLabels, layers, options);
    
    
    % Predict labels for validation data
    valPredictions = classify(net, valData);
    
    % Calculate the validation accuracy
    accuracy = sum(valPredictions == valLabels) / numel(valLabels);
    disp("Validation Accuracy for run " + i + " :");
    disp(accuracy);
    % plot validation and training accuracy curves
    plot(smooth(info.ValidationAccuracy));
    % plot(smooth(info.TrainingAccuracy));
    k = k+1;
    legendLabels{k} = "Validation Acc. History Size " + hyperparams(i).historySize;
    % k = k+1;
    % legendLabels{k} = "Training Acc. Learning Rate " + hyperparams(i).LearningRate;
end

hold off;
xlabel('Iterations');
ylabel('Accuracy');
legend(legendLabels);

% Confusion matrix
% figure();
% confusionchart(valLabels, valPredictions);

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
testState = classify(net, testData);
