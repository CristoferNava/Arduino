int TRIG =  10;
int ECHO = 9;
int LED = 3;
int TIME;
int DISTANCE;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600); // Para poder ver la información en la computadora, 9600 es la tasa de velocidad de comunicación, cantidad de bits/s que estaremos recibiendo
}

void loop() {
  digitalWrite(TRIG, HIGH); // Generamos una señal para el TRIG para que de esta manera éste mande un pulso.
  // La duración del pulso depende del fabricante
  delay(1); // En este caso hacemos esperamos un milisegundo que es la duración del pulso emitido
  digitalWrite(TRIG, LOW); // Terminamos de emitir el pulso
  TIME = pulseIn(ECHO, HIGH); // Tomamos el tiempo que tarda en responder, ECHO espera por un pulso alto. La función devuelve el tiempo
  DISTANCE = TIME / 58.2; // Distancia en centimetros. El valor de la constante es específicado por el fabricante.
  Serial.println(DISTANCE); // Imprimimos la distancia
  delay(200); // Dejamos 200 milisegundos entre una impresión y otra.

  // Implementación de la función a realizar
  if (DISTANCE >= 0 && DISTANCE <= 50) {
    digitalWrite(LED, HIGH);
    delay(DISTANCE * 10); // Hacemos que el LED prenda y apague dependiendo de la distancia del objecto, más cerca más rápido
    digitalWrite(LED, LOW);
  }
}
