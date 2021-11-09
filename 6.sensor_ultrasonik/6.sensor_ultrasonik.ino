#include <NewPing.h>

//Inisialisasi pembuatan variable
int triger =12;
int echo =11;
int batas =200; //Maksimal 400 cm
int buzzer =2;
int R =8;
int Y =9;
int G =10;

NewPing cm(triger,echo,batas);

void setup() {
 
 Serial.begin(9600); 
 pinMode(buzzer,OUTPUT);
 pinMode (R,OUTPUT);
 pinMode (Y,OUTPUT);
 pinMode (G,OUTPUT);
}
void loop() {

 int bacaJarak=cm.ping_cm();

 Serial.print("Data jarak:");
 Serial.print(bacaJarak);
 Serial.print(" cm");
 Serial.println();
 delay(100);
 
 if (bacaJarak <=20 ){
  digitalWrite(buzzer,HIGH);
  digitalWrite(R,HIGH);
  digitalWrite(Y,LOW);
  digitalWrite(G,LOW);
  Serial.println("berhenti!");
  
  }
  else if(bacaJarak >= 21 and bacaJarak<=70){
    digitalWrite(buzzer,HIGH);
    digitalWrite(R,LOW);
    digitalWrite(Y,HIGH);
    digitalWrite(G,LOW);
    Serial.println("bahaya!"); 
      
  } else if(bacaJarak >=71){
    digitalWrite(buzzer,LOW);
    digitalWrite(R,LOW);
    digitalWrite(Y,LOW);
    digitalWrite(G,HIGH);
    Serial.println("aman");
  }
}
