#define triggerPin 5
#define echoPin 16

long duration;
int jarak;

void setup()
{
  Serial.begin(115200);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  digitalWrite(triggerPin, LOW);   //Set triggerPin low
  delayMicroseconds(2);       // delay 2 micro second

  digitalWrite(triggerPin, HIGH);  // Set triggerPin high
  delayMicroseconds(10);      // triggerPin high selama 10 micro seconds
  digitalWrite(triggerPin, LOW);   // triggerPinPin low

  duration = pulseIn(echoPin, HIGH);   //Pembacaan Echo pin dan durasi
  jarak = duration * 0.034 / 2;   ///Menghitung jarak yg sebenarnya

  Serial.println("jarak :");
  Serial.print(jarak);
  Serial.println(" cm");

  
}
