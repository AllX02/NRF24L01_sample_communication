#include <SPI.h>
#include <RF24.h>

#define CE_PIN 7
#define CSN_PIN 8
#define LED_PIN 3

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_1MBPS);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&ledState, sizeof(ledState));
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);

    Serial.print("LED: ");
    Serial.println(ledState ? "ON" : "OFF");
  }
}