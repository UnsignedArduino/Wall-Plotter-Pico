#include <Arduino.h>
#include <Servo.h>
#include <Stepper.h>

const uint8_t LEFT_STEPPER_PIN_1 = 4;
const uint8_t LEFT_STEPPER_PIN_2 = 2;
const uint8_t LEFT_STEPPER_PIN_3 = 5;
const uint8_t LEFT_STEPPER_PIN_4 = 3;
const uint8_t RIGHT_STEPPER_PIN_1 = 8;
const uint8_t RIGHT_STEPPER_PIN_2 = 6;
const uint8_t RIGHT_STEPPER_PIN_3 = 9;
const uint8_t RIGHT_STEPPER_PIN_4 = 7;
const uint16_t STEPPER_STEPS = 2048;
const uint16_t STEPPER_RPM = 10;

const uint8_t SERVO_PIN = 10;
const uint16_t SERVO_MIN_US = 700;
const uint16_t SERVO_MAX_US = 2300;

Stepper leftStepper(STEPPER_STEPS, LEFT_STEPPER_PIN_1, LEFT_STEPPER_PIN_2,
                    LEFT_STEPPER_PIN_3, LEFT_STEPPER_PIN_4);
Stepper rightStepper(STEPPER_STEPS, RIGHT_STEPPER_PIN_1, RIGHT_STEPPER_PIN_2,
                     RIGHT_STEPPER_PIN_3, RIGHT_STEPPER_PIN_4);
Servo servo;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  leftStepper.setSpeed(STEPPER_RPM);
  rightStepper.setSpeed(STEPPER_RPM);
  servo.attach(SERVO_PIN, SERVO_MIN_US, SERVO_MAX_US);
}

void loop() {
  leftStepper.step(5);
  rightStepper.step(5);

  static uint8_t angle = 0;
  static int8_t dir = 1;
  servo.writeMicroseconds(map(angle, 0, 180, SERVO_MIN_US, SERVO_MAX_US));
  angle += dir;
  if (angle == 0 || angle == 180) {
    dir *= -1;
  }
}
