#include <SoftwareSerial.h>

#define RX_GSM1 8         // Ligar o Pino 8 do Arduino no TX do Módulo "SIM808 EVB-V3.2"
#define TX_GSM1 7         // Ligar o Pino 7 do Arduino no RX do Módulo "SIM808 EVB-V3.2"

SoftwareSerial serialGSM1(RX_GSM1, TX_GSM1);

void setup() {
  Serial.begin(9600);                  // Serial é um objeto instanciado de HardwareSerial que extende Stream
  serialGSM1.begin(9600);              // serialGSM1 é um objeto instanciado de SoftwareSerial que extende Stream
}

void loop() {
 if(serialGSM1.available()>0){
  Serial.println(lerSerial(serialGSM1));
 }
}

String lerSerial(Stream& out){        // Stream é uma classe abstrata, Pai de HardwareSerial e de SoftwareSerial
  String retorno = "";

  if(out.available()>0){
    while(out.available()>0){
      retorno += char(out.read());
      delay(5);
    }
    out.flush();
  }  
  return retorno;
}
