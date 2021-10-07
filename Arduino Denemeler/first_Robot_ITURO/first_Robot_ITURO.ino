/* Written by Alican Bayındır 
   For ITURO Competition
   
   Ilk olarak sensörleri ve motorları tanımlayarak başlanıldı.*/
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

//Burda robotun kesişime geldiğini anlamak için değişken oluşturuldu (İleride kullanımını anlatıldı. Anlattılan yer * ile işaretlenmiştir.)
int tShapes = 0;


//Sensör ve motorları kuruldu - Arduinoya tanıtıldı.
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

  //*** Burda tabelaların önünde durma sayısı 8 den küçükse normal prosedürü işlemesi için bir kod satırı
  //yazdıldı bu kod satırında sensörler eğer kesişim noktasına geliyorsa duruyor 2 saniye bekliyor ve
  //yoluna devam ediyor.***
if(tShapes<=8)
{
  if(digitalRead(garipSensor) == 1 && digitalRead(ortaSensor) == 1)
  {
    justStop();
    delay(2000);
    forward();
    delay(100);
    tShapes++;
  }

  //Aşağıdaki 3 satır if komutu aracın çizgi izleyen sensörlere göre konumunu ayarlaması eğer 
  //düz bir konumda ise ileri doğru gitmesi için yazıldı.
  
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

//Aşağıdaki satırlar kesişim sayısı (tShapes) ==8 ise dur, geriye dön, ve başlangıç noktasına geldiğinde dur
//komutunu vermek için yazıldı.

  else
{
  justStop();
  delay(2000);
  back();
  
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
}

//Bu fonksiyon ileri fonksiyonu aracın ileri gitmesini sağlar.
void forward () 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 60);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 65);
}

//Bu fonksiyon sol fonksiyonu aracın sola gitmesini sağlar.
void left () 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 60);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 0);
}

//Bu fonksiyon sağ fonksiyonu aracın sağa gitmesini sağlar.
void right () 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 0);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 65);
}

//Bu fonksiyon aracın durmasını sağlar.
void justStop() 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 0);
  
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  analogWrite(rightMotor_speed, 0);
}

//Bu fonksiyon motorlara giden akımın yönünü değiştirerek birinin ileriye diğerinin geriye
//dönmesiyle aracın geriye dönmesini sağlar. leftMotor_forward ile rightMotor_forward diğer 
//fonksiyonlara baktığımızda HIGH komutunu alır burda birinin HIGH diğerinin LOW olma sebebi
//akım yönünün değiştirilmek istenilmesinden dolayı.
void back() 
{
  digitalWrite(leftMotor_forward, HIGH);
  digitalWrite(leftMotor_backward, LOW);
  analogWrite(leftMotor_speed, 50);
  
  digitalWrite(rightMotor_forward, LOW);
  digitalWrite(rightMotor_backward, HIGH);
  analogWrite(rightMotor_speed, 50);
}
