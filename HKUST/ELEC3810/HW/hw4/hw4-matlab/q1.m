theta = 90;  % Moving direction
mu = [30, 120, 210, 300];  % Preferred directions
kappa = 3;  % Tuning parameter

% Calculate simulated spike rates
r1 = exp(kappa * cosd(theta - mu(1)));
r2 = exp(kappa * cosd(theta - mu(2)));
r3 = exp(kappa * cosd(theta - mu(3)));
r4 = exp(kappa * cosd(theta - mu(4)));

% Plotting the simulated spike rates
figure;
bar([mu(1), mu(2), mu(3), mu(4)], [r1, r2, r3, r4]);
title('Spike Rates for Moving Direction 90^\circ');
xlabel('\mu (\theta)');
ylabel('Spike Rate');

% Given neural firings
neural_firings = [5, 0, 12, 18];

% Preferred directions vectors for the four neurons
c1 = [cosd(mu(1)), sind(mu(1))];
c2 = [cosd(mu(2)), sind(mu(2))];
c3 = [cosd(mu(3)), sind(mu(3))];
c4 = [cosd(mu(4)), sind(mu(4))];

% Calculate decoded moving direction vector
decoded_direction = (neural_firings(1) * c1 + neural_firings(2) * c2 + neural_firings(3) * c3 + neural_firings(4) * c4) / sum(neural_firings);

% Calculate the angle of the decoded direction
decoded_angle = atan2d(decoded_direction(2), decoded_direction(1));

disp('Decoded Moving Direction Vector:');
disp(decoded_direction);
disp(['Decoded Angle: ' num2str(decoded_angle) ' degrees']);

