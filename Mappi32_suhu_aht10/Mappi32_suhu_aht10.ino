//dinda(Ndaisna_)

#include <Adafruit_AHTX0.h> //library AHT 10
 
Adafruit_AHTX0 aht; //variabel 
 
void setup() 
{
  Serial.begin(115200); //baundrate yang kita gunakan untuk menjalankan program di Serial Monitor
  Serial.println("Adafruit AHT10 demo!");
 
  if (! aht.begin()) 
  {
    Serial.println("Could not find AHT 10?"); //
    while (1) delay(10);
  }
  Serial.println("AHT10 found");
}
 
void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  Serial.print("Temperature: "); //kata yang akan tampil di serial monitor
  Serial.print(temp.temperature); 
  Serial.println(" C");
  Serial.print("Humidity: ");   //kata yang akan tampi di serial monitor
  Serial.print(humidity.relative_humidity); 
  Serial.println(" %");
 
  delay(500);  
}
