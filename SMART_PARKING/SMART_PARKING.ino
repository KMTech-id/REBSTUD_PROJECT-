//KMTek
//Selamat Berkarya

#include <WiFi.h>  //library WiFi
#include <PubSubClient.h> // library PubSubClient

#define WIFISSID "XXXXXX"                           // Nama Hotspot / WiFi
#define PASSWORD "XXXXXX"                       // Password WiFi
#define TOKEN "XXXXXXXXXXXXXXXXXXX"   // Ubidots TOKEN
#define MQTT_CLIENT_NAME "smart-parking"

#define VARIABLE_LABEL_1 "jarak" // Nama Variabel 1
#define DEVICE_LABEL "smart-parking" // Device Label 

#define triggerPin 26 //mendefinisikan pin 26 Mappi32 sebagai trigger pin sensor ultrasonic
#define echoPin 25   //mendefinisikan pin 25 Mappi32 sebagai echoPin pin sensor ultrasonic
#define LED 23    //mendefinisikan pin 23 Mappi32 sebagai pin Output LED
#define Buzzer 19 //mendefinisikan pin 19 Mappi32 sebagai pin Output Buzzer

long duration; // variabel durasi sensor ultrasonic
int jarak;   // jarak dalam centimeter

char mqttBroker[]  = "industrial.api.ubidots.com";
char payload[700];
char topic[150];

char str_val_1[6];

WiFiClient ubidots;
PubSubClient client(ubidots);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");

    // Attemp to connect
    if (client.connect(MQTT_CLIENT_NAME, TOKEN, "")) {
      Serial.println("Connected");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      // Wait 2 seconds before retrying
      delay(2000);
    }
  }
}

void setup()
{
  Serial.begin(112500); // setting kecepatan pengiriman serial monitor
  WiFi.begin(WIFISSID, PASSWORD);

  pinMode(triggerPin, OUTPUT); // set trigger sebagai output
  pinMode(echoPin, INPUT); // set echo sebagai input
  pinMode(LED , OUTPUT); //output untuk lampu
  pinMode(Buzzer, OUTPUT); // setting Buzzer sebagai Output

  Serial.println();
  Serial.print("Wait for WiFi...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  client.setServer(mqttBroker, 1883);
  client.setCallback(callback);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }

  digitalWrite(triggerPin, HIGH);// aktifkan sensor ultrasonic
  delayMicroseconds(10); // selama 10 microseconds
  digitalWrite(triggerPin, LOW); // matikan sensor ultrasonic

  duration = pulseIn(echoPin, HIGH);   //baca rentan waktu dari triggerPin High sampai echoPin high
  jarak = duration * 0.034 / 2;   /// konversi selang waktu ke CM

  if (jarak != 0) {
    Serial.print("jarak :");
    Serial.print(jarak);
    Serial.println(" cm");

    dtostrf(jarak, 4, 2, str_val_1);

    sprintf(topic, "%s", "");
    sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);

    sprintf(payload, "%s", ""); // Cleans the payload content
    sprintf(payload, "{\"%s\":", VARIABLE_LABEL_1);
    sprintf(payload, "%s {\"value\": %s}", payload, str_val_1);
    sprintf(payload, "%s}", payload);

    Serial.println("Publishing data to Ubidots Cloud");
    client.publish(topic, payload);
    client.loop();
    delay(1000);
  }

  if (jarak <= 3) { // Jika jarak kurang dari atau sams dengan 3cm maka
    digitalWrite(LED, HIGH); // Led high/menyala
    digitalWrite(Buzzer, LOW); //Buzzer berbunyi (Buzzer Low level trigger)
    delay (250);
  }
  else {
    digitalWrite(LED, LOW);
    digitalWrite(Buzzer, HIGH );
    delay (500);
  }

  delay (500);
}
