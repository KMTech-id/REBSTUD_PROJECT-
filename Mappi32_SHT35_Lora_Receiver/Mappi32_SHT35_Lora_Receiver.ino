#include <SPI.h>
#include <LoRa.h>
#define ss 15
#define rst 0
#define dio0 27

String data1, data2 ;

void setup() {

  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");

  //setup LoRa transceiver module
  //  SPI.begin(52,50, 51, 53);
  SPI.begin(14, 12, 13, 15);
  LoRa.setPins(ss, rst, dio0);

  //replace the LoRa.begin(---E-) argument with your location's frequency
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(915E6)) {
    Serial.println(".");
    delay(500);
  }

  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

  void loop() {

    // try to parse packet
    int packetSize = LoRa.parsePacket();
    if (packetSize) {
      String LoRaData;
      Serial.println("Received packet\n ");
      // received a packet
      while (LoRa.available())
      {
        LoRaData = LoRa.readString();
        Serial.println(LoRaData);

      }

      if ( LoRaData.charAt(0) == '#') {
        int i = 1;
        for (i; i < LoRaData.length(); i++) {
          if (LoRaData.charAt(i) == ',') {
            break;
          }
          else {
            data1 += LoRaData.charAt(i);
          }
        }

        int j = i + 1 ;
        for (j; j < LoRaData.length(); j++) {
          if (LoRaData.charAt(j) == '!') {
            break;
          }
          else {
            data2 += LoRaData.charAt(j);
          }
        }

      }

      Serial.print("Temperature: ");
      Serial.println(data1);
      Serial.print("Humidity: ");
      Serial.println(data2);

      data1 = "";
      data2 = "";

      delay (1000);

    }
  }
