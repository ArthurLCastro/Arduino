// Controle de Motor de Passo
// Arthur L. Castro
// Janeiro de 2018

#define in1 8
#define in2 9
#define in3 10
#define in4 11

#define tempoMotor 5

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
/*--------------------------------------------------------------------
  giro(sentido,angulo);

  Para um giro em sentido anti-horário: sentido = 0 
  Para um giro em sentido horário: sentido = 1
  
  O ângulo pode assumir qualquer valor positivo
--------------------------------------------------------------------*/
  giro(1,45);
  delay(1000);
  giro(0,45);
  delay(1000);
  giro(1,90);
  delay(1000);
  giro(0,90);
  delay(1000);
  giro(1,180);
  delay(1000);
  giro(0,180);
  delay(1000);
}

void giro(int sentido, float angulo){
  int passo[4], passoH[4] = {0x03, 0x06, 0x0C, 0x09}, passoAH[4] = {0x09, 0x0C, 0x06, 0x03}, i, j, k, steps, resto;
  
  if(sentido == 0){
    for(k=0 ; k<=3 ; k++){
      passo[k] = passoAH[k];
    }
  } else {
    for(k=0 ; k<=3 ; k++){
      passo[k] = passoH[k];
    }  
  }
    
  steps = convAngPassos(angulo);    // Retorna um número inteiro de Passos referente ao ângulo
  resto = steps % 4;                // Retorna o resto da divisão
  
  if(resto == 0){
    for(j=1; j<=(steps/4); j++){
      for(i=0; i<=3; i++){
        PORTB = passo[i];
        delay(tempoMotor);
        //Serial.println("DEBUG 1");
      }
    }
  } else {
    for(j=1; j<=(steps/4); j++){
      for(i=0; i<=3; i++){
        PORTB = passo[i];
        delay(tempoMotor);
        //Serial.println("DEBUG 2");
      }
    }
    for(i=0; i<=(resto-1); i++){
      PORTB = passo[i];
      delay(tempoMotor);
      //Serial.println("DEBUG 3");
    }
  }
}

int convAngPassos(float ang){
  float qtdPassosF;
  int qtdPassosI;
  
  qtdPassosF = 5.69 * ang;            // (2048passos / 360graus) * angulo
  qtdPassosI = round(qtdPassosF);     // Arredondamento para Inteiro mais próximo

  return qtdPassosI;
}
