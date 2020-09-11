/* 
    Author : Newton Kelvin
    Gas Detection and Alert system
 */

#include "SIM900.h"
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// Create an LCD object. Parameters: (RS, E, D4, D5, D6, D7):
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

int sensor = 7;
int gas_value;
int buzz;


void setup() {
  / Specify the LCD's number of columns and rows. 
  lcd.begin(16, 2);
  pinMode(sensor, INPUT);
  pinMode(buzz, OUTPUT);


}

void loop() {
  gas_detect();  
}

void gas_detect() {
  gas_value = digitalRead(sensor);
  alert();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WARNING");
  lcd.setCursor(1, 0);
  lcd.print("GAS LEAKS!!");
  Send_Sms();
  delay(3600000);
 }

void Send_Sms(){

  //Start configuration of shield with baudrate.
  //For http uses is raccomanded to use 4800 or slower.
    if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  if(started){
    //Enable this two lines if you want to send an SMS.
    if (sms.SendSMS("+254797*******", "GAS LEAKS AT HOME")){
      Serial.println("\nSMS sent OK");
  }
   if (sms.SendSMS("+25470********", "GAS LEAKS AT HOME")){
      Serial.println("\nSMS sent OK");
  }
  }
  delay(1000);
}

void alert() {
  for (int i = 0; i <8; i++){
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    delay(500);
    }
}
