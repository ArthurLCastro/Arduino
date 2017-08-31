// Módulo Relé (1 canal) - Sketch para Teste
// Arthur L. Castro
// Abril de 2017

#define rele 7

void setup() {
  pinMode(rele,OUTPUT);
  Serial.begin(9600);
  Serial.print("Digite 1 para acionar o Rele ou outro valor para desacionar: \n");
}

void loop() {
  if(Serial.available() > 0){
    char estado = Serial.read();
    
    Serial.println(estado);
    
    if(estado == '1'){
      digitalWrite(rele, HIGH);
    } else {
      digitalWrite(rele, LOW);    
    }
  }
}
