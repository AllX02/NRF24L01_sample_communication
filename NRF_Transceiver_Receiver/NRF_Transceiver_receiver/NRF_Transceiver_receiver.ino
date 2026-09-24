#include <RF24.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>

byte LED1= 3;
byte LED2= 4;
byte LED3= 5;
int timer= 200;

RF24 radio(7, 8);

const byte address[6] = "00001";
byte text;

void setup() {
  Serial.begin(115200);
  radio.begin();
  printf_begin();

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  radio.printDetails();
}

void loop() {
  if (radio.available()) {
    radio.read(&text, sizeof(text));

    if(text==1){

      digitalWrite(LED1, HIGH);
      Serial.println("LED1 ON");
    }
    else if(text==2){

      digitalWrite(LED2, HIGH);
      Serial.println("LED2 ON");

    }
    else if(text==3){

      digitalWrite(LED3, HIGH);
      Serial.println("LED3 ON");

    }
    else{

      digitalWrite(LED1,LOW);
      digitalWrite(LED2,LOW);
      digitalWrite(LED3,LOW);
   }

  }
}