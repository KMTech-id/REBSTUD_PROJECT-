// syafanida_Rebstud
int SensorPin = 34;// deklarasi pin analog yg dipakai
int soilMoistureValue; // menyimpan nilai analog dari sensor ke esp32
int soilmoisturepercent; // nilai yg diperoleh dalam bentuk persen setelah dimaping

#define RedLed  13 // PIN LED Merah
#define YellowLed  12 // PIN LED Kuning
#define GreenLed  14 // PIN LED Hijau

void setup() {
  Serial.begin(115200); // Baudrate komunikasi dengan serial monitor
  pinMode (RedLed, OUTPUT);
  pinMode (YellowLed, OUTPUT);
  pinMode (GreenLed, OUTPUT);
}

void loop() {
  soilMoistureValue = analogRead(SensorPin);
  Serial.print("Nilai analog = ");
  Serial.println(soilMoistureValue);
  soilmoisturepercent = map(soilMoistureValue, 4095, 0, 0, 100);

  Serial.print("Presentase kelembaban tanah= ");
  Serial.print(soilmoisturepercent);
  Serial.println("% ");
  
  if (soilmoisturepercent > 60 && soilmoisturepercent <= 100) {
    Serial.println("Tanah basah");
    digitalWrite (GreenLed, HIGH);
    digitalWrite (RedLed, LOW);
    digitalWrite (YellowLed, LOW);
  }
  else if (soilmoisturepercent > 30 && soilmoisturepercent <= 60) {
    Serial.println("Tanah kondisi normal");
    digitalWrite (YellowLed, HIGH);
    digitalWrite (RedLed, LOW);
    digitalWrite (GreenLed, LOW);
  }
  else if (soilmoisturepercent >= 0 && soilmoisturepercent <= 30) {
    Serial.println("Tanah Kering");
    digitalWrite (RedLed, HIGH);
    digitalWrite (YellowLed, LOW);
    digitalWrite (GreenLed, LOW);
  }
  delay(3000);
}
