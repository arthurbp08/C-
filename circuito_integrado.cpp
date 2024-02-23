#include <DHT.h>

#define DHTPIN 2        // Pino digital onde o sensor DHT está conectado
#define DHTTYPE DHT22   // Tipo do sensor DHT, pode ser DHT11, DHT21 ou DHT22
#define echo 4           // Pino digital do sensor de distância (echo)
#define trig 5           // Pino digital do sensor de distância (trig)

DHT dht(DHTPIN, DHTTYPE);
unsigned long tempo;
double distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
  dht.begin();
  digitalWrite(trig, LOW);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  tempo = pulseIn(echo, HIGH);
  distancia = tempo / 58;
  Serial.print("Distancia em centimetros: ");
  Serial.println(distancia);

  // Lê a temperatura em graus Celsius
  float tempC = dht.readTemperature();

  // Verifica se a leitura foi bem-sucedida
  if (isnan(tempC)) {
    Serial.println("Erro ao ler o sensor DHT!");
  } else {
    // Converte a temperatura para Fahrenheit e Kelvin e exibe os valores
    float tempF = (tempC * 9.0 / 5.0) + 32.0;
    float tempK = tempC + 273.15;

    Serial.print("Temperatura em Celsius: ");
    Serial.print(tempC);
    Serial.print(" °C\t");

    Serial.print("Temperatura em Fahrenheit: ");
    Serial.print(tempF);
    Serial.print(" °F\t");

    Serial.print("Temperatura em Kelvin: ");
    Serial.print(tempK);
    Serial.println(" K");
  }

  delay(2000);
}
