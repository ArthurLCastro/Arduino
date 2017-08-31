// Módulo Laser - Sketch para Teste
// Arthur L. Castro
// Abril de 2017

#define laser 13

void setup() {
  pinMode(laser,OUTPUT);
  Serial.begin(9600);
  Serial.print("Digite 1 para ligar o lazer ou outro valor para desligar: \n");
}

void loop() {
  if(Serial.available() > 0){
    char estado = Serial.read();
    
    Serial.println(estado);
    
    if(estado == '1'){
      digitalWrite(laser, HIGH);
    } else {
      digitalWrite(laser, LOW);    
    }
  }
}
