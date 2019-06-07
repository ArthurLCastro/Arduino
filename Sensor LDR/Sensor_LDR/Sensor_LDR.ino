// Leitura de Luminosidade Ambiente com LDR
// Arthur Castro
// Julho de 2017

#define LDR A0
#define intervalo 500

int lum = 0;
int lum_percent = 0;

void setup() {
  pinMode(LDR,INPUT);
  Serial.begin(9600);
}

void loop() {
  lum = analogRead(LDR);
  lum_percent = map(lum,0,1023,0,100);
  
  Serial.print("Luminosidade: ");
  Serial.print(lum_percent);
  Serial.println("%");
  
  delay(intervalo);
}
