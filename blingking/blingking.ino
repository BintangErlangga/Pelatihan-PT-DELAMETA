// inisialisasi
int R=PA0;
int Y=PA1;
int G=PA2;
int tombol1= PA3;
int tombol2= PA4;
int tombol3= PA5;
int kunci = 0;

void setup() {
  //FUNGSI
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);

}

void loop() {
  //baca data 
 int bacatombol1 = digitalRead(tombol1);
 int bacatombol2 = digitalRead(tombol2);
 int bacatombol3 = digitalRead(tombol3);
 
 // print serial 
 
 Serial.println("Condition : " + String(bacatombol1));
 Serial.println("Condition : " + String(bacatombol2));
 Serial.println("Condition : " + String(bacatombol3));

 // logika
 // tombol1
 if (bacatombol1 == 1 && kunci ==0){
  kunci =1;
  digitalWrite(R,HIGH);
  delay(500);
 }else if(bacatombol1==1 && kunci ==1){
  kunci =0;
  digitalWrite(R,LOW);
  delay(500);
 }

 //tombol2
 
  if (bacatombol2 == 1 && kunci ==0){
  kunci =1;
  digitalWrite(Y,HIGH);
  delay(500);
 }else if (bacatombol2==1 && kunci ==1){
  kunci =0;
  digitalWrite(Y,LOW);
  delay(500);
  
 }
 
// //tombol3
  if (bacatombol3 == 1 && kunci ==0){
  kunci=1;
  digitalWrite(G,HIGH);
  delay(500);
 }else if (bacatombol3 ==1 && kunci==1){
  kunci =0;
  digitalWrite(G,LOW);
  delay(500);
 }
 
}
