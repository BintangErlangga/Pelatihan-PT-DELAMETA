  //Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#define A1 5 // Motor A pins
#define A2 6
#define B1 10 // Motor B pins
#define B2 11
int incomingByte = 0; // for incoming serial data
int input = 0;

LiquidCrystal_I2C lcd(0x27, 16, 2);
String uidString;

int buzzer = 2;
int flag = 0;
int G=3;
int R=4;
int IR=7;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 



void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); 
 lcd.begin();
 SPI.begin(); 
 mfrc522.PCD_Init(); 
 pinMode(A1, OUTPUT);
 pinMode(A2, OUTPUT);
 digitalWrite(A1, LOW);
 digitalWrite(A2, LOW);
 pinMode(G,OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(IR,INPUT);
 pinMode(buzzer,OUTPUT);
 bunyibuzzeroke();
 Serial.println("TEMPELKAN KARTU!!!");
 
}

void loop() {
 // BACA DATA
 
 lcd.clear(); //
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
 delay(500);
 int ReadIR =digitalRead(IR); //sensor
 if ( mfrc522.PICC_IsNewCardPresent()&& flag==0) {
  readRFID();
 Serial.println(uidString);

 // berhasil
 if(uidString=="A7-32-89-4B"){
  if (Serial.available() > 0)
 
  bunyibuzzeroke();
  flag =1;
 lcd.clear(); //
 lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK");
 delay(500);
 digitalWrite(G,HIGH);
 delay(1000); //
 digitalWrite(R,LOW);
 delay(1000);
 analogWrite(A1,255);
 delay(100);
 digitalWrite(A1,LOW);
 
 }else { 
 lcd.clear(); //
 lcd.setCursor(4,0); lcd.print("GAGAL");
 delay(500); //
  bunyibuzzergagal();

 }
}
if (ReadIR== 0 && flag ==1){
  lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
 digitalWrite(R,HIGH);
 delay(1000);
 digitalWrite(G,LOW);
 delay(1000);
 analogWrite(A2, 210);
 delay(100);
 digitalWrite(A2, LOW);
 bunyibuzzergagal();
 delay(500);
 flag=0;
  
}else {
 delay(500);
}
}


void readRFID()
{
  mfrc522.PICC_ReadCardSerial();
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
 }
 
void bunyibuzzeroke(){
 digitalWrite(buzzer,HIGH);
 delay(1000);
 digitalWrite(buzzer,LOW);
 delay(1000);
}
 void forward() { //function of forward 
 analogWrite(A1, 255);
 analogWrite(A2, 0);
 delay(1000);
 digitalWrite(A1,LOW);
 }
 

void bunyibuzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}
void backward() { //function of backward
 analogWrite(A1, 0);
 analogWrite(A2, 210);
 delay(1000);
 digitalWrite(A2, LOW);
}
