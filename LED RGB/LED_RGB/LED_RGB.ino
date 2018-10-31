// LED RGB - Sketch para Teste
// Arthur L. Castro
// Abril de 2017

#define Red 9
#define Green 10
#define Blue 11

void setup() {
  pinMode(Red,OUTPUT);
  pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
}

void loop() {
  fade(Red);
  delay(100);
  fade(Green);
  delay(100);
  fade(Blue);
  delay(100);

}

void fade(int led){
  for(int i=0; i<255; i++){
    analogWrite(led,i);
    delay(5);
  }
  for(int i=255; i>0; i--){
    analogWrite(led,i);
    delay(5);
  }
}
