#define echo 10
#define trig 9

float tempo, distancia;

void setup()
{
  for(int i=2; i<10; i++) {
  	pinMode(i, OUTPUT);
  }
  pinMode(10, INPUT);
}

void loop()
{
  // Sensor medindo distância
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  tempo = pulseIn(echo,HIGH);
  distancia = tempo/58.2;
  
  
  if (distancia <= 50) {
    tone(8, 500);
  
    for(int i=2; i<8; i++) {
      digitalWrite(i, HIGH);
    }
  }
  else if (distancia > 50 && distancia <= 70) {
  	tone(8, 500);
    for(int i=2; i<8; i++) {
      digitalWrite(i, LOW);
    }
    for(int i=2; i<6; i++) {
      digitalWrite(i, HIGH);
    }
    delay(100);
    noTone(8);
    delay(100);
  }
  else if (distancia > 70 && distancia <= 100) {
  	tone(8, 500);
    for(int i=2; i<8; i++) {
      digitalWrite(i, LOW);
    }
    for(int i=2; i<4; i++) {
      digitalWrite(i, HIGH);
    }
    delay(200);
    noTone(8);
    delay(200);
  }
  else {
  	for(int i=2; i<8; i++) {
      digitalWrite(i, LOW);
    }
    noTone(8);  }
}
