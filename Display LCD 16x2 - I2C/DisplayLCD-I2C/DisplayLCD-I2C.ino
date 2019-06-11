// Utilização do Display LCD 16x2 com módulo de comunicação I2C
// Arthur Castro
// Junho de 2019

#include <LiquidCrystal_I2C.h>

// Definição do Endereço I2C para Display (Descomente a linha apropriada abaixo)
//#define endI2C 0x27         // Endereço para o chip PCF8574T com A0, A1 e A2 em H
//#define endI2C 0x3F         // Endereço para o chip PCF8574AT com A0, A1 e A2 em H

// Cria o Objeto "lcd" do tipo "LiquidCrystal_I2C"
LiquidCrystal_I2C lcd(endI2C, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  lcd.begin (16,2);					// Inicializa o display (qtd. colunas, qtd. linhas)
  lcd.setBacklight(HIGH);
}

void loop() {
  lcd.clear();						// Limpa o Display
  lcd.setCursor(0,0);				// Seta a posição do cursor (coluna, linha)
  lcd.print("      Ola"); 			// Imprime o texto "Ola" na primeira linha do Display
  lcd.setCursor(0,1);				// Seta a posição do cursor (coluna, linha)
  lcd.print("     Mundo!"); 		// Imprime o texto "Mundo!" na segunda linha do Display

  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  ArthurLCastro ");

  delay(1000);
}