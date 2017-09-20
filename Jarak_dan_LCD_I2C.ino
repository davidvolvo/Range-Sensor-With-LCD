#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("jarak maks");
  }
  
  else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PENGUKURAN");
    lcd.setCursor(0,1);
    lcd.print("JARAK :");
    lcd.print(distance);
    lcd.print(" CM");
    
  }
  delay(500);
}

