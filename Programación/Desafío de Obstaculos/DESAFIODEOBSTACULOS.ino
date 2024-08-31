//inclusión de las librerias a utilizar
#include <SPI.h>
#include <Pixy2.h>
#include <Servo.h>

//nombre de la pixy
Pixy2 pixy;
//nombre del serovmotor
Servo direccion;

////////////////////////////////////////////////////////

// Pines del motor DC y del servomotor
int motorPin = 4;
int servoPin = 3;
//Configuracion de pines de los botones de inicio
#define buttonPin 5
//configuracion de los pines del sensor de distancia
#define trigPin2 7
#define trigPin3 6
#define echoPin2 9
#define echoPin3 8
////////////////////////////////////////////////////////

//variables para el uso de la cámara
int cont = 0;
int signature, x, y, width, height;
float area;

//variables para el botón de incio
int pulsadorPin = 5; // Variable que guarda el número del pin al que conectamos el pulsador.
int valorPulsador = 0; // Variable donde almacenaremos la lectura del estado del pulsador.
int k = 0;

//variables para contabilizar las vueltas y giros
int giro;
int vuelta;

//variables para los bucles if
int c;
int l;

//variable para almacenar la signature
int j;
//variables para almacenar los angulos del servomotor
int m;
int n;

//variables para la lectura del servomotor
long distanceIzq = 0;
long distanceDerch = 0;
long durationIzq = 0;
long durationDerch = 0;
long duration, distance;

void setup() {
  //inicializando el monitor y la cámara
  Serial.begin(9600);
  Serial.print("Starting...\n");
  pixy.init();

  //declarando pines
  pinMode(motorPin, OUTPUT);
  direccion.attach(servoPin);
  pinMode(trigPin3, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(echoPin2, INPUT);

  pinMode(pulsadorPin, INPUT_PULLUP); // Declaramos la variable inputPin como entrada y activamos su resistencia interna Pullup.
}

void loop() {
  //lectura del pulsador
  valorPulsador = digitalRead(pulsadorPin);
  if (valorPulsador == HIGH) {
    k = k;
  }
  else {
      k = 1;
  }
  //si el pulsador fue activado entonces ejecutar el código
  if(k == 1){
    vuelta = giro/4;
  //obtenemos valores de la función
  pixyCheck();
  leerdistancia();
  //si el objeto esta cerca entonces...
  if(vuelta>3){
  if(y>= 30){
    //si es el rectángulo verde entonces..
    if(signature==1){
      Serial.println("VERDE CERCA");
      j= 1;
    }
    //si es el rectángulo rojo entonces..
    if(signature==2){
      Serial.println("ROJO CERCA");
      j= 2;
    }
  }

  //si el sensor derecho marca espacio entonces girar a la derecha 
  if(distanceDerch>110){
    //espera un tiempo para no hacer un giro demasiado cerrado
    avanzar();
    delay(600);
    //luego realiza el giro de 90 grados
    direccion.write(50);
    avanzar();
    delay(3500);
    //suma la vuetla
    giro = giro + 1;
    //restablece los valores
    distanceDerch= 0;
    Serial.println("Derecha");
  }
  //si el espacio esta hacia la izquierda entonces girar hacia la izquierda
  if (distanceIzq>110) {
    avanzar();
    delay(600);
    direccion.write(140);
    avanzar();
    delay(3500);
    giro = giro + 1;
    distanceIzq= 0;
    Serial.println("izquierda");
  }
  else if(j == 1){
    Serial.println("signature 1");
    //si el rectángulo esta totalmente a su derecha entonces solo avanzara
    if(x>=280){
      Serial.println("recto rojo");
      avanzar();
    }
    //si no debera esquivarlo
    else{
      //esquiva el obstaculo en la dirección que deberia
     if(c == 0){
      direccion.write(140);
      n = 50;
      avanzar();
      delay(1800);
      c = 1;
      l=0;
     }
     if(l == 0){
      //avanza un poco para no impactar con el obstáculo
      adelante();
      delay(100);
      //regresa a la posición inicial
      direccion.write(m);
      avanzar();
      delay(1800);
      l=1;
      c=0;
     }
     }
     //restablece las variables
    j = 0;
  }
  else if(j == 2){
    Serial.println("Signature 2");
    //si el rectangulo ya se encuentra totalmente esquivado por defecto entonces solo avanzara
    if(x>=280){
      avanzar();
      Serial.println("Recto verde");
    }
    //si no esta esquivado entonces debera esquivarlo
    else{
    if(c == 0){
      //esquiva el obstáculo en la dirección que debe
     direccion.write(50);
     m = 140;
     avanzar();
     delay(1800);
     c = 1;
     l= 0;  
    }
    if(l == 0){
      //avanza un poco para no impactar con el obstáculo
      adelante();
      delay(100);
      //se reposiciona a la posición icinial
      direccion.write(m);
      avanzar();
      delay(1600);
      l=1;
      c=0;
    }
    }
    //restablecer la lectura para no tener una lectura falsa
    j=0;
  }
  //si no sucede nada de los casos anteriores eso significa de deberia seguir recto
  else{
    Serial.println("sigue recto hasta nueva indicación");
    adelante();
  }
  /*
  Serial.println(j);
  Serial.println(c);
  Serial.println(y);*/
  }
  //si se completan todas las vuetlas, entonces termina de posicionarse y se detiene
  else if(vuelta == 3 ){
    delay(1000);
    stop();
    delay(15000);
  }
  }
}

//leer los valores provenientes de la pixy
float pixyCheck() {
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  // grab blocks!
  blocks = pixy.ccc.getBlocks();

  //Si se encuentran bloques, almacenarlos en variables sus valores e imprimirlas
  if (blocks) {
    signature = pixy.ccc.blocks[0].m_signature;
    height = pixy.ccc.blocks[0].m_height;
    width = pixy.ccc.blocks[0].m_width;
    x = pixy.ccc.blocks[0].m_x;
    y = pixy.ccc.blocks[0].m_y;
    Serial.print(" y:");
    Serial.print(y);
    Serial.print(" x:");
    Serial.println(x);
  }
  //si no, todo sera igual a 0
  else {
    signature= 0;
    x= 0;
    y= 0;
    area = 0;
  }
}
//lectura de sensores de distancia
void leerdistancia(){
  // Sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin2, HIGH);
  distance = duration * 0.034 / 2;

  distanceDerch = distance;
  
  Serial.print("Sensor 2: ");
  Serial.print(distanceDerch);
  Serial.print(" cm");

  Serial.print("   ");
  
  duration = 0;
  distance = 0;

  // Sensor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration = pulseIn(echoPin3, HIGH);
  distance = duration * 0.034 / 2;
  distanceIzq = distance;
  
  Serial.print("Sensor 3: ");
  Serial.print(distanceIzq);
  Serial.print(" cm"); 

  Serial.println("   ");
  
  duration = 0;
  distance = 0;
}

//rectificar las llantas y avanzar
void adelante(){
  direccion.write(105); // Posición del servo para avanzar
  digitalWrite(motorPin,HIGH);
}

//solamente avanzar con la posicion de llantas anteriormente establecida en el código
void avanzar(){
  digitalWrite(motorPin,HIGH);
}

//detenerse totalmente
void stop(){
  digitalWrite(motorPin,LOW);
}