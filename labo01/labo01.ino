const String ID = "2471005";
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // open the serial port at 9600 bps:


}
void print(String text) {
Serial.print(text);
Serial.print(" - ");
Serial.print(ID);
Serial.print("\n");
}
void etatAllume() {
print("Allume");
digitalWrite(LED_BUILTIN, HIGH);
delay(2000);
digitalWrite(LED_BUILTIN, LOW);
}
void etatClignotement() {
print("Clignotement");
int loops = 0;
if (loops == 0) {
  loops = 10;
}
for (int i = 0; i<loops; i++) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}
}

void etatVariation() {
print("Variation");
float brightness = 0;
int lastDaNumber = 5;
int steps = 256;
int rampTime = 2048;
float delayTime = rampTime/steps;
if (lastDaNumber % 2 == 0) {
  brightness = 0;
  for (int i = 0; i<steps; i++) {
      brightness += 1;
      analogWrite(LED_BUILTIN, brightness);
      delay(delayTime);
  }
} else {
  brightness = 255;
  for (int i = 0; i<steps; i++) {
      brightness -= 1;
      analogWrite(LED_BUILTIN, brightness);
      delay(delayTime);
  }
  }
}

void etatEteint() {
  print("Eteint");
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, HIGH);

}
void loop() {
  // put your main code here, to run repeatedly:
etatAllume();
etatClignotement();
etatVariation();
etatEteint();
}
