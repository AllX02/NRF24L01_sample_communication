#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5
#define BUTTON_PIN 17

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

bool ledState = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_1MBPS);
  radio.stopListening();
}

void loop() {
  ledState = (digitalRead(BUTTON_PIN) == LOW);

  bool ok = radio.write(&ledState, sizeof(ledState));

  Serial.print("Etat envoye: ");
  Serial.print(ledState ? "ON" : "OFF");
  Serial.print(" | Envoi: ");
  Serial.println(ok ? "OK" : "ECHEC");

  delay(100);
}