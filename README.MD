
# Application for stepper motor. Direct drive. On orbit rotation imitation


Program for controlling a stepper motor for satellite rotation in a vacuum chamber.
It simulates the passage of a satellite under the sunlit conditions on orbit. When the sun hides behind the Earth - it returns to the previous state.   
The start is when the sun rises, the end is when the sun sets.   

## Initial data:

> Total rotation time **97.5** minutes.   
> Time while sunlit **43** minutes.   
> Time in shadow **54.5** minutes.   
> Number of test cycles **5-7**.   

## Calculations:

> Rotation angle **201.23**.   
> Motor step **1.8** degrees.   
> Reduction coefficient **0.166667** (1/6).   

***

> Stepper motor should make **112** steps.   
> The sunlit side lasts **3270** seconds.   
> One step in **29.196** seconds.   
> Total time of orbit **5850**.   

### If we need to use reduction we have:

> One step in **4.866** seconds.   
> Stepper motor should make **672** steps.   

***

## Required components for orbit rotation imitation   

1. Stepper Motor 86HSE12N-BC38   
2. Stepper Motor Reducer PX86N006S0 (reduction ratio 1:6)   
3. Servo Driver HSS758   
4. Power Supply Unit 70V 12A   
5. Cables for connecting the stepper motor to the servo drive and cables for connecting to the power supply   
6. Arduino Pro Mini Board   
7. USB-TTL Module HW-728   
8. Tact Button   
9. USB-MicroUSB Cable   
10. Wires for connecting the Arduino Pro Mini to the servo drive   

## Electrical connection scheme of Arduino Pro Mini to peripherals and servo driver   

![Schematic electricity connections](/Schematic_OrbitImitatorRotation.JPG "Schematic electricity connections")   

[Electrical connection scheme](/Schematic_OrbitImitatorRotation.pdf)

[LOG file example](/StepperLogExampleFullCycle.log)