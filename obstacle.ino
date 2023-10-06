#include <Servo.h>

#define trigPin   9
#define echoPin  10

#define servoPin  6

#define motor1EN  3
#define motor1A   4
#define motor1B   5

#define motor2EN 11
#define motor2A  12
#define motor2B  13

#define obstacleDistance 20
#define safeDistance     15 

Servo ultrasonicServo;

int rightdistance=0 , leftdistance=0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(motor1EN, OUTPUT);
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);

  pinMode(motor2EN, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  
  ultrasonicServo.attach(servoPin);
  ultrasonicServo.write(90);
  Serial.begin(9600);
}

void loop() {
  int distance = getUltrasonicDistance();

  if (distance <= obstacleDistance) {
    moveBackward();
    delay(400); 
    stopCar();
    delay(1000);
    ultrasonicServo.write(5);
    rightdistance = getUltrasonicDistance();
    delay(1000);
    ultrasonicServo.write(175);
    leftdistance = getUltrasonicDistance();
    delay(1000);
    ultrasonicServo.write(90);
    delay(500);
    if(rightdistance<leftdistance){
      turnLeft();
      delay(1000);
      moveForward();
    }else if(rightdistance>leftdistance){
      turnRight();
      delay(1000);
      moveForward();
    }else if(rightdistance<obstacleDistance && leftdistance<obstacleDistance){
      stopCar();
      delay(1000);
    }
    
    
  }
   else{
    moveForward();
  }

  Serial.print(distance);
  Serial.print("\t");
  Serial.print(rightdistance);
  Serial.print("\t");
  Serial.println(leftdistance);
  
}

int getUltrasonicDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  return distance;
}

void moveBackward() {

  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  
  analogWrite(motor1EN, 90);
  analogWrite(motor2EN, 90);
}

void moveForward() {
  
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 90); 
  analogWrite(motor2EN, 90); 
}

void turnLeft() {

  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  
  analogWrite(motor1EN, 90); 
  analogWrite(motor2EN, 90);
}

void turnRight() {
  
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 90); 
  analogWrite(motor2EN, 90);
}

void stopCar() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  
  analogWrite(motor1EN, 0);
  analogWrite(motor2EN, 0);
}
