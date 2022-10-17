int sensorPin = 34;
int sensorValue ;

void setup () {
  Serial.begin(112500);

}
void loop () {
  sensorValue = analogRead(sensorPin);
  Serial.print("Nilai LDR : ");
  Serial.println(sensorValue);
  delay (1000);

}
