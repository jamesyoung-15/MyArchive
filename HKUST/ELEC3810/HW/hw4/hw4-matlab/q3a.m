load("ELEC4830_BIEN4310_homework4.mat");

preferredDirection = [30 120 210 300];
numNeurons = length(preferredDirection);
spikedData = zeros(numNeurons, length(movingDirection));

k=3;

for i=1:numNeurons
    spikedData(i,:)=exp(k*cosd(movingDirection-preferredDirection(i)));
end

figure;

for i=1:numNeurons
    subplot(4,1,i)
    plot(movingDirection,spikedData(i,:));
    xlabel('Moving Direction');
    ylabel('FiringRate');
    xlim([0 360]);
end