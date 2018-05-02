// Leitura de Temperatura e Umidade com Sensor DHT22
// Arthur Castro
// Novembro de 2017

#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
float temp;
float hum;

void setup() {
dht.begin();
Serial.begin(9600);
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.println(temp);
  Serial.print("Umidade: ");
  Serial.println(hum);

  delay(500);
}
