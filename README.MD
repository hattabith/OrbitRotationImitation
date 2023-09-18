
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

> One step in **243304** microseconds.   
> Stepper motor should make **13440** steps.   
> When satellite in shadow we slowly return in start position and wait end of cycle **2580** seconds   
> Return speed is not defined, I use about 4:30 minutes return   

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

## How to log into the file   

> Recommended application is:   
> Terminalbpp v1.93b
> Realterm 2.0.0.70

## Step-by-step instructions for simulating satellite rotation in orbit and recording a log file   

- Make sure that the microcontroller is programmed with the appropriate firmware.   
- Check if a terminal program capable of writing timestamped log files is installed on your computer.   
- Connect the Arduino board to the stepper motor servo driver.   
- Connect the servo driver to the stepper motor and power supply.   
- Switch on the servo driver.   
- In the servo driver menu, select the step display mode. To do this, press the button on the left to enter the menu. Use the up/down arrows to select the dP-PoS mode and press the ENT key.   
- Power up the microcontroller board.   
- Launch the terminal program and set up a timestamped file recording.   
- Connect to the microcontroller board via the appropriate COM port.   
- Press the START button on the microcontroller board to begin the cycle.   
- If you need to repeat the cycle, press the START button again.   

## Log file example   

[LOG file example](/20230818122756.log)   

## License   

[MIT License](/LICENSE)   
