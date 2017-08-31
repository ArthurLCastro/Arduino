// Módulo Joystick - Sketch para Teste
// Arthur L. Castro
// Abril de 2017

#define VRx A0
#define VRy A1
#define SW 8

void setup() {
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP);          // Utiliza-se um Resistor PULL-UP na entrada SW para evitar falsas leituras
  Serial.begin(9600);
}

void loop() {
  int VRx_Lido = analogRead(VRx);
  int VRy_Lido = analogRead(VRy);
  int SW_Lido = digitalRead(SW);
  
  Serial.print("VRx: ");
  Serial.println(VRx_Lido);         // Imprime o valor lido de VRx no Monitor Serial
  Serial.print("VRy: ");
  Serial.println(VRy_Lido);         // Imprime o valor lido de VRy no Monitor Serial
  
  if(SW_Lido == LOW){               // Imprime o estado do PushButton SW no Monitor Serial
    Serial.println("SW: Botao Pressionado");
  } else {
    Serial.println("SW: Botao Despressionado");
  }
  Serial.print("\n");              // Pula uma linha para melhor vizualização

  delay(500);                      // Atualização: Tempo de espera para a próxima leitura
}
