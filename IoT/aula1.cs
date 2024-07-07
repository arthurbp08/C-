// Define os pinos dos LEDs
const int ledPinos[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
const int numLEDs = 12;

void setup() {
// Configura os pinos dos LEDs como saída
for (int i = 0; i < numLEDs; i++) {
 pinMode(ledPinos[i], OUTPUT);
}
}

void loop() {
// Faz os LEDs acenderem um por um
delay(200);
for (int i = 0; i < numLEDs; i++) {
	digitalWrite(ledPinos[i], HIGH); // Liga o LED
	delay(100); // Espera um pouco
	digitalWrite(ledPinos[i], LOW); // Desliga o LED
}
}

//void setup() {
// pinMode(13, OUTPUT);
// pinMode(12, OUTPUT);
// pinMode(11, OUTPUT);
// pinMode(10, OUTPUT);
// pinMode(9, OUTPUT);
//}

//void loop() {
// digitalWrite(13, HIGH);
// delay(200);
// digitalWrite(12, HIGH);
// delay(200);
// digitalWrite(11, HIGH);
// delay(200);
// digitalWrite(10, HIGH);
// delay(200);
// digitalWrite(9, HIGH);
// delay(200);

// digitalWrite(13, LOW);
// delay(200);
// digitalWrite(12, LOW);
// delay(200);
// digitalWrite(11, LOW);
// delay(200);
// digitalWrite(10, LOW);
// delay(200);
// digitalWrite(9, LOW);
//}
