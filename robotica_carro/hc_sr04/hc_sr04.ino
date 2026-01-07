#include <Ultrasonic.h>

// Movimentos básicos do carrinho
int in1 = 2;
int in2 = 4;
int enA = 3;

int in3 = 5;
int in4 = 7;
int enB = 6;

int pinDigitalSL1 = 10;
int pinDigitalSL2 = 11;

int ledVerde = 12;
int ledVermelho = 13;

int velocidade = 100;

Ultrasonic ultrasonic(8,9);

<<<<<<< HEAD
int distancia;
=======
// int pinTrigger = 8; //Gatilho do pulso do sensor 
// int pinEcho = 9; // ler a saída do sensor

int distancia = 0;
>>>>>>> fef768ee1bf55883d3c4cdb2b5149d01f9fd6ce8

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  pinMode(pinDigitalSL1, INPUT);
  pinMode(pinDigitalSL2, INPUT);

  Serial.begin(9600);
}

void loop() {
  distancia = ultrasonic.read();
  Serial.println(distancia);
  Serial.println("cm");

  if (distancia < 10){
    frear();
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledVerde, LOW);
    andarDireita();
  }
  else{
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledVerde, HIGH);
    andarFrente();
  }

  delay(100);
}

void andarFrente() {
  digitalWrite(in1, LOW);  // para tras
  digitalWrite(in2, HIGH);   // frente
  digitalWrite(in3, HIGH);   // frente
  digitalWrite(in4, LOW);  // para tras
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
}

void andarParaTras() {
  digitalWrite(in1, HIGH);   // para tras
  digitalWrite(in2, LOW);  // frente
  digitalWrite(in3, LOW);  // frente
  digitalWrite(in4, HIGH);   // para tras
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
}

void andarEsquerda() {
  digitalWrite(in1, HIGH);  // frente - Esquerda
  digitalWrite(in2, LOW);   // para trás
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, LOW);   // frente
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
}

void andarDireita() {
  digitalWrite(in1, LOW);   // frente
  digitalWrite(in2, HIGH);   // para trás
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, HIGH);  // frente - Direita
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
}

void frear(){
  digitalWrite(in1, LOW);   // frente
  digitalWrite(in2, LOW);   // para trás
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, LOW);  //  frente
}
