#include <Ultrasonic.h>

// Movimentos básicos do carrinho
const int in1 = 2;
const int in2 = 4;
const int enA = 3; //Direita

const int in3 = 5;
const int in4 = 7;
const int enB = 6; //Esquerda

const int pinDigitalDir = 10;
const int pinDigitalEsq = 11;

const int ledVerde = 12;
const int ledVermelho = 13;

const int pinBuzzer = A1;

int velocidadeReta = 80;
int velocidadeCurva = 100;

Ultrasonic ultrasonic(8,9);

int distancia;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
 
  pinMode(pinDigitalDir, INPUT);
  pinMode(pinDigitalEsq, INPUT);

  pinMode(pinBuzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  distancia = ultrasonic.read();
  Serial.println(distancia);
  Serial.println("cm");

  int sensorDireita = digitalRead(pinDigitalDir);
  int sensorEsquerda = digitalRead(pinDigitalEsq);


  if (sensorDireita == LOW) && (sensorEsquerda == LOW){
    andarFrente();
    Serial.println(Carro andando para frente);
  }

  else if(sensorDireita == HIGH) && (sensorEsquerda == LOW){
    andarDireita();
    Serial.println(Virando a direita);
  }

  else if(sensorDireita == LOW) && (sensorEsquerda == HIGH){
    andarEsquerda();
    Serial.println(Virando a esquerda);
  }

  else if(sensorDireita == HIGH) && (sensorEsquerda == HIGH){
    frear();
    Serial.println(Carro parrou);
  }
}

void andarFrente() {
  digitalWrite(in1, LOW);  // para tras
  digitalWrite(in2, HIGH);   // frente
  analogWrite(enA, velocidadeReta);
  
  digitalWrite(in3, HIGH);   // frente
  digitalWrite(in4, LOW);  // para tras
  analogWrite(enB, velocidadeReta);
}

//void andarParaTras() {
//  digitalWrite(in1, HIGH);   // para tras
//  digitalWrite(in2, LOW);  // frente
//  digitalWrite(enA, velocidade);
//  
//  digitalWrite(in3, LOW);  // frente
//  digitalWrite(in4, HIGH);   // para tras
//  digitalWrite(enB, velocidade);
//}

void andarEsquerda() {
  digitalWrite(in1, HIGH);  // frente - Esquerda
  digitalWrite(in2, LOW);   // para trás
  analogWrite(enA, velocidadeCurva);
  
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, LOW);   // frente
  analogWrite(enB, 0);
}

void andarDireita() {
  digitalWrite(in1, LOW);   // frente
  digitalWrite(in2, LOW);   // para trás
  analogWrite(enA, 0);
  
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, HIGH);  // frente - Direita
  analogWrite(enB, velocidadeCurva);
}

void frear(){
  digitalWrite(in1, LOW);   // frente
  digitalWrite(in2, LOW);   // para trás
  analogWrite(enB, 0);
  
  digitalWrite(in3, LOW);   // para tras
  digitalWrite(in4, LOW);  //  frente
  analogWrite(enB, 0);
}
