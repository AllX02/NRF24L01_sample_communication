#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>

RF24 radio(4, 5);

const byte address[6]= "00001";
const char text[6]= "ALLIX";

void setup() {
  Serial.begin(115200);
  radio.begin();
  printf_begin();

  radio.openWritingPipe(address); 
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  radio.printDetails();
}

void loop() {

  radio.write(&text, sizeof(text));
  Serial.println("Transmission...");
  Serial.print("Sending:");
  Serial.print(text);
}
