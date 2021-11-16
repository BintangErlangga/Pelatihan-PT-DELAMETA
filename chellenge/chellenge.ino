// insialisi
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
  int R  = PA7;
  int Y  = PA6;
  int G  = PA5;
  int IR = PB0;
  int LDR = PB1;
  int flag =0;
  
void setup() {
// fungsi
     Serial.begin(9600);
     lcd.begin();
     pinMode(IR,INPUT);
     pinMode(LDR,INPUT);
     pinMode(R,OUTPUT);
     pinMode(Y,OUTPUT);
     pinMode(G,OUTPUT);
  
}

void loop() {
//baca data
    int bacaIR = digitalRead(IR);
    int bacaLDR= analogRead(LDR);
    bacaLDR= map(bacaLDR,0,4095,255,0);
    bacaIR = map(bacaIR,1,0,0,1);
    
    // serial print
    
    Serial.print("kondisi IR : " + String(bacaIR));
    Serial.print("kondisi LDR: " + String(bacaLDR));
    Serial.println();
    
// logika 
   if (bacaIR ==1 && flag ==0){
       flag =1;
       delay(500);
   }else if(bacaIR ==1 && flag ==1){
       flag=0;
       delay(500);
   }

   if (flag==1){
      if(bacaLDR <100){
        digitalWrite(R,HIGH);
        digitalWrite(Y,LOW);
        digitalWrite(G,LOW);
         lcd.clear(); 
         lcd.setCursor(4,0); lcd.print("MERAH");
      } else if(bacaLDR >100 && bacaLDR <200){
        digitalWrite(R,LOW);
        digitalWrite(Y,HIGH);
        digitalWrite(G,LOW);
         lcd.clear(); 
         lcd.setCursor(4,0); lcd.print("KUNING");
      }else if(bacaLDR >200 && bacaLDR <250){
        digitalWrite(R,LOW);
        digitalWrite(Y,LOW);
        digitalWrite(G,HIGH);
         lcd.clear(); 
         lcd.setCursor(4,0); lcd.print("HIJAU");
      }
   }else if (flag==0){
      digitalWrite(R,LOW);
      digitalWrite(Y,LOW);
      digitalWrite(G,LOW);
   }
  }
