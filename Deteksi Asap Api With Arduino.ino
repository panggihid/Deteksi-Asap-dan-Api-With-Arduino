
#include <Wire.h>
#include <MQ2.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// inialisasi masing2 pin

//sensor mq2
int pinMq2 = A0;
int NilaiApi;
//sensor flame
int pinFlame = 13;
//Buzzer
int pinBuzzer = 12;
//nilai treshold
int sensorThres = 35;
//variabel data
int data;
int dataAsap;
int kipas = 7;


void setup() {
  Serial.begin(9600);
  // inialisasi status pin mq2
  pinMode(pinMq2, INPUT);
  //inialisasi status pin flame
  pinMode(pinFlame, INPUT);
  //inialisasi status pin buzzer
  pinMode(pinBuzzer, OUTPUT);
  //kipas
  pinMode(kipas, OUTPUT);
  
   lcd.init();
   lcd.backlight();
   lcd.setCursor(0,0);
   lcd.print("DETEKSI ASAP");
   lcd.setCursor(0,1);
   lcd.print("DAN API");
   delay(2000);
   lcd.clear();
  
}

void loop() {
{
  //MQ2 SENSOR
  int analogSensor = analogRead(pinMq2);
  lcd.setCursor(0,0);
  lcd.print("Asap :");
  Serial.println(analogSensor);
  if
  (analogSensor >=sensorThres)
  {
    digitalWrite(pinBuzzer, HIGH);
    lcd.setCursor(6,0);
    lcd.print("Bahaya");
    delay(500);
    lcd.clear();
    digitalWrite(kipas, HIGH);
  }
else
{
    digitalWrite(pinBuzzer, LOW);
    lcd.setCursor(6,0);
    lcd.print("Aman");
    delay(500);
    digitalWrite(kipas, LOW);
  }


// FLAME SENSOR
{
  NilaiApi = digitalRead(pinFlame);
  lcd.setCursor(0,1);
  lcd.print("Api :");
  
  if(NilaiApi == LOW){
    digitalWrite(pinBuzzer, HIGH);
    lcd.setCursor(6,1);
    lcd.print("Bahaya");
    delay(500);
    lcd.clear();
  }
else
{
    digitalWrite(pinBuzzer, LOW);
    lcd.setCursor(6,1);
    lcd.print("Aman");
    delay(500);
}
}
}
}
