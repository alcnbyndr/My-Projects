#include <QTRSensors.h>
QTRSensors qtr;

const uint8_t SensorCount = 5;
uint16_t sensorValues[SensorCount];

const int leftMotor_speed = 9;
const int rightMotor_speed = 6;
const int leftMotor_forward = 2;
const int leftMotor_backward = 3;
const int rightMotor_forward = 5;
const int rightMotor_backward = 4;

int tShapes = 0;

void setup()
{
    sensor_setup();

    pinMode(leftMotor_speed, OUTPUT);
    pinMode(rightMotor_speed, OUTPUT);
    pinMode(leftMotor_forward, OUTPUT);
    pinMode(leftMotor_backward, OUTPUT);
    pinMode(rightMotor_forward, OUTPUT);
    pinMode(rightMotor_backward, OUTPUT);
     Serial.begin(9600);
}

void loop() {
  qtr.read(sensorValues);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
  
 if(tShapes < 8)
 {
  if(sensorValues[0] >= 650 && sensorValues[1] >= 650 && sensorValues[2] >= 650) 
  {
      justStop();
      delay(2000);
      forward();
      delay(200);
      tShapes++;
  }
  if(sensorValues[3] >= 650 && sensorValues[4] >= 650) 
      forward();
      
  if(sensorValues[4]<650)
    right();
    
  if(sensorValues[3]<650)
    left();

}

   else if(tShapes>=8){
    back();
  if(sensorValues[3] >= 650 && sensorValues[4] >= 650) 
    forward();
      
  if(sensorValues[4]<650)
    right();
    
  if(sensorValues[3]<650)
    left();
if(sensorValues[0] >= 1000 && sensorValues[1] >= 1000 && sensorValues[2] >= 1000) 
      justStop();
}
}

void sensor_setup()
{
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){8, 13, 12, 11, 10}, SensorCount);
  qtr.setEmitterPin(7);
}

void forward () {
  digitalWrite(leftMotor_forward, LOW);
  digitalWrite(leftMotor_backward, HIGH);
  analogWrite(leftMotor_speed, 60);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 60);
}

void left () {
  digitalWrite(leftMotor_forward, LOW);
  digitalWrite(leftMotor_backward, HIGH);
  analogWrite(leftMotor_speed, 60);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 0);
}

void right () {
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 0);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 60);
}

void justStop() {
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 0);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 0);
}

void back() {
  digitalWrite(leftMotor_forward, LOW);
  digitalWrite(leftMotor_backward, HIGH);
  analogWrite(leftMotor_speed, 60);
  
  digitalWrite(rightMotor_forward, LOW);
  digitalWrite(rightMotor_backward, HIGH);
  analogWrite(rightMotor_speed, 60);
}
