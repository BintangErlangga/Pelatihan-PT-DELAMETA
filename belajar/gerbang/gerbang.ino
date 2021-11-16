// inisialisasi
#include <NewPing.h>
#include <Servo.h>

int echo    = 12;
int triger = 11;
int buz     =2;
int R       =4;
int G       =5;
int servo   =3;
int flag    =0;
int IR      =6;
int batas   =200;


Servo myservo ;
NewPing cm(triger,echo,batas);


void setup() {
  // fungsi
  Serial.begin (9600);
  pinMode(buz,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(IR,INPUT);
  myservo.attach(servo);
  
}

void loop() {
  // baca data
  int bacaIR = digitalRead(IR);
  int bacajarak = cm.ping_cm();

  bacaIR  = map(bacaIR,1,0,0,1);

  Serial.print(" IR :" + String(bacaIR));
  Serial.print(" jarak :" + String(bacajarak));
  Serial.println();

  //logika
  if (bacaIR ==1 && flag ==0){
      flag=1;
      delay(100);
  }else if (bacaIR==1 && flag == 1){
      flag=0;
      delay(100);
  }

  if (flag ==1){
  myservo.write(0);
  delay(100);
  }else if (bacajarak >10 && bacajarak <15){
   myservo.write(90);
   delay(100);
  }
 

}
