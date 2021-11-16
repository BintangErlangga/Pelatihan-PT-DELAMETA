int R =PB11;
int Y =PB10;
int G =PA5;
int tombol1 =PA4;
int tombol2 =PA12;
int tombol3 =PA15;

void setup() {
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
}

void loop() {
  int bacatombol1 = digitalRead(tombol1);
  int bacatombol2 = digitalRead(tombol2);
  int bacatombol3 = digitalRead(tombol3);
  Serial.println("Condition : " + String(bacatombol1));
  Serial.println("Condition : " + String(bacatombol2));
  Serial.println("Condition : " + String(bacatombol3));
  
  if(bacatombol1 == 1){
    digitalWrite(R, HIGH);
  } else{
    digitalWrite(R, LOW);
  }
    if(bacatombol2 == 1){
    digitalWrite(Y, HIGH);
  } else{
    digitalWrite(Y, LOW);
  }
    if(bacatombol3 == 1){
    digitalWrite(G, HIGH);
  } else {
    digitalWrite(G, LOW);
    
  }
}
