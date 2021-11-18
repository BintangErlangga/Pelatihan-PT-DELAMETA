  //Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);
String uidString;

int servo =5;
Servo myservo;

int buzzer = 2;
int flag = 0;
int G=3;
int R=4;
int IR=6;

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 



void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(115200); 
 lcd.begin();
 SPI.begin(); 
 mfrc522.PCD_Init(); 
 myservo.attach(servo);
 pinMode(G,OUTPUT);
 pinMode(R,OUTPUT);
 pinMode(IR,INPUT);
 pinMode(buzzer,OUTPUT);
 bunyibuzzeroke();
 Serial.println("TEMPELKAN KARTU!!!");
 
}

void loop() {
 // BACA DATA
 

 int ReadIR =digitalRead(IR); //sensor
 if ( mfrc522.PICC_IsNewCardPresent()&& flag==0) {
  readRFID();
 Serial.println(uidString);

 // berhasil
 if(uidString=="A-A8-90-15"){
  if (Serial.available() > 0)
  bunyibuzzeroke();
  terbuka();
 lcd.clear(); //
 lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK");
 delay(500);
 flag =1;
 
 }else {
 lcd.clear(); //
 lcd.setCursor(4,0); lcd.print("GAGAL");
 delay(500); //
 bunyibuzzergagal();
 flag=0;

 }
}
if (ReadIR== 0 && flag ==1){
  lcd.clear();
 lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
 delay(100); 
 bunyibuzzergagal();
 tertutup();
 delay(500);
 flag=0;
 lcd.clear(); //
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
 delay(500);
  
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
 
void bunyibuzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
}
void terbuka(){
  myservo.write(0);
  delay(100);
}
void tertutup(){
  myservo.write(90);
  delay (100);
  
}
