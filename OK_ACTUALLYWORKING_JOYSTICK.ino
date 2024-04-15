// Define motor control pins
#define DIR2_PIN1 9   // Connect to the DIR2 input of MX1508 (PWM1 for Motor A)
#define DIR_PIN1 8   // Connect to the DIR input of MX1508 (DIR1 for Motor A)
#define DIR2_PIN2 11   // Connect to the DIR2 input of MX1508 (PWM1 for Motor A)
#define DIR_PIN2 12   // Connect to the DIR input of MX1508 (DIR1 for Motor A)
#define JOYSTICK_X_PIN A0  // Connect X-axis of joystick to analog pin A0
#define JOYSTICK_Y_PIN A1 //y direction pin
// Define motor directions
#define FORWARD 1
#define BACKWARD 0

// Define joystick threshold values
#define LEFT_THRESHOLD 100  // Adjust this threshold for left movement
#define RIGHT_THRESHOLD 900 // Adjust this threshold for right movement

void setup() {
  // Initialize motor control pins
  pinMode(DIR2_PIN1, OUTPUT);
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(DIR2_PIN2, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);

  // Initialize joystick pin
  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_Y_PIN, INPUT);
}

void loop() {
  // Read X-axis value of joystick
  int joystickXValue = analogRead(JOYSTICK_X_PIN);
  int joystickYValue = analogRead(JOYSTICK_Y_PIN);
  // Check if joystick is moved all the way to the left or right
  if (joystickXValue <= LEFT_THRESHOLD) {
    setMotorDirectionMotor1(BACKWARD); // Move motor backward

  } else if (joystickXValue >= RIGHT_THRESHOLD) {
    setMotorDirectionMotor1(FORWARD);  // Move motor forward
   
  } else {
    digitalWrite(DIR_PIN1, LOW);
    digitalWrite(DIR2_PIN1,LOW);
  }

  if (joystickYValue <= LEFT_THRESHOLD) {
    setMotorDirectionMotor2(BACKWARD); // Move motor backward

  } else if (joystickYValue >= RIGHT_THRESHOLD) {
    setMotorDirectionMotor2(FORWARD);  // Move motor forward
   
  } else {
    digitalWrite(DIR_PIN2, LOW);
    digitalWrite(DIR2_PIN2,LOW);
  }

}

void setMotorDirectionMotor1(int direction) {
  if (direction == FORWARD) {
    digitalWrite(DIR_PIN1, HIGH); // Set direction to forward
    digitalWrite(DIR2_PIN1,LOW);
  } else {
    digitalWrite(DIR2_PIN1, HIGH); // Set direction to backward
    digitalWrite(DIR_PIN1, LOW);
  }
}

void setMotorDirectionMotor2(int direction) {
  if (direction == FORWARD) {
    digitalWrite(DIR_PIN2, HIGH); // Set direction to forward
    digitalWrite(DIR2_PIN2,LOW);
  } else {
    digitalWrite(DIR2_PIN2, HIGH); // Set direction to backward
    digitalWrite(DIR_PIN2, LOW);
  }
}