const int Button1 = 2;
const int R = 4;
int holdButton1 = 0;

void setup(){
  Serial.begin(9600);
  pinMode(Button1, INPUT);
  pinMode(R, OUTPUT);
  digitalWrite(R, LOW);
}

void loop(){
  int readButton1 = digitalRead(Button1);
  if(readButton1 == 1){
    if(holdButton1 == 0){
      holdButton1 = 1;
      digitalWrite(R, HIGH);
    }
    else {
      holdButton1 = 0;
      digitalWrite(R, LOW);
    }
    delay(1000);
  }
}
