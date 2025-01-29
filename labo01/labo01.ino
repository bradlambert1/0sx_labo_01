const string ID = "2471005";

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void etatAllume() {
serial.print("Allume - ");
serial.print(ID);
digitalWrite(LED_BUILTIN, HIGH);
delay(2000);
digitalWrite(LED_BUILTIN, LOW);
}

void etatClignotement() {
serial.print("Clignotement - ");
serial.print(ID);
int loops = stoi(ID[-2]);
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
serial.print("Variation - ");
serial.print(ID);
float brightness = 0;
if (stoi(ID[-1]) % 2 == 0 ) {
  brightness = 0;
  for (int i = 0; i<128; i++) {
      brightness += 0.78125
    delay(16);
  }
} else {
  brightness = 100;
  for (int i = 0; i<128; i++) {
      brightness -= 0.78125
    delay(16);
  }

  brightness = 100;
}

void etatEteint() {
  serial.print("Eteint - ");
  serial.print(ID);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, high);

}
void loop() {
  // put your main code here, to run repeatedly:
etatAllume();
etatClignotement();
etatVariation();
etatEteint();
}
