#define motor1EN  3
#define motor1A   4
#define motor1B   5

#define motor2EN 11
#define motor2A  12
#define motor2B  13

void setup() {
  pinMode(motor1EN, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);

  pinMode(motor2EN, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    
    // Forward
    if (command == 'F') {
      moveForward();
    }
    // Backward
    else if (command == 'B') {
      moveBackward();
    }
    // Left
    else if (command == 'L') {
      turnLeft();
    }
    // Right
    else if (command == 'R') {
      turnRight();
    }
    // Stop
    else if (command == 'S') {
      stopCar();
    }
  }
}

void moveBackward() {

  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  
  analogWrite(motor1EN, 200);
  analogWrite(motor2EN, 200);
}

void moveForward() {
  
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 200); 
  analogWrite(motor2EN, 200); 
}

void turnRight() {

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  
  analogWrite(motor1EN, 200); 
  analogWrite(motor2EN, 200);
}

void turnLeft() {
  
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 200); 
  analogWrite(motor2EN, 200);
}

void stopCar() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 0); 
  analogWrite(motor2EN, 0); 
}
