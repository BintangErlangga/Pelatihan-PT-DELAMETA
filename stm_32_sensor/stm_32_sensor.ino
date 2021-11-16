// insialisasi

int IR  = PA7;
int LDR = PB1;
int R   = PB0;
int Y   = PA3;
int G   = PA4;
int prev = 0;
int flag= 0;

void setup() {
// fungsi
Serial.begin(9600);
pinMode(IR,INPUT);
pinMode(LDR,INPUT);
pinMode(R,OUTPUT);
pinMode(Y,OUTPUT);
pinMode(G,OUTPUT);

}

void loop() {
  // baca data

 int bacaIR = digitalRead(IR);
 int bacaLDR= analogRead(LDR);

 bacaIR  = map(bacaIR,1,0,0,1);
 bacaLDR = map(bacaLDR,0,4095,0,255);

  //PrintSerial
 Serial.print("kondisi IR :" + String(bacaIR));
 Serial.print("kondisi LDR :" + String(bacaLDR)); 
 Serial.println();
//
// //logika
//    if (bacaIR == 1 && flag ==0){
//      flag=1;
//     digitalWrite(R,1);
//   }else if (bacaIR ==0 && flag == 1){
//      flag=0;
//     digitalWrite(R,0);
//   }
   
// // LDR 
//  if(bacaLDR <100 ){
//    analogWrite(R,0);
//  }else if(bacaLDR <200){
//    analogWrite(R,100);
//    
//  }else if(bacaLDR <=255){
//    analogWrite(R,255);
//  }

//  //IR
//  digitalWrite(R,bacaIR);

//  if (prev ==0 && bacaIR == 1) {
//    flag = ! flag;
//  }
//  prev = bacaIR;
//
//  if (flag == 1) {
//    analogWrite(R, bacaLDR );
//  } else {
//    analogWrite(R, LOW);
//  }

}
  
