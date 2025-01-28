void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
  const string ID = "2471005";
}

void etatAllume(string ID) {
serial.print("Allume - ");
serial.print(ID);
digitalWrite(LED_BUILTIN, HIGH);
delay(2000);
digitalWrite(LED_BUILTIN, LOW);
}

void etatClignotement(string ID) {
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

void etatVariation(string ID) {
serial.print("Eteint - ");
serial.print(ID);
if (stoi(ID[-1]) % 2 == 0 ) {

} else {
  
}
}

void loop() {
  // put your main code here, to run repeatedly:
etatAllume(ID);
etatClignotement(ID);
etatVariation(ID);
}
