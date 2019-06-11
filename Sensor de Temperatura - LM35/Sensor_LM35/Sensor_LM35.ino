// Sensor de Temperatura - LM35
// Arthur L. Castro
// Junho de 2019

#define TENSAO_mV 5000
#define RESOL_ADC 1024
#define TEMP_PIN A0
#define INTERVALO 1000

float lerTemperatura(unsigned int);

void setup(){
  pinMode(TEMP_PIN, INPUT);
  Serial.begin(9600);
}

void loop(){
  int i;
  float temp = 0;
  
// Tira a média da temperatura
  for(i=0; i<10; i++){
    temp += lerTemperatura(TEMP_PIN);
    delay(5);
  }
  temp = temp / i;

  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("*C");
 
  delay(INTERVALO);
}

float lerTemperatura(unsigned int pinSensor){
    /*
    ------------ Cálculo de Constante: ------------
    Tensão = 5V
    Resolução do Conversor AD do ATmega328 = 1024
    Fator de Escala do LM35 = 10mV/ºC

    (5000mV/1024)/10mV = 0.48828125
    -----------------------------------------------
  */
  const float constante = (TENSAO_mV / RESOL_ADC) / 10;
  unsigned int valorLido;
  float temperatura;

  valorLido = analogRead(pinSensor);
  temperatura = valorLido * constante;  

  return temperatura;
}
