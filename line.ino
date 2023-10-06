#define LirSensor  7
#define RirSensor  8

#define motor1EN  3
#define motor1A   4
#define motor1B   5

#define motor2EN 11
#define motor2A  12
#define motor2B  13

void setup() {
  pinMode(LirSensor, INPUT);
  pinMode(RirSensor, INPUT);

  pinMode(motor1EN, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);

  pinMode(motor2EN, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

}

void loop() {
  int LSensorValue = digitalRead(LirSensor);
  int RSensorValue = digitalRead(RirSensor);

  if (LSensorValue == HIGH && RSensorValue == HIGH) {
    moveForward();
  }
  else if (LSensorValue == LOW && RSensorValue == HIGH) {
    turnLeft();
  }
  else if (LSensorValue == HIGH && RSensorValue == LOW) {
    turnRight();
  }
  else {
    moveForward();
  }
  delay(200);
}

void moveForward() {
  
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 70); 
  analogWrite(motor2EN, 70); 
}

void turnRight() {

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  
  analogWrite(motor1EN, 20); 
  analogWrite(motor2EN, 70);
}

void turnLeft() {
  
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);

  analogWrite(motor1EN, 20); 
  analogWrite(motor2EN, 70);
}

void stopCar() {
  digitalWrite(motor1A, LOW);                                                                                                                                                                   
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 0);
  analogWrite(motor2EN, 0);
}
