#include <Servo.h>
#include <BH1750.h>
#include <Wire.h>
#include <DHT11.h>
#include <LiquidCrystal_I2C.h>

// Create two Servo objects
Servo servoBase;   // Connected to D9 - rotates the platform
Servo servoTilt;   // Connected to D10 - tilts the panel
BH1750 lightMeter; //communicates over the I2C bus
DHT11 dht11(8); //Connected to D8, acquires Humidity and Temperature Values
LiquidCrystal_I2C lcd(0x27, 16, 2);


const int photoResist0 = A0;
const int photoResist90 = A1;
const int photoResist180 = A2;

// Timing variables
unsigned long previousMillis = 0;
const long interval = 1000; 

void setup() {
  // Attach the servos to pins
  servoBase.attach(9);
  servoTilt.attach(10);

  // Optional: Initialize Serial for debugging
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
  servoBase.write(0);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Starting...");
  printFlashScreen();
}

void printFlashScreen(){
  lcd.clear();
  lcd.setCursor(0,0); //first column, first row
  lcd.print("By:Mrve,Xhoi,Vic");
  lcd.setCursor(0,1); //first column, second row
  lcd.print("Drba,Cdrt,Arj");
  delay(3000);
}

int returnTurnAngle(int l0, int l1, int l2){
  int maxLight = l0;
  int turnAngle = 0;
  if (l1>maxLight){
    maxLight = l1;
    turnAngle = 90;
  }
  if (l2>maxLight){
    maxLight = l2;
    turnAngle = 180;
  }
  return turnAngle;
}

void loop() {
  unsigned long currentMillis = millis(); //for non-blocking delays
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    float lux = lightMeter.readLightLevel();
    int hum = dht11.readHumidity();
    int temp = dht11.readTemperature();

    int light0 = analogRead(photoResist0);
    int light90 = analogRead(photoResist90);
    int light180 = analogRead(photoResist180);

    if (isnan(temp)||isnan(hum)){
      lcd.clear();
      lcd.print("DHT Err");
      delay(1000);
      return;
    }
    lcd.clear();

    // Display temperature and humidity on the first row
    lcd.setCursor(0, 0);  // Set cursor to first row
    lcd.print("T: ");
    lcd.print(temp);    // Print temperature
    lcd.print(" C  H: ");
    lcd.print(hum);       // Print humidity
    lcd.print(" %");

    // Display light intensity on the second row
    lcd.setCursor(0, 1);  // Set cursor to second row
    lcd.print("Light: ");
    lcd.print(lux);  // Print light intensity value
    lcd.print(" lux");

    //the following is for serial communication with the downstream Team
    Serial.print("T: ");
    Serial.print(temp);
    Serial.print(" C H: ");
    Serial.print(hum);
    Serial.print("% ");
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.print(" lux");
    Serial.println("");
    int turnAngle = returnTurnAngle(light0,light90,light180);
    servoBase.write(turnAngle);

  }
}
