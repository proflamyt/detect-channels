//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  //radio.openReadingPipe(0, address);
  
  //Set module as receiver
 
}

void loop()
{
  // channel4,5, 6
  for (int i =0; i<128; i++){
  radio.setChannel(i);
     radio.startListening();
     delayMicroseconds(225);

    if (radio.testCarrier() )
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
    Serial.print("channel");
    Serial.println(i);
  }

  radio.stopListening();
  }
  //Read the data if available in buffer
  
}
