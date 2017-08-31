// Módulo LDR - Sketch para teste
// Arthur L. Castro
// Abril de 2017

#define ldr A0

void setup() {
  pinMode(ldr,INPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura, leituraPercent;
  
  leitura = analogRead(ldr);
  leituraPercent = map(leitura,0,1023,0,100);
  Serial.print("Luminosidade: ");
  Serial.print(leituraPercent);
  Serial.println("%");
  delay(100);
}
