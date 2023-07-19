/*
*
*OrientationRotationProMini
*
*MIT License
*Copyright (c) 2023 Dmytro Myronov
*
*
*Program for controlling a stepper motor for satellite rotation in a vacuum chamber.
*It simulates the passage of a satellite under the sunlit conditions on orbit. When the sun hides behind the Earth - it returns to the previous state.
*The start is when the sun rises, the end is when the sun sets.
*
*Initial data:
*
*Total rotation time 97.5 minutes
*Time while sunlit 43 minutes
*Time in shadow 54.5 minutes
*number of test cycles 5-7
*
*
*Calculations:
*
*Rotation angle 201.23 (fact 201.6)
*Motor step 1.8 degrees
*Stepper motor should make 112 steps
*The sunlit side lasts 3270 seconds (fact 3269.952)
*In the Earth shadow lasts 2580 seconds
*One step in 29.196 seconds
*Total time of orbit 5850
*
*If we need to use reduction we have:
*One step in 4.866 seconds
*Stepper motor should make 672 steps
*
*/

#include <Arduino.h>
#include <BasicStepperDriver.h>

#define ORBIT_TIME 5850           // Orbit cycle
#define ORBIT_SUN_LIGHT 3270      // The Sun light
#define ORBIT_SHADOW 2580         // Shadow

#define STEPPER_MOTOR_STEP_ANGLE 1.8
#define STEPPER_MOTOR_STEP_ANGLE_REDUCTION 0.3
#define REDUCTION_COEFFICIENT 0.166667
#define ANGLE_LIGHT_ROTATION 201.6        // Calculations is: 121.846 
#define STEP_PERIOD 29.196                // Calculations is: 29.213
#define STEP_PERIOD_REDUCTION 4.866       // If use reduction
#define NUMBER_OF_STEPS 112               // Calculations is: 67.777
#define NUMBER_OF_STEPS_REDUCTION 672     // If use reduction

/*-----------------------------------------------------------------*/

uint32_t timer = 0;                  // timer for millis function. Period for steps
boolean startRotation = false;       // state stepper motor
byte cyclesNumber = 0;               // test cycles number

// function declarations:
float NextStep(float, float);

void setup() {
  // serial port configuration
  Serial.begin(9600);

  int result = NextStep(2, 3);

  Serial.println("Total rotation time 97.5 minutes");
  Serial.println("Time while sunlit 33 minutes");
  Serial.println("Time in shadow 64.5 minutes");
  Serial.println("");
  Serial.println("Rotation angle 122.4");
  Serial.println("Motor step 1.8 degrees");
  Serial.println("Stepper motor should make 68 steps");
  Serial.println("The sunlit side lasts 1980 seconds");
  Serial.println("One step in 29.213 seconds");
  Serial.println("Total time of orbit 5850");
  Serial.println("");
  Serial.println("**********************************");
  Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:

}

// function definitions:
float NextStep(float x, float y) {
  return x + y;
}