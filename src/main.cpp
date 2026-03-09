#include <Arduino.h>

// ===== Clase SensorUltrasonico =====
class SensorUltrasonico {
  private:
    int pinTrig;
    int pinEcho;

  public:
    SensorUltrasonico(int trig, int echo) {
      pinTrig = trig;
      pinEcho = echo;
    }

    void begin() {
      pinMode(pinTrig, OUTPUT);
      pinMode(pinEcho, INPUT);
    }

    float medirDistancia() {
      float suma = 0;
      int lecturasValidas = 0;
      for(int i = 0; i < 5; i++) {

        digitalWrite(pinTrig, LOW);
        delayMicroseconds(5);
        digitalWrite(pinTrig, HIGH);
        delayMicroseconds(10);
        digitalWrite(pinTrig, LOW);
        long duracion = pulseIn(pinEcho, HIGH, 30000);
        if(duracion > 0) {
          float distancia = duracion * 0.0343 / 2;
          suma += distancia;
          lecturasValidas++;
        }
        delay(10);
      }
      if(lecturasValidas == 0) return -1;
      return suma / lecturasValidas;
    }
  };
// ===== Clase ControlLeds =====
class ControlLeds {
  private:
    int led1, led2, led3;

  public:
    ControlLeds(int l1, int l2, int l3) {
      led1 = l1;
      led2 = l2;
      led3 = l3;
    }

    void begin() {
      pinMode(led1, OUTPUT);
      pinMode(led2, OUTPUT);
      pinMode(led3, OUTPUT);
    }

    void apagarTodos() {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }

    void encenderNivel(int nivel) {
      apagarTodos();

      if (nivel >= 1) digitalWrite(led1, HIGH);
      if (nivel >= 2) digitalWrite(led2, HIGH);
      if (nivel >= 3) digitalWrite(led3, HIGH);
    }

    void parpadearTodos() {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(200);

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(200);
    }
};

// ===== Objetos =====
SensorUltrasonico sensor(3, 2);
ControlLeds leds(4, 5, 6);

// ===== Setup =====
void setup() {
  Serial.begin(9600);
  sensor.begin();
  leds.begin();
}
void loop() {
  float distancia = sensor.medirDistancia();
  Serial.println(distancia);

  if (distancia > 30) {
    leds.apagarTodos();
  }
  else if (distancia > 20) {
    leds.encenderNivel(1);
  }
  else if (distancia > 10) {
    leds.encenderNivel(2);
  }
  else if (distancia > 5) {
    leds.encenderNivel(3);
  }
  else {
    leds.parpadearTodos();
  }

  delay(200);
}
