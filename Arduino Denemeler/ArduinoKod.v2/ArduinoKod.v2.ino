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
}

void loop() {
  sensor_loop();
  uint16_t position = qtr.readLineBlack(sensorValues);

 if(tShapes < 8){
  
  if(sensorValues[0] >= 1200 && sensorValues[1] >= 1200 ) {
      justStop();
      delay(2000);
      forward();
      delay(50);
      sayac();
}
  if(sensorValues[3] >= 1030 && sensorValues[5] >= 1030 ) 
      forward();
      
  if(sensorValues[5]<1030)
    left();
    
  if(sensorValues[3]<1030)

        right();
}

/*   else if(tShapes>=8){
    back();
  if(sensorValues[3] >= 1350 && sensorValues[4] >= 1350) 
    forward();
      
  if(sensorValues[4]<1350)
    right();
    
  if(sensorValues[3]<1350)
    left();
if(sensorValues[0] >= 1350 && sensorValues[1] >= 1350 && sensorValues[2] >= 1350) {
      justStop();
}
}*/
}


void sensor_setup()
{
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){8, 10, 11,12,13}, SensorCount);
  qtr.setEmitterPin(7);

  Serial.begin(9600);
}

void sensor_loop()
{
  qtr.read(sensorValues);

  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();

  delay(250);
}

void forward () {
  digitalWrite(leftMotor_forward, LOW);
  digitalWrite(leftMotor_backward, HIGH);
  analogWrite(leftMotor_speed, 85);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 85);
}

void left () {
  digitalWrite(leftMotor_forward, LOW);
  digitalWrite(leftMotor_backward, HIGH);
  analogWrite(leftMotor_speed, 85);
  
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
  analogWrite(rightMotor_speed, 85);
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

void sayac(){
  tShapes++;
  Serial.print(tShapes);
  Serial.print('\t');

  Serial.println();
}
