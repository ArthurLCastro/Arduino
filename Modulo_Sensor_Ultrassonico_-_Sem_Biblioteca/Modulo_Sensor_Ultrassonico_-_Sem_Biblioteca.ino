// Módulo Sensor Ultrassônico (Sem uso de biblioteca) - Sketch para teste
// Arthur L. Castro
// Dezembro de 2016

#define TrigPin 13
#define EchoPin 12
 
void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  digitalWrite(TrigPin, LOW);         //Saída de Trigger inicia em nível baixo

  Serial.begin(9600);
}

void loop() {
  double TempoMicros;
  double Dist;
  
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  
  TempoMicros = pulseIn(EchoPin, HIGH);         //pulseIn() Mede, em microsegundos, o tempo em que o pino de Echo passou em nivel alto
  
/*    CÁLCULOS:

        Velocidade do Som no ar (20ºC ao nível do mar):  343m/s ou 34300cm/s
        Para achar a distância devemos dividir por 2 (Tempo do Trigger para Echo):
          34300 / 2 = 1750cm/s
        
        1000000 us  -----  1750cm/s
            x us    -----    1cm

            x = 58.3           */
  
  Dist = TempoMicros / 58.3;          //Valor da distância em centímetros
 
  Serial.print("Distancia: ");
  Serial.print(Dist);
  Serial.print(" cm");

  Serial.print(" | Tempo de Duracao do Echo: ");
  Serial.print(TempoMicros);
  Serial.println(" us");

  delay(10);          // Atualização
}
