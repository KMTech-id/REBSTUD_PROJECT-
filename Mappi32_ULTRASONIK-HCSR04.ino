#define echoPin 13 //Membuat variabel Echo ke-pin 13
#define trigPin 12

long durasi, jarak;

void setup() {
  Serial.begin (115200); //Berfungsi untuk komunikasi serial dengan komputer
  pinMode(trigPin, OUTPUT); //Set varibel trigPin sebagai output
  pinMode(echoPin, INPUT); //Set variabel echoPin sebagai input

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
 
  durasi = pulseIn(echoPin, HIGH); //Echo menerima sinyal ultrasonik
  jarak = (durasi / 2) / 29.1; //Rumus mengubah durasi menjadi jarak (cm)



Serial.print("Jarak :");
Serial.print(jarak);
Serial.println("cm ");

delay(1000);
} 
