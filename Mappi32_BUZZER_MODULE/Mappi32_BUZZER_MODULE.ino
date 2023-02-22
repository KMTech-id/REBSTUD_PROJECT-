
const int PIN17 = 17; //memberikan nama alias pin13

void setup() {
  pinMode(PIN17, OUTPUT); //deklarasi nama alias pin9 sebagai output
}

//fungsi untuk membuat dering pendek dengan duty cycle 50%,selama 0,8 s
void dering_pendek() {
  digitalWrite(PIN17, HIGH);
  delay(400);
  digitalWrite(PIN17, LOW);
  delay(400);
}

//fungsi untuk membuat dering pendek dengan duty cycle 50% ,selama 1,4 s
void dering_panjang() {
  digitalWrite(PIN17, HIGH);
  delay(700); //memberikan nilai tunda 0.7 second
  digitalWrite(PIN17, LOW);
  delay(700);
}

void loop() {
  void dering_pendek(); //memanggil fungsi dering_pendek()
  void dering_pendek();
  void dering_panjang(); //memanggil fungsi dering_panjang()
  delay(300);
}
