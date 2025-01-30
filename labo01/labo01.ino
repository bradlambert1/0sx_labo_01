const String ID = "2471005";

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void etatAllume() {
Serial.print("Allume - ");
Serial.print(ID);
digitalWrite(LED_BUILTIN, HIGH);
delay(2000);
digitalWrite(LED_BUILTIN, LOW);
}

void etatClignotement() {
Serial.print("Clignotement - ");
Serial.print(ID);
char loops = ID[-2];
int loopsN = 0;
if (loops == '0') {
  loopsN = 10;
}
for (int i = 0; i<loopsN; i++) {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}
}

void etatVariation() {
Serial.print("Variation - ");
Serial.print(ID);
float brightness = 0;
if (ID[-1] == '2' || ID[-1] == '4' || ID[-1] == '6' || ID[-1] == '8' || ID[-1] == '0') {
  brightness = 0;
  for (int i = 0; i<128; i++) {
      brightness += 0.78125;
    delay(16);
  }
} else {
  brightness = 100;
  for (int i = 0; i<128; i++) {
      brightness -= 0.78125;
    delay(16);
  }

  brightness = 100;
  }
}

void etatEteint() {
  Serial.print("Eteint - ");
  Serial.print(ID);
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
