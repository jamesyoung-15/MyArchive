preferredDirection = [30 120 210 300];
spikedData = [5 0 12 18];
k=3;


L = length(spikedData);
decodeDirections = zeros(1,2);

for i=1:L
    decodeDirections(1,1) = decodeDirections(1,1) + cosd(preferredDirection(i))*spikedData(i)/sum(spikedData);
    decodeDirections(1,2) = decodeDirections(1,2) + sind(preferredDirection(i))*spikedData(i)/sum(spikedData);
end

disp('Decoded Moving Direction Vector:');
disp(decodeDirections);

disp('spiked data: ');
disp(spikedData);

disp('sum of firing: ')
disp(sum(spikedData));
