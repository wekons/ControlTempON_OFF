#include <LiquidCrystal.h>
#define verde A5
#define naranja A4
#define rojo A3
#define motor A2
#define u1 27
#define u2 45
#define u3 50
LiquidCrystal lcd (7,6,5,4,3,2);
float sensorValue = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(verde,OUTPUT);
  pinMode(naranja,OUTPUT);
  pinMode(rojo,OUTPUT); 
  pinMode(motor,OUTPUT); 

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(" Temperatura es ");
  lcd.setCursor(0,1);
  for (int i = 0; i<5; i++)
  {
    sensorValue =  sensorValue + (analogRead(A0)*500.0)/1024;
  }
  sensorValue=(sensorValue/6);
  
  lcd.print("  ");
  lcd.print(sensorValue);
  lcd.print(" Celcius ");
  Serial.println(sensorValue);
  if(sensorValue<=u1)
  {
    digitalWrite(verde,HIGH); 
    digitalWrite(naranja,LOW); 
    digitalWrite(rojo,LOW); 
    digitalWrite(motor,HIGH); 
    
  }else if (sensorValue <= u2)
  {
    digitalWrite(verde,HIGH); 
    digitalWrite(naranja,HIGH); 
    digitalWrite(rojo,LOW);
    digitalWrite(motor,HIGH);  
  }else if (sensorValue <= u3)
  {
    digitalWrite(verde,HIGH); 
    digitalWrite(naranja,HIGH); 
    digitalWrite(rojo,HIGH);
    digitalWrite(motor,LOW);      
  }
    
  delay(1000); 
}
