const int IR1_PIN = 5;
const int IR2_PIN = 6;
const int IR3_PIN = 7;
const int motor1_IN1 = 11;
const int motor1_IN2 = 12;
const int motor2_IN3 = 13;
const int motor2_IN4 = 14;

void setup() {
  pinMode(motor1_IN1, OUTPUT);
  pinMode(motor1_IN2, OUTPUT);
  pinMode(motor2_IN3, OUTPUT);
  pinMode(motor2_IN4, OUTPUT);
  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(IR3_PIN, INPUT);
}

void loop() {
  if (digitalRead(IR1_PIN) == HIGH) {
    digitalWrite(motor1_IN1, HIGH);
    digitalWrite(motor1_IN2, LOW);
    delay(5000);
  } else {
    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, LOW);
  }

  if (digitalRead(IR2_PIN) == HIGH) {
    delay(5000);
    digitalWrite(motor1_IN1, LOW);
    digitalWrite(motor1_IN2, LOW);
    digitalWrite(motor2_IN3, HIGH);
    digitalWrite(motor2_IN4, LOW);
    delay(5000);
  } else {
    digitalWrite(motor2_IN3, LOW);
    digitalWrite(motor2_IN4, LOW);
  }

  if (digitalRead(IR3_PIN) == HIGH) {
    digitalWrite(motor2_IN3, LOW);
    digitalWrite(motor2_IN4, LOW);
  }
}
