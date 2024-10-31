# AunomomousVehiclesl5

The controller operates using a time gap range of 2 to 3 seconds, with a desired space gap of 2.5 seconds. To reduce oscillations when the lead car's speed fluctuates, the desired acceleration generated when the space gap is between 2 and 3 seconds is scaled down by a reduction factor. This factor is set to 1 when the space gap is below 2 or above 3 seconds, and it reduces to 0 when the space gap is exactly 2.5 seconds. An exponential function is used to smoothly transition the factor in between, ensuring that when the space gap is close to the desired gap, the ego car becomes less sensitive to speed variations in the lead car, effectively reducing oscillations.

When this controller is used in a multi-vehicle simulation, the ego car’s speed should fluctuate minimally in response to small lead car speed changes.
