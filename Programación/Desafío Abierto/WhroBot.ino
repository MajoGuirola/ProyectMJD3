#include <Servo.h>

// Configuración de pines de los sensores de distancia
#define trigPin 7
#define echoPinDerch 8
#define echoPinAtras 9
#define echoPinIzq 10
#define echoPinAde 11

// Configuración de pines de los botones de inicio
#define buttonPin A2

// Configuración de los pines de los motores (cc y servo)
#define motorPin1 2
#define motorPin2 4
#define servoPin 3

// Nombre del servomotor
Servo direccion;

// Contar los giros y las vueltas que lleva el carro para después detenerlo
int vueltas = 0;
long giros = 0;
int sentidodegiro = 0;
String nombredelsentidodegiro;

// Variables para los sensores de dirección
long durationAde = 0;
long durationAtras = 0;
long durationIzq = 0;
long durationDerch = 0;

long distanceAde = 0;
long distanceAtras = 0;
long distanceIzq = 0;
long distanceDerch = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPinDerch, INPUT);
  pinMode(echoPinAtras, INPUT);
  pinMode(echoPinIzq, INPUT);
  pinMode(echoPinAde, INPUT);

  pinMode(buttonPin, INPUT);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  direccion.attach(servoPin);
  direcciondegiro();
}

void loop() {
  leerdistancia();
  if (digitalRead(buttonPin) == HIGH) {
    direccion.write(95);
    digitalWrite(motorPin1, HIGH);
    if (sentidodegiro == 1) {
      if (distanceIzq <= 80) {
        digitalWrite(motorPin1, LOW);
        delay(500);
        girar();
        giros++;
      }
    }
    if (sentidodegiro == 2) {
      if (distanceDerch <= 80) {
        delay(500);
        girar();
        giros++;
      }
    }
    vueltas = giros / 4;
    if (vueltas >= 4) {
      digitalWrite(motorPin1, LOW);
      digitalWrite(motorPin2, LOW);
      exit(0);
    }
  }
}

void leerdistancia() {
  // Enviar señal a todos los sensores
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer la respuesta de todos los sensores
  durationAde = pulseIn(echoPinAde, HIGH);
  durationAtras = pulseIn(echoPinAtras, HIGH);
  durationIzq = pulseIn(echoPinIzq, HIGH);
  durationDerch = pulseIn(echoPinDerch, HIGH);

  // Conversión a centímetros
  distanceAde = durationAde * 0.034 / 2;
  distanceAtras = durationAtras * 0.034 / 2;
  distanceIzq = durationIzq * 0.034 / 2;
  distanceDerch = durationDerch * 0.034 / 2;

  // Mostrar valores en el monitor serial
  Serial.print("Adelante: ");
  Serial.print(distanceAde);
  Serial.print(" cm");
  Serial.print("  Izquierda: ");
  Serial.print(distanceIzq);
  Serial.print(" cm");
  Serial.print("  Derecha: ");
  Serial.print(distanceDerch);
  Serial.print(" cm");
  Serial.print("  Atrás: ");
  Serial.print(distanceAtras);
  Serial.print(" cm");
  Serial.println();

  delay(1000);  // Espera 1 segundo antes de la siguiente lectura
}

void direcciondegiro() {
  leerdistancia();
  // 1 = sentido de giro hacia la izquierda, sentido antihorario
  // 2 = sentido de giro hacia la derecha, sentido horario
  if (distanceIzq > distanceDerch) {
    sentidodegiro = 1;
    nombredelsentidodegiro = "antihorario";
  } else {
    sentidodegiro = 2;
    nombredelsentidodegiro = "horario";
  }

  Serial.println("Sentido de giro: " + nombredelsentidodegiro);
}

void girar() {
  if (sentidodegiro == 1) {
    direccion.write(0);
    delay(500);
    digitalWrite(motorPin1, HIGH);  // El pin del motor con el que gire hacia adelante
  } else if (sentidodegiro == 2) {
    direccion.write(180);
    delay(500);
    digitalWrite(motorPin1, HIGH);  // El pin del motor con el que gire hacia adelante
  }
  if (distanceAde > 30) {
    direccion.write(90);
    delay(500);
    digitalWrite(motorPin1, HIGH);
  }
}
