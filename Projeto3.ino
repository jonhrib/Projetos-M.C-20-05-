// const int LED_PIN = 23; // Define o pino do LED

// void setup() {
//   pinMode(LED_PIN, OUTPUT); // Configura o pino do LED como saída
//   // Não é necessário configurar T0 (GPIO4) como entrada, a função touchRead já cuida disso
// }

// void loop() {
//   if (touchRead(4) < 20) { // Lê o valor do pino touch T0 (GPIO4)
//     digitalWrite(LED_PIN, HIGH); // Liga o LED se o valor lido for menor que 20
//   } else {
//     digitalWrite(LED_PIN, LOW); // Desliga o LED caso contrário
//   }
//   delay(100); // Aguarda 100 milissegundos antes de repetir o loop
// }

int LED_BUILTIN = 23; // Define o pino do LED

void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Configura o pino do LED como saída
  pinMode(T0, INPUT);
  // Não é necessário configurar T0 (GPIO4) como entrada
}

void loop() {
  if (touchRead(T0) < 20) { // Lê o valor do pino touch T0 (GPIO4)
    digitalWrite(LED_BUILTIN, HIGH); // Liga o LED se o valor lido for menor que 20
  } else {
    digitalWrite(LED_BUILTIN, LOW); // Desliga o LED caso contrário
  }
  delay(100); // Aguarda 100 milissegundos antes de repetir o loop
}

