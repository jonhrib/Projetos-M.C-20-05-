#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  SerialBT.begin("ESP32 LED"); // Inicializa o Bluetooth com o nome "ESP32 LED"
  pinMode(2, OUTPUT); // Configura o pino 2 como saída
}

void loop() {
  if (SerialBT.available()) { // Verifica se há dados disponíveis para leitura no Bluetooth
    char c = SerialBT.read(); // Lê o caractere recebido
    if (c == '1') {
      digitalWrite(2, HIGH); // Liga o LED se o caractere recebido for '1'
      SerialBT.println("LED on"); // Envia a mensagem "LED on" via Bluetooth
    }
    if (c == '0') {
      digitalWrite(2, LOW); // Desliga o LED se o caractere recebido for '0'
      SerialBT.println("LED off"); // Envia a mensagem "LED off" via Bluetooth
    }
  }
  delay(20); // Pequeno atraso para evitar leitura excessiva
}
