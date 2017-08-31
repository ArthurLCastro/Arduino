// Módulo Reed Switch - Sketch para teste
// Arthur L. Castro
// Abril de 2017

#define reed 8
#define led 13

void setup() {
  pinMode(led,OUTPUT);
  pinMode(reed,INPUT);
  Serial.begin(9600);
}

void loop() {
  boolean leitura = digitalRead(reed);
  Serial.print("Leitura: ");
  if(leitura == HIGH){
    Serial.println("Objeto detectado");
    digitalWrite(led,HIGH);
  } else {
    Serial.println("Nenhum objeto detectado");  
    digitalWrite(led,LOW);
  }
  delay(100);
}
