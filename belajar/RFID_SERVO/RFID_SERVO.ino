#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>


int outServo=5; //Pin untuk Servo
Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);
String uidString;

int buzzer = 2;
int flag = 0;
int R=3;
int G=4;
int IR=7;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 



void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600);
 myservo.attach(outServo);  
 lcd.begin();
 SPI.begin(); 
 mfrc522.PCD_Init(); 
 pinMode(R,OUTPUT);
 pinMode(G,OUTPUT);
 pinMode(IR,INPUT);
 pinMode(buzzer,OUTPUT);
 berhasil();
 Serial.println("TEMPELKAN KARTU!!!");
}

void loop() {
 // BACA DATA
 lcd.clear(); 
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
 delay(500);
 int ReadIR =digitalRead(IR); 
 if ( mfrc522.PICC_IsNewCardPresent()&& flag==0) {
  readRFID();
 Serial.println(uidString);
 
 if(uidString=="A7-32-89-4B"){
  berhasil();
  flag =1;
 lcd.clear(); 
 lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK");
 delay(500); 
 myservo.write(90); 
 delay(500); 
 myservo.write(0); 
 delay(500); 
 
 
 }
 if(uidString=="EA-6-D5-80"){
  berhasil();
  flag =1;
 lcd.clear();
 lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK");
 delay(500); 
 myservo.write(90); 
 delay(500); 
 myservo.write(0);
 delay(500); 
 
 }else { 
 lcd.clear(); 
 lcd.setCursor(4,0); lcd.print("GAGAL");
 delay(500);
  gagal();

 }
}
if (ReadIR== 0 && flag ==1){
   myservo.write(0);
 delay(500); 
 myservo.write(90);
 delay(500); 
  lcd.clear();
 lcd.setCursor(0,0); 
 delay(500); 
 berhasil();
 delay(500);
 flag=0;
  
}else {
 lcd.clear(); 
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
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
 
void berhasil(){
 digitalWrite(buzzer,HIGH);
 delay(500);
 digitalWrite(buzzer,LOW);
 delay(500);
 }
 

void gagal(){
  digitalWrite(buzzer,HIGH);
  delay(150);
  digitalWrite(buzzer,LOW);
  delay(150);
}
