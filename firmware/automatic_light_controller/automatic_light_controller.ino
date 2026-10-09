#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 6);

const int lightPin = A0;
const int ledPin = 9;

// Adjust after testing your sensor
const int darkReading = 100;
const int brightReading = 900;

float filteredLight = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  filteredLight = analogRead(lightPin);

  lcd.print("Light Controller");
  delay(1000);
  lcd.clear();
}

void loop() {
  int rawLight = analogRead(lightPin);

  // Smooth out small fluctuations
  filteredLight =
    0.85 * filteredLight + 0.15 * rawLight;

  int brightness = map(
    (int)filteredLight,
    darkReading,
    brightReading,
    255,
    0
  );

  brightness = constrain(brightness, 0, 255);

  analogWrite(ledPin, brightness);

  int lightPercent = map(
    (int)filteredLight,
    darkReading,
    brightReading,
    0,
    100
  );

  lightPercent = constrain(lightPercent, 0, 100);

  lcd.setCursor(0, 0);
  lcd.print("Light: ");
  lcd.print(lightPercent);
  lcd.print("%    ");

  lcd.setCursor(0, 1);
  lcd.print("LED PWM: ");
  lcd.print(brightness);
  lcd.print("    ");

  Serial.print("ADC: ");
  Serial.print(rawLight);
  Serial.print(" PWM: ");
  Serial.println(brightness);

  delay(100);
}
