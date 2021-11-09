//inisialisasi
int pinPir =2;
int pinBuzzer =5;
int R=4;
void setup() {
  
  Serial.begin(9600);
  pinMode (pinPir,INPUT);
  pinMode (pinBuzzer,OUTPUT);
  pinMode(R,OUTPUT);
}


void loop() {
  int bacaPir=digitalRead(pinPir);
  Serial.print ("NILAI PIR :");
  Serial.print (bacaPir);
  Serial.println();
  
if (bacaPir ==1){
  digitalWrite(pinBuzzer,HIGH);
  delay(100);
  digitalWrite(R,HIGH);
  delay(100);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
  digitalWrite(R,LOW);
  delay(100);
  Serial.println("ADA MALING!!!");
}else{
  (bacaPir ==0);
  digitalWrite(pinBuzzer,LOW);
  delay(100);
}
  
}
