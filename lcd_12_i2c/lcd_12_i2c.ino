#include <LiquidCrystal_I2C.h>

//Inisialisasi pembuatan variable
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 //Menentukan Fungsionalitas dari PIN pada Microcontroller
 Serial.begin(9600); //baudrate yang digunakan untuk komunikasi microcontroller dengan komputer
 lcd.begin();
}
void loop() {
 //Program yang akan dijalankan berulang-ulang
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(4,0); lcd.print("WELCOME");
 lcd.setCursor(0,1); lcd.print("BINTANG ERLANGGA");
 delay(5000); //Jeda waktu perulagan seama 1000 mili detik
 
 lcd.clear(); //Untuk Menghapus karakter pada LCD
 lcd.setCursor(4,0); lcd.print("WELCOME");
 lcd.setCursor(0,1); lcd.print("to mobilelegend");
 delay(5000); //Jeda waktu perulagan seama 1000 mili detik
}
