
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

[LOG file example](/StepperLogExampleFullCycle.log)