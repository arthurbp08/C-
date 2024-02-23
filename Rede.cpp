#include <DHT.h>
#include <WiFi.h>
#include <ThingSpeak.h>

// Defina o tipo de sensor DHT e o pino ao qual está conectado
#define DHTPIN 4
#define DHTTYPE DHT22

// Defina suas credenciais Wi-Fi
const char *ssid = "PAUL_WIFI";
const char *password = "ca32611873";

// Defina sua chave de API ThingSpeak
const char *thingSpeakApiKey = "G3ZWSPIQUWDPPOYL";

// Defina o ID do seu canal ThingSpeak
const unsigned long YOUR_CHANNEL_ID = 2251834; // Substitua pelo seu ID de canal

// Inicialize o sensor DHT
DHT dht(DHTPIN, DHTTYPE);

// Inicialize a conexão Wi-Fi
WiFiClient client;

void setup() {
  Serial.begin(115200);
  
  // Inicialize o sensor DHT
  dht.begin();

  // Inicialize a conexão Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conexão WiFi estabelecida");

  // Inicialize o ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Leia a temperatura e umidade do sensor DHT
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Verifique se a leitura foi bem-sucedida
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Falha na leitura do sensor DHT!");
    delay(2000);
    return;
  }

  // Enviar os dados de temperatura e umidade para o ThingSpeak
  ThingSpeak.writeField(YOUR_CHANNEL_ID, 1, temperature, thingSpeakApiKey);
  ThingSpeak.writeField(YOUR_CHANNEL_ID, 2, humidity, thingSpeakApiKey);

  Serial.println("Dados de temperatura e umidade enviados para o ThingSpeak!");

  // Aguarde um intervalo antes de enviar novamente (geralmente 15 minutos para evitar limitações do ThingSpeak)
  delay(900000); // 15 minutos em milissegundos
}

