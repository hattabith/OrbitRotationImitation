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
#define STEP_PERIOD 29196                // Calculations is: 29.213
#define STEP_PERIOD_REDUCTION 243       // If use reduction
#define STEP_PERIOD_REDUCTION_MICROS 300
#define NUMBER_OF_STEPS 112               // Calculations is: 67.777
#define NUMBER_OF_STEPS_REDUCTION 13440     // If use reduction

#define MOTOR_STEPS 4000
#define DIR 7
#define STEP 8
#define ENABLE 9
#define RPM 120
#define MICROSTEPS 1

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
  // put your main code here, to run repeatedly:


  // need to do
  // 1. add button for start cycle
  // 2. rewrite code on micros
  // 3. add print to serial in degrees

  //stepper.rotate(2160);
  //stepper.move(- MOTOR_STEPS * MICROSTEPS);
  //delay(5000);

  //stepper.move(1);
  Serial.println("The Sun light *************************");
  for (int i = 0; i < NUMBER_OF_STEPS_REDUCTION; i++){
    stepper.move(-1);
    Serial.print("Step number: ");
    Serial.println(i);
    delay(STEP_PERIOD_REDUCTION);
    delayMicroseconds(STEP_PERIOD_REDUCTION_MICROS);
  }
  Serial.println("Shadow ********************************");
  for (int i = NUMBER_OF_STEPS_REDUCTION; i > 0; i--){
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