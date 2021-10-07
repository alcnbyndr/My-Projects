#define garipSensor 13  
#define sagSensor 12
#define ortaSensor 11
#define solSensor 10

const int leftMotor_speed = 9;
const int rightMotor_speed = 6;
const int leftMotor_forward = 3;
const int leftMotor_backward = 2;
const int rightMotor_forward = 5;
const int rightMotor_backward = 4;

int tShapes = 0;

void setup() 
{
  pinMode(solSensor, INPUT);
  pinMode(ortaSensor, INPUT);
  pinMode(sagSensor, INPUT);
  pinMode(garipSensor, INPUT);

  pinMode(leftMotor_forward, OUTPUT);
  pinMode(leftMotor_backward, OUTPUT);
  pinMode(rightMotor_forward, OUTPUT);
  pinMode(rightMotor_backward, OUTPUT);
}


void loop() {
  
//if(tShapes<8)
//{
  if(digitalRead(garipSensor) == 1 && digitalRead(ortaSensor) == 1)
  {
    justStop();
    delay(2000);
    forward();
    delay(100);
    tShapes++;
  }
  if(digitalRead(solSensor) == 0 && digitalRead(ortaSensor) == 1 && digitalRead(sagSensor) == 0)
  {
    forward();
  }

  if(digitalRead(solSensor) == 0 && digitalRead(ortaSensor) == 0 && digitalRead(sagSensor) == 1)
  {
    right();
  }

  if(digitalRead(solSensor) == 1 && digitalRead(ortaSensor) == 0 && digitalRead(sagSensor) == 0)
  { 
    left();
  }
}
  /*else
{
  if(digitalRead(solSensor) == 0 && digitalRead(ortaSensor) == 1 && digitalRead(sagSensor) == 0)
  {
    forward();
  }

  if(digitalRead(solSensor) == 0 && digitalRead(ortaSensor) == 0 && digitalRead(sagSensor) == 1)
  {
    right();
  }

  if(digitalRead(solSensor) == 1 && digitalRead(ortaSensor) == 0 && digitalRead(sagSensor) == 0)
  { 
    left();
  }

  if(digitalRead(garipSensor) == 1 && digitalRead(solSensor) == 1 && digitalRead(ortaSensor) == 0 && digitalRead(sagSensor) == 0)
  {
    justStop();
  }
 }
}*/

void forward () 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 60);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 65);
}


void left () 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 60);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 0);
}

void right () 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 0);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 65);
}

void justStop() 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 0);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 0);
}

void back() 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 50);
  
  digitalWrite(rightMotor_forward, LOW);
  digitalWrite(rightMotor_backward, HIGH);
  analogWrite(rightMotor_speed, 50);
}
