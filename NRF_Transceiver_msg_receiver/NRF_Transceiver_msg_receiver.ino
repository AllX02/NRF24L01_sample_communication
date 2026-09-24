#include <SPI.h>
#include <RF24.h>

#define CE_PIN 7
#define CSN_PIN 8

#define LED1_PIN 3
#define LED2_PIN 4
#define LED3_PIN 5

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001"; 
byte message;
void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  Serial.begin(9600);

  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void loop() {
  if (radio.available()) { 
    
  
    radio.read(&message, sizeof(message));


    if (message == 1) {
      digitalWrite(LED1_PIN, HIGH);
      Serial.println("LED1 ON");

    } else if (message == 2) {
      digitalWrite(LED2_PIN, HIGH);
      Serial.println("LED2 ON");

    } else if (message == 3) {
      digitalWrite(LED3_PIN, HIGH);
      Serial.println("LED3 ON");
      
    } else {
      Serial.print("Message inconnu: ");
      Serial.println(message);
    }
  }
}