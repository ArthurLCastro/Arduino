//String lido = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
 Serial.println(lerSerial());
  delay(1000);
}

String lerSerial(){
  String retorno = "";

  if(Serial.available()>0){
    while(Serial.available()>0){
      retorno += char(Serial.read());
      delay(5);
    }
    Serial.flush();
    //Serial.println(retorno);
  }  
  return retorno;
}
