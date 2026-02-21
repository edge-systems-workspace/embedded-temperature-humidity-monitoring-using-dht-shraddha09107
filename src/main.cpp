#include <Arduino.h>
#include <DHT.h>
#define DHTTYPE DHT11
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);

void setup() {
    // write your initialization code here
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 Sensor initialized");
}
void loop() {
    // write your code here
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print(" % |");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");

    delay(2000); // Wait a few seconds between measurements
}