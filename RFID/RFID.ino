  //Download dan masukan Library MFRC522
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String uidString;

int buzzer = 2;
int flag = 0;
int R=3;
int Y=4;
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
 pinMode(R,OUTPUT);
 pinMode(Y,OUTPUT);
 pinMode(IR,INPUT);
 pinMode(buzzer,OUTPUT);
 bunyibuzzeroke();
 Serial.println("TEMPELKAN KARTU!!!");
}

void loop() {
 // BACA DATA
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
 delay(1000);
 int ReadIR =digitalRead(IR); //sensor
 if ( mfrc522.PICC_IsNewCardPresent()&& flag==0) {
  readRFID();
 Serial.println(uidString);
 
 if(uidString=="A7-32-89-4B"){
  bunyibuzzeroke();
  flag =1;
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("SILAHKAN MASUK");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
 
 }else { 
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(4,0); lcd.print("GAGAL");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
  bunyibuzzergagal();

 }
}
if (ReadIR== 0 && flag ==1){
  lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("PALANG TERTUTUP");
 delay(1000); //Jeda waktu perulagan seama 1000 mili detik
 bunyibuzzergagal();
 delay(1000);
 flag=0;
  
}else{
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(0,0); lcd.print("TEMPELKAN KARTU");
 delay(1000);
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
 delay(150);
 digitalWrite(buzzer,LOW);
 delay(150);
 }
 

void bunyibuzzergagal(){
  digitalWrite(buzzer,HIGH);
  delay(150);
  digitalWrite(buzzer,LOW);
  delay(150);
}
