//inisialisasi
int pinBuzzer =3;
int pinFlame =A1;
int R=4;
int Y=5;
int G=6;
void setup() {
  
  Serial.begin(9600);
  pinMode (pinBuzzer,OUTPUT);
  pinMode (pinFlame,INPUT);
  pinMode (R,OUTPUT);
  pinMode (Y,OUTPUT);
  pinMode (G,OUTPUT); 
}


void loop() {
  int bacaFlame=analogRead(pinFlame);
 bacaFlame= map (bacaFlame,1017,35,0,100);
  Serial.print ("NILAI Flame :");
  Serial.print (bacaFlame);
  Serial.println();
  
if(bacaFlame <=20){
  digitalWrite(pinBuzzer,
}
  
}



 
