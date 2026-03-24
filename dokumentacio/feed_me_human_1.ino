#include <Servo.h>
#include <LiquidCrystal.h>

const int redLed = 8;
const int yellowLed = 13;
const int greenLed = 9;
const int buttonPin = 2;
const int buzzer = 7;
const int potPin = A0;
const int servoPin = 6;

Servo myServo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 10);

int lastShownWaitTime = -1;
int lastButtonState = LOW;
int stableWaitTime = 3;

unsigned long lastPotReadTime = 0;
const unsigned long potReadInterval = 120;

void allLedsOff() {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
}

void beep(int freq, int duration) {
  tone(buzzer, freq, duration);
  delay(duration + 50);
}

void soonSound() {
  beep(800, 120);
  beep(1000, 120);
}

void eatSound() {
  beep(900, 120);
  beep(1200, 120);
  beep(1500, 180);
}

void endSound() {
  beep(1400, 120);
  beep(1100, 120);
  beep(800, 180);
}

void servoOpenSlow() {
  for (int pos = 0; pos <= 90; pos++) {
    myServo.write(pos);
    delay(10);
  }
}

void servoCloseSlow() {
  for (int pos = 90; pos >= 0; pos--) {
    myServo.write(pos);
    delay(10);
  }
}

bool buttonJustPressed() {
  int currentButtonState = digitalRead(buttonPin);

  if (lastButtonState == LOW && currentButtonState == HIGH) {
    delay(30);
    if (digitalRead(buttonPin) == HIGH) {
      lastButtonState = currentButtonState;
      return true;
    }
  }

  lastButtonState = currentButtonState;
  return false;
}

void showWaitingScreen(int waitTime) {
  lcd.setCursor(0, 0);
  lcd.print("VARAKOZAS      ");
  lcd.setCursor(0, 1);
  lcd.print("Ido: ");
  lcd.print(waitTime);
  lcd.print(" mp   ");
}

void updatePotValue() {
  if (millis() - lastPotReadTime >= potReadInterval) {
    lastPotReadTime = millis();

    int potValue = analogRead(potPin);
    int newWaitTime = map(potValue, 0, 1023, 3, 10);

    if (newWaitTime != stableWaitTime) {
      stableWaitTime = newWaitTime;
    }
  }
}

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzer, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  lcd.begin(16, 2);

  allLedsOff();
  digitalWrite(redLed, HIGH);
  showWaitingScreen(stableWaitTime);
  lastShownWaitTime = stableWaitTime;
}

void loop() {
  updatePotValue();

  allLedsOff();
  digitalWrite(redLed, HIGH);

  if (stableWaitTime != lastShownWaitTime) {
    showWaitingScreen(stableWaitTime);
    lastShownWaitTime = stableWaitTime;
  }

  if (buttonJustPressed()) {
    int runTime = stableWaitTime;

    allLedsOff();
    digitalWrite(yellowLed, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HAMAROSAN");
    lcd.setCursor(0, 1);
    lcd.print("Keszulj!      ");

    soonSound();
    delay(1500);

    allLedsOff();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("EHET");

    eatSound();
    servoOpenSlow();

    for (int sec = runTime; sec > 0; sec--) {
      digitalWrite(greenLed, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Hatra: ");
      lcd.print(sec);
      lcd.print(" mp   ");
      delay(500);

      digitalWrite(greenLed, LOW);
      delay(500);
    }

    servoCloseSlow();
    endSound();

    allLedsOff();
    digitalWrite(redLed, HIGH);

    lastShownWaitTime = -1;
    showWaitingScreen(stableWaitTime);
    delay(200);
  }
}