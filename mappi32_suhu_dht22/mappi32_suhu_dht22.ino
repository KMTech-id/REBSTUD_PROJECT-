//dinda(Ndaisna_)



#include <DHT.h>
#define DHTPIN 25
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

float Temperature;
float Humidity;

void setup() {
  Serial.begin(115200);
  dht.begin();

}

void loop() {
  Temperature = dht.readTemperature();
  Humidity = dht.readHumidity();
  Serial.print ("Temperature = ");
  Serial.print (Temperature);
  Serial.println (" c ");
  Serial.print("Humidity = ");
  Serial.print (Humidity);
  Serial.println (" % ");
  delay (1000);
}
