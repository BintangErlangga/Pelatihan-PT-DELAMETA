#include <NewPing.h>


// inisialisasi
  
  int Flame =PB11;
  int R   =PB10;
  int Y   =PB1;
  int G   =PB0;
  int echo=PA7;
  int triger=PA5;
  int flag=0;
  int limit=400;

NewPing cm(triger,echo,limit);

void setup() {
 //Fungsi

   Serial.begin(9600);
   pinMode(R,OUTPUT);
   pinMode(Y,OUTPUT);
   pinMode(G,OUTPUT);
   pinMode(Flame,INPUT);
   

}

void loop() {
  // baca data

    int bacaFlame   = digitalRead(Flame);
    int bacaJarak = cm.ping_cm(); 

    bacaFlame = map(bacaFlame,1,0,0,1);
  // Serial print
      Serial.print("Flame   :   "   + String (bacaFlame));
      Serial.print("|jarak :   "  +  String (bacaJarak));
      Serial.println();
      delay(100);
      
//  //Logika
//
//    if(bacaFlame == 1 && flag ==0){
//      flag=1;
//      delay(500);
//    }else if (bacaFlame == 1 && flag ==1){
//      flag=0;
//      delay(500);
//    }
//    if (flag == 1){
//       if (bacaJarak >30 ){
//        digitalWrite(R,1);
//        delay(100);
//        digitalWrite(R,0);
//        digitalWrite(Y,1);
//        delay(100);
//        digitalWrite(Y,0);
//        digitalWrite(G,1);
//        delay(100);
//        digitalWrite(G,0);
//        digitalWrite(Y,1);
//        delay(100);
//        digitalWrite(Y,0);
//        
//    }else if (bacaJarak >20 && bacaJarak <30){
//       digitalWrite(R,1);
//       digitalWrite(Y,1);
//       digitalWrite(G,1);
//       delay(500);
//       digitalWrite(R,0);
//       digitalWrite(Y,0);
//       digitalWrite(G,0);
//    }else if (bacaJarak <20){
//       digitalWrite(R,1);
//       digitalWrite(Y,1);
//       digitalWrite(G,1);
//       delay(100);
//       digitalWrite(R,0);
//       digitalWrite(Y,0);
//       digitalWrite(G,0);
//    }
//}if (flag==0){
//      digitalWrite(R,0);
//      digitalWrite(Y,0);
//      digitalWrite(G,0);
//}
    }
