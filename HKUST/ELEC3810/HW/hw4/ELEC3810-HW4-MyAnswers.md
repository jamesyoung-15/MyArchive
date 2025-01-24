# ELEC3810 Homework 4
Name: Young, James Yang (20740589)

### Question 1: If the moving direction of the subject is 90°, calculate the simulated spike rate for each of the 4 neurons.

Neuron 1 with $\mu=30^{\circ}$: 

$=e^{3*cos(90-30)}=e^\frac{3}{2}$

Neuron 2 with $\mu=120^{\circ}$:

$=e^{3*cos(90-120)}=e^\frac{3\sqrt{3}}{2}$

Neuron 3 with $\mu=210^{\circ}$:

$=e^{3*cos(90-210)}=\frac{1}{e^\frac{3}{2}}$

Neuron 4 with $\mu=300^{\circ}$:

$=e^{3*cos(90-300)}=\frac{1}{e^\frac{3\sqrt{3}}{2}}$


### Question 2: If the neural firings of the 4 neurons are (5,0,12,18), calculate the decoded moving direction using the population vector method

Moving direction vector = [0.0839 -0.5454]

### Question 3a: Generate the simulated spikes for all the moving directions for all the 4 neurons

Plot of Spike Rates in terms of Moving Directions

![](./q3a.png)


### Question 3b: Decode the movement direction (vector) for each trial and Input this matrix into plotTrajectory(decodedDirection)

![](./q3b.png)