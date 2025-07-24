#include <Stepper.h>

// Define the number of steps per revolution
unsigned long steps_per_revolution = 4 * 1600;

// Define the pins connected to the driver
const int enable_pin = 8;
const int step_pin = 7;
const int direction_pin = 6;

// Define the motor speed (in RPM)
const int motor_speed = 280; //For BDA medium, use 250

// Create a new instance of the Stepper class
Stepper motor(steps_per_revolution, step_pin, direction_pin);

void setup() {
  // Set the enable pin as an output
  pinMode(enable_pin, OUTPUT);
  
  // Set the motor speed in RPM
  motor.setSpeed(motor_speed);

  Serial.begin(9600);
}

void loop() {
  // Enable the motor
  digitalWrite(enable_pin, LOW);
  
  // Set the motor direction (1 for clockwise, 0 for counter-clockwise)
  //motor.setSpeed(100);
  
  // Move the motor for 1 revolution
  for(int i = 150; i <= motor_speed; i++){
    motor.setSpeed(i);
    Serial.println(i);
    motor.step(5*steps_per_revolution);
  }
  for(unsigned long revolution = 1; revolution <= 15000; revolution++){
    motor.step(steps_per_revolution);
  }
  
  //digitalWrite(enable_pin, HIGH);
  
  // Wait for a brief moment before the next rotation
  delay(10000);
}
