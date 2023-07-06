/*

Program for controlling a stepper motor for satellite rotation in a vacuum chamber.
It simulates the passage of a satellite under the sunlit conditions on orbit. When the sun hides behind the Earth - it returns to the previous state.
The start is when the sun rises, the end is when the sun sets.

Initial data:

Total rotation time 97.5 minutes
Time while sunlit 33 minutes
Time in shadow 64.5 minutes
number of test cycles 5-7
Calculations:

Rotation angle 121.846
Motor step 1.8 degrees
Stepper motor should make 67,777 steps
The sunlit side lasts 1980 seconds
One step in 29.213 seconds
Total time of orbit 5850

*/

#include <Arduino.h>

#define ORBIT_TIME 5850           // Orbit cycle
#define ORBIT_SUN_LIGHT 1980      // The Sun light
#define ORBIT_SHADOW 3870         // Shadow

#define STEPPER_MOTOR_STEP_ANGLE 1.8
#define ANGLE_LIGHT_ROTATION 122        // Calculations is: 121.846 
#define STEP_PERIOD 29                  // Calculations is: 29.213
#define NUMBER_OF_STEPS 68              // Calculations is: 67.777



// function declarations:
float NextStep(float, float);

void setup() {
  // put your setup code here, to run once:
  int result = NextStep(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(ORBIT_TIME);
}

// function definitions:
float NextStep(float x, float y) {
  return x + y;
}