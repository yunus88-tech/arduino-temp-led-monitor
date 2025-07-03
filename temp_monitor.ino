#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define LEDPIN 13

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  delay(2000);
  float temperature = dht.readTemperature();
  if (isnan(temperature)) {
    Serial.println("Fehler beim Lesen vom Sensor");
    return;
  }

  Serial.print("Temperatur: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > 25.0) {
    digitalWrite(LEDPIN, HIGH);
  } else {
    digitalWrite(LEDPIN, LOW);
  }
}
