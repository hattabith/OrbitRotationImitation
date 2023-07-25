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
*Motor step reduction 0.3 degrees
*Motor step reduction and step resolution 4000 is 0.05
*Stepper motor should make 112 steps
*Stepper motor should make 13440 steps if use reduction and step resolution 4000 (default value)

*The sunlit side lasts 3270 seconds 
*In the Earth shadow lasts 2580 seconds
*Total time of orbit 5850
*
*If we need to use reduction and step resolution we have:
*One step in 243304 microseconds
*Stepper motor should make 13440 steps
*
*When satellite in shadow we slowly return in start position and wait end of cycle 2580 seconds
*Return speed non specified, I use about 4:30 minutes return
*
*/

#include <Arduino.h>
#include <BasicStepperDriver.h>

#define ORBIT_TIME 5850           // Orbit cycle
#define ORBIT_SUN_LIGHT 3270      // The Sun light
#define ORBIT_SHADOW 2580         // Shadow

#define STEPPER_MOTOR_STEP_ANGLE 1.8                  // If motor steps is 200
#define STEPPER_MOTOR_STEP_ANGLE_REDUCTION 0.3        // If use reduction
#define STEPPER_MOTOR_STEP_ANGLE_REDUCTION_4000 0.05  // If motor steps is 4000 (current value, default for driver)
#define REDUCTION_COEFFICIENT 0.166667                // Reduction is 1:6
#define ANGLE_SUN_LIGHT_ROTATION 201.6                // The Sun is shining on satellite
#define STEP_PERIOD_MILLIS 29196                      // If motor steps is 200
#define STEP_PERIOD_REDUCTION_MICROS_4000 243304L     // If motor steps is 4000 (current value, default for driver)
#define NUMBER_OF_STEPS 112                           // If motor steps is 200
#define NUMBER_OF_STEPS_REDUCTION_4000 13440          // If use reduction and motor speed is 4000

#define MOTOR_STEPS 4000    // Current value, default for stepper driver
#define DIR 7               // Direction pin
#define STEP 8              // Pulse pin
#define ENABLE 9            // Enable pin
#define RPM 120             // Rotate per minutes 
#define MICROSTEPS 1        // Micro steps (1=full step, 2=half step etc.)

/*-----------------------------------------------------------------*/

unsigned long timerStep = 0;         // timer for micros function. Period for steps
unsigned long timerMessage = 0;      // timer for serial port message
unsigned long timerReturn = 0;       // timer for return to start position
boolean startCycle = false;          // state stepper motor
byte cyclesNumber = 0;               // test cycles number

/*-----------------------------------------------------------------*/

BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

// function declarations:
float NextStep(float, float);

void setup() {

  delay(10000);
  // serial port configuration
  Serial.begin(9600);

  stepper.begin(RPM, MICROSTEPS);

  int result = NextStep(2, 3);

  Serial.println("");
  Serial.println("Stepper motor with reduction!!! (1/6)");
  Serial.println("");  
  Serial.println("Total rotation time 97.5 minutes");
  Serial.println("Time while sunlit 54.5 minutes");
  Serial.println("Time in shadow 43 minutes");
  Serial.println("");
  Serial.println("Rotation angle 201");
  Serial.println("Motor step 1.8 degrees");
  Serial.println("Stepper motor should make 13440 steps");
  Serial.println("The sunlit side lasts 1980 seconds");
  Serial.println("One step in 243300 microseconds");
  Serial.println("Total time of orbit 5850");
  Serial.println("");
  Serial.println("**********************************");
  Serial.println();

  delay(5000);

}

void loop() {

  Serial.println("The Sun light *************************");
  for (int i = 0; i < NUMBER_OF_STEPS_REDUCTION_4000; i++){
    stepper.move(-1);
    Serial.print("Step number: ");
    Serial.println(i);
    delay(STEP_PERIOD_REDUCTION_MICROS_4000);
    delayMicroseconds(STEP_PERIOD_REDUCTION_MICROS_4000);
  }
  Serial.println("Shadow ********************************");
  for (int i = NUMBER_OF_STEPS_REDUCTION_4000; i > 0; i--){
    stepper.move(1);
        Serial.print("Step number: ");
    Serial.println(i);
    delay(10);
  }
  delay(2445600);
  Serial.println("Cycle finish ***************************");

}

// function definitions:
float NextStep(float x, float y) {
  return x + y;
}