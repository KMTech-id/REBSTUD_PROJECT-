//UNTUK MENDEKLARASIKAN PIN
#define PIN_RELAY_1  16
#define PIN_RELAY_2  17
#define PIN_RELAY_3  25
#define PIN_RELAY_4  26




void setup() {
  Serial.begin(9600);

  // MENGINISIALISASI PIN DIGITAL SEBAGAI OUTPUT
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
  pinMode(PIN_RELAY_3, OUTPUT);
  pinMode(PIN_RELAY_4, OUTPUT);
}

// MENJALANKAN CODINGAN BERULANG ULANNG
void loop() {
  Serial.println("Turn on all");
  digitalWrite(PIN_RELAY_1, HIGH);
  digitalWrite(PIN_RELAY_2, HIGH);
  digitalWrite(PIN_RELAY_3, HIGH);
  digitalWrite(PIN_RELAY_4, HIGH);
  delay(1000);

  Serial.println("Turn off all");
  digitalWrite(PIN_RELAY_1, LOW);
  digitalWrite(PIN_RELAY_2, LOW);
  digitalWrite(PIN_RELAY_3, LOW);
  digitalWrite(PIN_RELAY_4, LOW);
  delay(1000);
}
