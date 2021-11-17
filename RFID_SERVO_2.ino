#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

Servo myservo;
String uidString;

#define SS_PIN PB1
#define RST_PIN PB0

MFRC522 mfrc522(SS_PIN, RST_PIN);

int IR =PB5;
int R  =PB4;
int G  =PB3;
int flag=0;
int servo=PA15;

void setup(){
  Serial.begin(9600);
//  pinMode(Buzzer, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(IR, INPUT);
  SPI.begin();
  mfrc522.PCD_Init();
  myservo.attach(servo);
  digitalWrite(R, HIGH);
  welcome();
}

void loop(){
  int readIR = digitalRead(IR);
  if(mfrc522.PICC_IsNewCardPresent() && flag == 0){
    readRFID();
    if(uidString == "4-42-45"){
      flag = 1;
      succeed();
        myservo.write(0); //0-180
        delay(1000);
      Serial.println("Gate Opened!");
    } else{
      flag = 0;
      Serial.println("Fail!");
      fail();
    }
  } 
  if(readIR == 0 && flag == 1){
    Serial.print("Please go!");
    flag = 0;
      myservo.write(90); //0-180
      delay(1000);
    digitalWrite(R, HIGH);
    digitalWrite(G, LOW);
    welcome();
  }
}

void readRFID(){
  mfrc522.PICC_ReadCardSerial();
  Serial.println("Tag UID : " + String(uidString));
  uidString = String(mfrc522.uid.uidByte[0]) + "-" +
  String(mfrc522.uid.uidByte[1], HEX) + "-" +
  String(mfrc522.uid.uidByte[2]), HEX + "-" +
  String(mfrc522.uid.uidByte[3]), HEX;
  uidString.toUpperCase();
}

void welcome(){
  Serial.println("SELAMAT DATANG");
}

void succeed(){
  Serial.println("SILAKAN MASUK");
//  digitalWrite(Buzzer, HIGH);
//  delay(50);
//  digitalWrite(Buzzer, LOW);
//  delay(50);
//  digitalWrite(Buzzer, HIGH);
//  delay(50);
//  digitalWrite(Buzzer, LOW);
  digitalWrite(R, LOW);
  digitalWrite(G, HIGH);
}

void fail(){
  Serial.println("KARTU TIDAK TERDAFTAR");
  digitalWrite(R, HIGH);
  digitalWrite(G, LOW);
//  digitalWrite(Buzzer, HIGH);
//  delay(1000);
//  digitalWrite(Buzzer, LOW);
  welcome();
}
