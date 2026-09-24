#include <SPI.h>
#include <RF24.h>

#define CE_PIN 4
#define CSN_PIN 5

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  Serial.println("Envoyer 1, 2 ou 3 pour allumer LED1, LED2 ou LED3 et un chiffre superieur pour les eteindres");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
  
    if (c>= '0' || c>='3') {
      byte text = c- '0';
      radio.write(&text, sizeof(text));
      Serial.print("Envoi: ");
      Serial.println(text);
    }
  

  }
}