function plotTrajectory( decodeDirection )
% plot the trajectory for the given decoded directions
%   decodeDirection is a 6x2 matrix, each row represents the decoded moving
%   direction

if (size(decodeDirection,2)~=2)
   decodeDirection=decodeDirection'; 
end
decodeDirection=decodeDirection./sqrt(sum(decodeDirection.^2,2));
trajectory(1,:)=[2 2];
for i=1:size(decodeDirection,1)
    trajectory(i+1,:)=trajectory(i,:)+decodeDirection(i,:);
end
plot(trajectory(:,1),trajectory(:,2),'r','LineWidth',4);
% xlim([1.5 5.5]);
% ylim([0.5 3.5]);

end

