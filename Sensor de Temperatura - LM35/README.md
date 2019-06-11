# Display LCD 16x2 - com comunicação I2C

## Hardware:
<figure>
    <img src="/Display LCD 16x2 - I2C/img/DisplayLCD-I2C.png" width="70%" alt="Hardware">
    <figcaption>figura 01 - Hardware</figcaption>
</figure>

</br> 
</br> 

<figure>
    <img src="/Display LCD 16x2 - I2C/img/Modulo-I2C.png" width="70%" alt="Módulo I2C para Display LCD">
    <figcaption>figura 02 - Módulo I2C</figcaption>
</figure>

</br> 

## Biblioteca:
O sketch utiliza a bilbioteca [LCD library](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home). Uma bilbioteca derivada da LiquidCrystal original do Arduino. Foi desenvolvida para ser compatível com a atual biblioteca LiquidCrystal, possuindo desempenho mais rápido de quase 5 vezes e totalmente extensível, se necessário.

## Endereçamento I2C:
Para que o código [DisplayLCD-I2C.ino](https://github.com/ArthurLCastro/modulos-arduino/) seja compilado é necessário endereçar o módulo I2C corretamente.
<figure>
    <img src="/Display LCD 16x2 - I2C/img/terminais-de-enderecamento.png">
    <figcaption>figura 03 - Terminais de Endereçamento</figcaption>
</figure>

</br> 

Verifique se o módulo que você está utilizando possui o chip **PCF8574T** ou o chip **PCF8574AT** e se há curto nos terminais de endereçamento (figura 03). Compare com os valores da tabela abaixo para descobrir qual o valor que deverá ser passado no código do Arduino.

| A2 | A1 | A0 | PCF8574T | PCF8574AT |
|----|----|----|----------|-----------|
| 0  | 0  | 0  | 0x20     | 0x38      |
| 0  | 0  | 1  | 0x21     | 0x39      |
| 0  | 1  | 0  | 0x22     | 0x3A      |
| 0  | 1  | 1  | 0x23     | 0x3B      |
| 1  | 0  | 0  | 0x24     | 0x3C      |
| 1  | 0  | 1  | 0x25     | 0x3D      |
| 1  | 1  | 0  | 0x26     | 0x3E      |
| 1  | 1  | 1  | 0x27     | 0x3F      |

_**Obs.:** Na maioria dos casos A2, A1 e A0 estarão em nível lógico alto (H), ou seja, sem curtos nos terminais de configuração I2C. Logo, basta descomentar a 8ª ou 9ª linha para do código baseando-se na tabela acima._

## Referências:
* [Biblioteca NewLiquidCrystalI2C](https://bitbucket.org/fmalpartida/new-liquidcrystal/wiki/Home)
* [Display LCD 20×4 e LCD 16×2 com Adaptador I2C – Utilizando o display com Arduino](https://portal.vidadesilicio.com.br/display-lcd-20x4-16x2-adaptador-i2c/)
* [Como utilizar o módulo I2C com display LCD](https://www.arduinoecia.com.br/2014/12/modulo-i2c-display-16x2-arduino.html)