int LED   =2;
int LDR   =A0;
int Flame =A1;
int Buzzer=5;
int Pir   =3;

void setup() {
  pinMode (LED,OUTPUT);
  pinMode (Buzzer,OUTPUT);
  pinMode (LDR,INPUT);
  pinMode (Flame,INPUT);
  pinMode (Pir,INPUT);
}

void loop() {
  // LDR
   int bacaLDR     =analogRead(LDR);
       bacaLDR     =map (bacaLDR, 0,1024,0,255);  
  Serial.print ("NILAI LDR :");
  Serial.print (bacaLDR);
  // Flame  
   int bacaFlame   =analogRead(Flame);
       bacaFlame   =map (bacaFlame,1017,35,0,100);
   Serial.print ("NILAI Flame :");
   Serial.print (bacaFlame);
   // Pir
   int bacaPir     =digitalRead(Pir);
     Serial.print (bacaPir);
     Serial.print (bacaPir);
     
if (bacaPir ==1){
  digitalWrite(LED,bacaPir);
 // digitalWrite(LED,HIGH);
  //delay(100);
}//else{ 
 // digitalWrite(Buzzer,LOW);
  //digitalWrite(LED,LOW);
  //delay(100);
  
  
}
