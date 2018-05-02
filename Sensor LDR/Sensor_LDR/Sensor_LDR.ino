// Leitura de Luminosidade Ambiente com LDR
// Arthur Castro
// Julho de 2017

#define LDR A0
int lum = 0;
float lum_percent = 0;

void setup() {
  pinMode(LDR,INPUT);
  Serial.begin(9600);
}

void loop() {
  lum = analogRead(ldr);
  lum_percent = map(lum,0,1023,0,100);
  Serial.print("Luminosidade: ");
  Serial.println(lum_percent);
  delay(500);
}
