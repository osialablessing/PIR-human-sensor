#include <LiquidCrystal.h>
int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd (rs, en, d4, d5, d6, d7);
int buzzer = 8;
int pir = 9;
int led = 10;
int pirState;

void setup () {
lcd.begin(16,2);
pinMode(pir, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
}void loop () {
pirState = digitalRead(pir);
if (pirState==HIGH) {
 for (int x=0; x<5; x++) {
 digitalWrite (led, HIGH);
 digitalWrite (buzzer, HIGH);
 delay (1000);
 lcd.clear(); // Clear the display
lcd.setCursor(0,1);
 lcd.print("INTRUDER DETECTED");
 digitalWrite (led, LOW);
 digitalWrite (buzzer, LOW);
 delay (1000);
} }
else {
 digitalWrite (led, LOW);
 digitalWrite (buzzer, LOW);
 delay(500);
 lcd.clear();
  lcd.print("NO INTRUDER");
} }