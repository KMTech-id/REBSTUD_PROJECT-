//Ndaisna_

int sensorPin = 34; //pin AO Ldr
int sensorValue;


//pin LED
#define RedLed  13
#define YellowLed  12
#define GreenLed  14
void setup () {
  Serial.begin(112500); //baundrate agar bisa ditampilkan di serial monitor
  pinMode (RedLed, OUTPUT);
  pinMode (YellowLed, OUTPUT);
  pinMode (GreenLed, OUTPUT);
}
void loop () {
  sensorValue = analogRead(sensorPin);
  Serial.print("Nilai LDR : ");
  Serial.println(sensorValue);
  delay (1000);
  if (sensorValue == 0) {       //jika 0 maka yang nyala merah
    Serial.println("cahaya Terang");
    digitalWrite (GreenLed, LOW);
    digitalWrite (RedLed, HIGH);
    digitalWrite (YellowLed, LOW);
  }
  else if (sensorValue >= 0 && sensorValue <= 100) {  //jika lebih dari 0 dan kurang dari 100 yang nyala kuning
    Serial.println("cahaya sedang");
    digitalWrite (YellowLed, HIGH);
    digitalWrite (RedLed, LOW);
    digitalWrite (GreenLed, LOW);
  }
  else if (sensorValue > 100 && sensorValue  <= 4095) {  //jika lebih dari 100 dan kurang dari 4095 yang nyala warna hijau
    Serial.println("cahaya redup");
    digitalWrite (RedLed, LOW);
    digitalWrite (YellowLed, LOW);
    digitalWrite (GreenLed, HIGH);
  }
  
  delay(1000);
}
