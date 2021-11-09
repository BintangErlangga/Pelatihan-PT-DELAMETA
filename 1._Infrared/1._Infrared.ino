const int Button1 = 4; 
const int IR = 3;
const int R = 5;
const int Y = 6;
const int G = 7;
int flag = 0;

void setup(){
  Serial.begin(9600);
  pinMode(IR, INPUT);
  pinMode(Button1, INPUT);
  pinMode(R, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(G, OUTPUT);
  digitalWrite(R, HIGH);
  Serial.println("System Start");
}

void loop(){
  int readButton1 = digitalRead(Button1);
  int readIR = digitalRead(IR);
  if(readButton1 == 1 && flag == 0){
    flag = 1;
    Serial.println("Gate Opened, Please Take Your Ticket!");
    digitalWrite(R, LOW);
    digitalWrite(Y, HIGH);
    delay(500);
    digitalWrite(Y, LOW);
    delay(500);
    digitalWrite(G, HIGH);
    }
  if(readIR == 0 && flag == 1){
    flag = 0;
    Serial.println("Gate Closed!");
    digitalWrite(G, LOW);
    digitalWrite(R, HIGH);
  }
}
