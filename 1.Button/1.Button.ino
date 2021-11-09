int Button1 = 2;
int Button2 = 3;
int Button3 = 4;
int R = 5;
int Y = 6;
int G = 7;

void setup(){
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);  
}

void loop(){
  int readButton1 = digitalRead(Button1);
  int readButton2 = digitalRead(Button2);
  int readButton3 = digitalRead(Button3);
  Serial.println("Condition : " + String(readButton1));
  Serial.println("Condition : " + String(readButton2));
  Serial.println("Condition : " + String(readButton3));
  if(readButton1 == 1){
    digitalWrite(R, HIGH);
  } else if(readButton1 == 0) {
    digitalWrite(R, LOW);
  } else if(readButton2 == 1){
    digitalWrite(Y, HIGH);
  } else if(readButton2 == 0){
    digitalWrite(Y, LOW);
  } else if(readButton3 == 1){
    digitalWrite(G, HIGH);
  } else{
    digitalWrite(G, LOW);
  }
}
