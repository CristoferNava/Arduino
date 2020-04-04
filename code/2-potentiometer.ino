// Revisar modulación por ancho de pulso
int LED = 3;
int BRIGHT;
int POT = 0; // Entrada 0 en ANALOG IN

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  /*
  for (BRIGHT = 0; BRIGHT <= 255; BRIGHT++) {
    analogWrite(LED, BRIGHT);
    delay(10);
  }

  for (BRIGHT = 255; BRIGHT >= 0; BRIGHT--) { // VALORES ENTRE 0 Y 255
    analogWrite(LED, BRIGHT);
    delay(10);
  }*/
  BRIGHT = analogRead(POT) / 4; /* Valores entre 0 y 1023*/
  analogWrite(LED, BRIGHT);
}
