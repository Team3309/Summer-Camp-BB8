#include <Arduino.h>
#include <analogWrite.h>

// Import the Dabble libraries
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

//When ESP 32 faces the user, Motor1 is on the right side(port1)
// Motor1 Low, High = forward
// Motor2 High, Low = forward
#define ENA 18//4
#define IN1 19//2
#define IN2 21//15
#define IN3 15//21
#define IN4 4 //19
#define ENB 2//18

#define LEFT_MOTOR_INVERTED false
#define RIGHT_MOTOR_INVERTED false

void setup() {
  // Start bluetooth. This is where the ESP32's bluetooth name is declared
  Dabble.begin("BB8_xx");

  // Define pin functions
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Get data from phone
  Dabble.processInput();

  // Get the joystick values from Dabble
  float dabbleX = GamePad.getXaxisData();
  float dabbleY = GamePad.getYaxisData();

  // The Dabble gamepad joystick returns values from -7 to 7, but we need -255 to 255, so do some math to convert
  int joyX = (int) (dabbleX * (255/7) + .5);
  int joyY = (int) (dabbleY * (255/7) + .5);

  if (GamePad.isUpPressed()) {
    joyY = 255;
  }
  if (GamePad.isDownPressed()) {
    joyY = -255;
  }
  if (GamePad.isLeftPressed()) {
    joyX = -255;
  }
  if (GamePad.isRightPressed()) {
    joyX = 255;
  }

  setArcadeSpeeds(joyY, joyX);
}

void setArcadeSpeeds (float throttle, float turn) {
  throttle *= -1;
  setMotorSpeeds (throttle - turn, throttle + turn);
}

void setMotorSpeeds (int left, int right) {
  setLeftMotorSpeed(left);
  setRightMotorSpeed(right);
}

void setLeftMotorSpeed (int left) {
  if (LEFT_MOTOR_INVERTED) {
    left *= -1;
  }
  if (left > 0) {
    analogWrite(ENA, left);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
  } else if (left < 0) {
    analogWrite(ENA, left);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    analogWrite(ENA, 0);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
  }
}

void setRightMotorSpeed (int right) {
  if (RIGHT_MOTOR_INVERTED) {
    right *= -1;
  }
  if (right > 0) {
    analogWrite(ENB, right);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (right < 0) {
    analogWrite(ENB, right);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    analogWrite(ENB, 0);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
  }
}
