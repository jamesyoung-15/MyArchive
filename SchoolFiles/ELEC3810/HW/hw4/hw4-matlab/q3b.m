% load data
load("ELEC4830_BIEN4310_homework4.mat");

[trials,numNeurons ]= size(neuralFiring);
decodeDirections = zeros(trials,2);
preferredDirection = [30 120 210 300];

for i=1:trials
    decodeDirections(i,1) =  cosd(preferredDirection)*neuralFiring(i,:).'/sum(neuralFiring(i,:));
    decodeDirections(i, 2) = sind(preferredDirection)*neuralFiring(i,:).'/sum(neuralFiring(i,:));
end


plotTrajectory(decodeDirections);

disp('Decoded Moving Direction Vector:');
disp(decodeDirections);