// Movimentos básicos do carrinho
int in1 = 2;
int in2 = 4;
int enA = 3;

int in3 = 5;
int in4 = 7;
int enB = 6;

int velocidade = 100;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void loop() {
  andarFrete();
  andarParaTras();
  andarEsquerda();
  andarDireita();
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
