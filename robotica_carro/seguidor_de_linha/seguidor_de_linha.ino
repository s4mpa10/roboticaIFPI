int pinDigital = 13; 
int led = 12;

void setup() {
  Serial.begin(9600); 
  pinMode(pinDigital, INPUT); 
  pinMode(led, OUTPUT);
}

void loop() {

  Serial.print("Leitura Digital: "); 
  Serial.println(digitalRead(pinDigital)); 

  if ((digitalRead(pinDigital)) == HIGH) { 
    Serial.println("Linha detectada");
    digitalWrite(led, HIGH);
    
  }
  else if ((digitalRead(pinDigital)) == LOW)  { 
    Serial.println("Linha não detectada");
    digitalWrite(led, LOW);
  }
  
  Serial.println("----------------------------------------------");
}
