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
 welcome();
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
  sukses();
  flag =1;
 lcd.clear(); 
 lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK");
 delay(1000); 
 myservo.write(180); 
 delay(500); 
 
 }
 else if(uidString=="EA-6-D5-80" and flag==0){
  sukses();
  flag =1;
 lcd.clear();
 lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK");
 delay(1000); 
 myservo.write(180); 
 delay(500); 
 
 }else { 
 lcd.clear(); 
 lcd.setCursor(4,0); lcd.print("GAGAL");
 delay(1000);
  gagal();

 }
}
if (ReadIR== 0 && flag ==1){
   myservo.write(90);
 delay(500);  
  lcd.clear();
 lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
 delay(500); 
 welcome();
 delay(500);
 flag=0;
 lcd.clear();
 lcd.setCursor(0,0);
}
//}else {
// lcd.clear(); 
// lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
// delay(500);
//}
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
 
void sukses(){
 digitalWrite(buzzer,HIGH);
 delay(500);
 digitalWrite(buzzer,LOW);
 delay(500);
 digitalWrite(G,1);
 digitalWrite(R,0);
 }
 

void gagal(){
  digitalWrite(buzzer,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(50);
  digitalWrite(G,0);
  digitalWrite(R,1);
}
void welcome(){
 digitalWrite(R,1);
 digitalWrite(G,0);
}
