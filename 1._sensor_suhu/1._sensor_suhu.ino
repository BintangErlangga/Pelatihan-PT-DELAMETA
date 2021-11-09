#include <OneWire.h>
#include <DallasTemperature.h>


int sensorsuhu =2;
OneWire oneWire(sensorsuhu);
DallasTemperature sensors(&oneWire);
int buzzer =5;
int R =8;
int G =9;
int Y =10;

void setup() {
  //Menentukan Fungsionalitas dari PIN pada Microcontroller
  Serial.begin(9600);
  sensors.begin();
  pinMode(buzzer,OUTPUT);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(Y,OUTPUT);
}

void loop() {
  //baca Sensor
  
  sensors.requestTemperatures();
  float bacaSuhu = sensors.getTempCByIndex(0);

  // print serial
  Serial.print ("suhu :");
  Serial.print(bacaSuhu);
  Serial.print("c");
  Serial.println();// enter 

  
  //logika
  if (bacaSuhu >=31){
  digitalWrite(buzzer,HIGH);
  digitalWrite(R,HIGH);
  digitalWrite(G,LOW);
}
else
{
  Serial.println("bacaSuhu!");
  digitalWrite(buzzer,LOW);
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
}
}
