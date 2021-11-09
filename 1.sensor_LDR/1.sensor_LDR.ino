//inisialisasi
int pinLED =3;
int pinLDR =A0;

void setup() {
  
  Serial.begin(9600);
  pinMode (pinLED,OUTPUT);
}


void loop() {
  int bacaLDR=analogRead(pinLDR);
      bacaLDR= map (bacaLDR, 0,1024,0,255);
  Serial.print ("NILAI LDR :");
  Serial.print (bacaLDR);
  Serial.println();

  if(bacaLDR){
    analogWrite(pinLED,bacaLDR);
    
  }
//else{
//    digitalWrite(pinLED,HIGH);
//    delay(200);
  }
  
 
