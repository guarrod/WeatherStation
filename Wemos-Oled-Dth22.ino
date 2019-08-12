#include <Wire.h>                               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"                        // legacy: #include "SSD1306.h"
#include "images.h"                             // For weather icons
#include "Open_Sans_Condensed_Bold_16.h"        // Open Sans Condensed Font for the numbers
#include "Open_Sans_Condensed_Bold_24.h"
#include "DHT.h"                                // For DHT 22
#include <math.h>


  #define DHTPIN 2     // what pin we're connected to
  #define DHTTYPE DHT22   // DHT 22  (AM2302)
  //int maxHum = 60;
  //int maxTemp = 40;

DHT dht(DHTPIN, DHTTYPE);

// Initialize the OLED display using Arduino Wire:
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL  -  SDA and SCL usually populate automatically based on your board's pins_arduino.h

int demoMode = 0;
int counter = 1;

void setup() {
  Serial.begin(115200);
  display.init();
  dht.begin();
  display.flipScreenVertically();

  
  Serial.println("Iniciando");
}

void drawProgressBarDemo() {
  int progress = (counter / 5) % 100;
  // draw the progress bar
  display.drawProgressBar(0, 32, 120, 10, progress);

  // draw the percentage as String
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 15, String(progress) + "%");
}


void loop() {
  delay(2000);
  display.clear();
  display.setFont(ArialMT_Plain_10);
  

  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Compute heat index in Celsius
  float hic = dht.computeHeatIndex(t, h, false);
  
  int humedad = round(h);
  int temperatura = round(t);
  int sensacion = round(hic);


  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }





//  if(h > maxHum || t > maxTemp) {
//      digitalWrite(fan, HIGH);
//  } else {
//     digitalWrite(fan, LOW); 
//  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  
  Serial.print(F("°C "));
  
  Serial.print(F("°Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));

  display.setFont(ArialMT_Plain_10);
  display.drawString(6, 0, "Indoor");

  display.setFont(Open_Sans_Condensed_Bold_24);

  //display.drawString(0, 12, "Temperatura: ");
  display.drawString(0, 10, String(temperatura));
  display.drawString(23, 10, "°");
  
  display.drawString(40,10, String(humedad));
  display.drawString(65, 10, "%");
  
  //display.drawString(95, 25, String(sensacion));
  //display.drawString(109, 25, "°C");
  
  display.display();

}
