int Button1 = 2;
int Button2 = 3;
int R = 5;

void setup(){
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(R, OUTPUT);
}

void loop(){
  int readButton1 = digitalRead(Button1);
  Serial.println("Condition : " + String(readButton1));
  if(readButton1 == 1){
    digitalWrite(R, HIGH);
    digitalWrite(Y, HIGH);
  } else{
    digitalWrite(R, LOW);
    digitalWrite(Y, LOW);
  }
}
