#include <Ultrasonic.h>

// Movimentos básicos do carrinho
int in1 = 2;
int in2 = 4;
int enA = 3;

int in3 = 5;
int in4 = 7;
int enB = 6;

int velocidade = 100;

Ultrasonic ultrasonic(8,9);

// int pinTrigger = 8; //Gatilho do pulso do sensor 
// int pinEcho = 9; // ler a saída do sensor

int distancia;

// float tempoEcho = 0;

// const float velocidadeSom_mpors = 340; // em metros por segundos 
// const float velocidadeSom_mporus = 0.000340; // em metros por microsegundos

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // pinMode(pinTrigger, OUTPUT);
  // digitalWrite(pinTrigger, LOW);
  // pinMode(pinEcho, INPUT);

  Serial.begin(9600);
}

void loop() {
  // dispararPulso();
  // tempoEcho = pulseIn(pinEcho, HIGH);
  // Serial.println("Distância em metros:");
  // Serial.println(calculoDistancia(tempoEcho));
  // Serial.println("Distância em centimetros:");
  // Serial.println(calculoDistancia(tempoEcho) * 100);
  distancia = ultrasonic.read();
  Serial.println(distancia);
  Serial.println("cm");

  if (distancia < 10){
    frear();
    andarDireita();
  }
  else{
    andarFrente();
  }

  delay(100);
}

void andarFrente() {
  digitalWrite(in1, HIGH);  // frente
  digitalWrite(in2, LOW);   // para trás
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, HIGH);  // frente
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
  delay(500);
}

void andarParaTras() {
  digitalWrite(in1, LOW);   // frente
  digitalWrite(in2, HIGH);  // para trás
  digitalWrite(in3, HIGH);  // para tras
  digitalWrite(in4, LOW);   // frente
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
  delay(500);
}

void andarEsquerda() {
  digitalWrite(in1, HIGH);  // frente - Esquerda
  digitalWrite(in2, LOW);   // para trás
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, LOW);   // frente
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
  delay(500);
}

void andarDireita() {
  digitalWrite(in1, LOW);   // frente
  digitalWrite(in2, LOW);   // para trás
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, HIGH);  // frente - Direita
  digitalWrite(enA, velocidade);
  digitalWrite(enB, velocidade);
  delay(500);
}

void frear(){
  digitalWrite(in1, LOW);   // frente
  digitalWrite(in2, LOW);   // para trás
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, LOW);  //  frente
  delay(1500);
}

// void dispararPulso(){
//   digitalWrite(pinTrigger, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(pinTrigger, LOW);
// }

// float calculoDistancia(float tempo_us){
//   return((tempo_us * velocidadeSom_mporus) / 2);
// }