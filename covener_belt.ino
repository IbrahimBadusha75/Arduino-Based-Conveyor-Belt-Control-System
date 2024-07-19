// Define pin numbers for IR sensors and motor driver inputs
const int IR1_PIN = 5;    // IR sensor 1 pin (detects Motor 1 on)
const int IR2_PIN = 6;    // IR sensor 2 pin (detects Motor 1 off and Motor 2 on)
const int IR3_PIN = 7;    // IR sensor 3 pin (detects Motor 2 off)

// Define motor driver pins
const int motor1_IN1 =11 ;  // L298N IN1
const int motor1_IN2 = 12;  // L298N IN2
const int motor2_IN3 = 13;  // L298N IN3
const int motor2_IN4 = 14;  // L298N IN4

void setup() {
  // Initialize motor driver pins as outputs
  pinMode(motor1_IN1, OUTPUT);
  pinMode(motor1_IN2, OUTPUT);
  pinMode(motor2_IN3, OUTPUT);
  pinMode(motor2_IN4, OUTPUT);
  
  // Initialize IR sensor pins as inputs
  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(IR3_PIN, INPUT);
}

void loop() {
  // Check IR1 to detect an object and turn Motor 1 on
  if (digitalRead(IR1_PIN) == HIGH) {
    digitalWrite(motor1_IN1, HIGH);
    digitalWrite(motor1_IN2, LOW);
    delay(5000);
  } else {
    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, LOW);  // Disable Motor 1
  }

  // Check IR2 to detect an object, turn off Motor 1 after 5 seconds, and turn Motor 2 on
  if (digitalRead(IR2_PIN) == HIGH) {
    delay(5000);  // 5-second delay
    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, LOW);  // Stop Motor 1
    digitalWrite(motor2_IN3, HIGH); // Run Motor 2 forward
    digitalWrite(motor2_IN4, LOW);
    delay(5000);
  } else {
    digitalWrite(motor2_IN3, LOW);
    digitalWrite(motor2_IN4, LOW);  // Disable Motor 2
  }

  // Check IR3 to detect an object and turn Motor 2 off
  if (digitalRead(IR3_PIN) == HIGH) {
    digitalWrite(motor2_IN3, LOW);
    digitalWrite(motor2_IN4, LOW);  // Stop Motor 2
  }
}
