#include <Arduino.h>

// ===== Clase SensorUltrasonico =====
class SensorUltrasonico {

private:
  int trig;
  int echo;

  float medirSimple() {

    digitalWrite(trig, LOW);
    delayMicroseconds(3);

    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long duracion = pulseIn(echo, HIGH, 30000);

    if (duracion == 0) return -1;

    float distancia = (duracion * 0.0343) / 2;
    return distancia;
  }

  void ordenar(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          float temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }

public:

  SensorUltrasonico(int t, int e) {
    trig = t;
    echo = e;
  }

  void begin() {
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
  }

  float medirDistancia() {

    const int muestras = 7;
    float valores[muestras];
    int validas = 0;

    for (int i = 0; i < muestras; i++) {

      float d = medirSimple();

      if (d > 0 && d < 400) {
        valores[validas++] = d;
      }

      delay(15);
    }

    if (validas == 0) return -1;

    ordenar(valores, validas);

    return valores[validas / 2]; // mediana
  }
};



// ===== Clase ControlLeds =====
class ControlLeds {

private:
  int l1, l2, l3;

public:

  ControlLeds(int a, int b, int c) {
    l1 = a;
    l2 = b;
    l3 = c;
  }

  void begin() {
    pinMode(l1, OUTPUT);
    pinMode(l2, OUTPUT);
    pinMode(l3, OUTPUT);
  }

  void apagar() {
    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
  }

  void nivel(int n) {

    apagar();

    if (n >= 1) digitalWrite(l1, HIGH);
    if (n >= 2) digitalWrite(l2, HIGH);
    if (n >= 3) digitalWrite(l3, HIGH);
  }

  void parpadeo() {

    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);

    delay(150);

    digitalWrite(l1, LOW);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);

    delay(150);
  }
};



// ===== Objetos =====
SensorUltrasonico sensor(15, 2);
ControlLeds leds(5, 18, 19);



// ===== Setup =====
void setup() {

  Serial.begin(115200);

  sensor.begin();
  leds.begin();
}



// ===== Loop =====
void loop() {

  float distancia = sensor.medirDistancia();

  Serial.print("Distancia: ");
  Serial.println(distancia);

  if (distancia == -1) return;

  if (distancia > 30) {
    leds.apagar();
  }
  else if (distancia > 20) {
    leds.nivel(1);
  }
  else if (distancia > 10) {
    leds.nivel(2);
  }
  else if (distancia > 5) {
    leds.nivel(3);
  }
  else if (distancia > 3) {
    leds.parpadeo();
  }

  delay(120);
}

