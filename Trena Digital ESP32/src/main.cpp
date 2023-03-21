#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

const int trigPin = 4;
const int echoPin = 5;
const int buttonPin = 18;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  SerialBT.begin("ESP32_BT"); // Inicia o módulo Bluetooth com o nome ESP32_BT
}

void loop() {
  if (digitalRead(buttonPin) == 1) { // Verifica se o botão foi pressionado
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    float distance = duration * 0.034 / 2;
    SerialBT.println(distance); // Envia a distância medida via Bluetooth
    Serial.println(distance); // Envia a distância medida via Serial
    delay(1000);
  }
}
