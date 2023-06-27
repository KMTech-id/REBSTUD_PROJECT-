#include <WiFi.h>

const char* ssid = "Rebstud";
const char* password = "12345678";

void setup() {
  Serial.begin(115200);

  // Menghubungkan ke jaringan WiFi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Menghubungkan ke WiFi...");
  }

  Serial.println("Terhubung ke WiFi!");
  Serial.print("Alamat IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Kode yang dijalankan secara berulang di sini
}
