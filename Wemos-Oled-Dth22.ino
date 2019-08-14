#include <Wire.h>                               // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h"                        // legacy: #include "SSD1306.h"
#include "icons.h"                              // For weather icons
#include "Open_Sans_Condensed_Bold_16.h"        // Open Sans Condensed Font for the numbers
#include "Open_Sans_Condensed_Bold_20.h"          // Open Sans Condensed Font for the numbers
#include "Open_Sans_Condensed_Bold_24.h"        // Open Sans Condensed Font for the numbers
#include "Meteocons_Bold_10.h"                  // Meteocons Weather icons
#include "DHT.h"                                // For DHT 22
#include <math.h>
#include <ESPWiFi.h>
#include <ArduinoJson.h>
#include <time.h>                       // time() ctime()
#include <sys/time.h>                   // struct timeval
#include <coredecls.h>                  // settimeofday_cb()



// WIFI
const char* WIFI_SSID = "Webcreek";
const char* WIFI_PWD = "gosu2017";

//const char* WIFI_SSID = "GUARRODSTUDIO";
//const char* WIFI_PWD = "3libras#";


#define DHTPIN 2     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//int maxHum = 60;
//int maxTemp = 40;
DHT dht(DHTPIN, DHTTYPE);


// Openweathermap
String APIKEY = "5f251236f1a557338bf6de0f745e4792";
String CityID = "3652462";                                 //Your City ID
WiFiClient client;
char servername[] = "api.openweathermap.org";            // remote server we will connect to
String result;
String result2;
int  counter = 60;
String weatherDescription = "";
String weatherLocation = "";
String Country;
float Temperature;
float Humidity;
float Pressure;
int tempOut;
int humOut;
String Icon;
float weatherUvi;


// Initialize the OLED display using Arduino Wire:
SSD1306Wire display(0x3c, SDA, SCL);   // ADDRESS, SDA, SCL  -  SDA and SCL usually populate automatically based on your board's pins_arduino.h

int demoMode = 0;
//int counter = 1;

void setup() {
  Serial.begin(115200);
  display.init();
  dht.begin();
  display.flipScreenVertically();


  Serial.println("Iniciando");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PWD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.drawXbm(34, 8, 60, 36, WiFi_Logo_bits);
    display.drawString(35, 50, "Conectando");
    display.display();
    Serial.print(".");
  }
  display.clear();
  Serial.println("");
  Serial.println("--------------------------------------------------");
  Serial.print("WiFi connected to ");
  Serial.print(WIFI_SSID);
  Serial.print(" With IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("--------------------------------------------------");


 
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

  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));

  Serial.print("  ");
  Serial.println(Icon);



  /////// INDOOR  ///////
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 0, "Indoor");

  display.setFont(Open_Sans_Condensed_Bold_20);

  //display.drawString(0, 12, "Temperatura: ");
  display.drawString(0, 7, String(temperatura));
  display.drawString(20, 7, "°");

  display.drawString(35, 7, String(humedad));
  //display.drawString(55, 7, "%");
  display.drawXbm(55, 13, 8, 16, drop);

  //display.drawString(95, 25, String(sensacion));
  //display.drawString(109, 25, "°C");


  /////// OUTDOOR  ///////
  display.setFont(ArialMT_Plain_10);
  display.drawString(0, 33, "Outdoor");

  display.setFont(Open_Sans_Condensed_Bold_20);
  display.drawString(0, 41, String(tempOut));
  display.drawString(20, 41, "°");

  display.drawString(35, 41, String(humOut));
  //display.drawString(55, 41, "%");
  display.drawXbm(55, 47, 8, 16, drop);

  display.drawString(70, 41, String(weatherUvi));
  display.setFont(ArialMT_Plain_10);
  display.drawString(114, 52, "uV");
  

  //display.drawString(40,80, String(Icon));

  display.drawXbm(75,-5, 50, 50, clear_day_bits);     //Icon TODO: Make Dinamyc
  //display.drawHorizontalLine(20, 58, 60);          //For aligment tests





  if (counter == 60)                                //Get new data every 10 minutes
  {
    counter = 0;
    delay(1000);
    getWeatherData();
    getUvi();
  } else
  {
    counter++;
    displayWeather(weatherLocation, weatherDescription);
    delay(5000);
    displayConditions(Temperature, Humidity, Pressure);
    delay(5000);
  }



  display.display();

}


void getWeatherData()                                //client function to send/receive GET request data.
{
  if (client.connect(servername, 80))
  { //starts client connection, checks for connection
    client.println("GET /data/2.5/weather?id=" + CityID + "&units=metric&APPID=" + APIKEY);
    client.println("Host: api.openweathermap.org");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();
  }
  else {
    Serial.println("connection failed");        //error message if no client connect
    Serial.println();
  }

  while (client.connected() && !client.available())
    delay(1);                                          //waits for data
  while (client.connected() || client.available())
  { //connected or data available
    char c = client.read();                     //gets byte from ethernet buffer
    result = result + c;
  }

  client.stop();                                      //stop client
  result.replace('[', ' ');
  result.replace(']', ' ');
  Serial.println(result);
  char jsonArray [result.length() + 1];
  result.toCharArray(jsonArray, sizeof(jsonArray));
  jsonArray[result.length() + 1] = '\0';
  StaticJsonBuffer<1024> json_buf;
  JsonObject &root = json_buf.parseObject(jsonArray);

  if (!root.success())
  {
    Serial.println("parseObject() failed");
  }

  String location = root["name"];
  String country = root["sys"]["country"];
  float temperature = root["main"]["temp"];
  float humidity = root["main"]["humidity"];
  String weather = root["weather"]["main"];
  String description = root["weather"]["description"];
  float pressure = root["main"]["pressure"];
  String icon = root["weather"]["icon"];
  weatherDescription = description;
  weatherLocation = location;
  Country = country;
  Icon = icon;
  Temperature = temperature;
  tempOut = round(temperature);
  humOut = round(humidity);
  Humidity = humidity;
  Pressure = pressure;
}


void getUvi(){
   if (client.connect(servername, 80))
  { //starts client connection, checks for connection
    client.println("GET /data/2.5/uvi?appid=5f251236f1a557338bf6de0f745e4792&lat=-0.23&lon=-78.53");
    client.println("Host: api.openweathermap.org");
    client.println("User-Agent: ArduinoWiFi/1.1");
    client.println("Connection: close");
    client.println();
  }
  else {
    Serial.println("connection failed");        //error message if no client connect
    Serial.println();
  }

  while (client.connected() && !client.available())
    delay(1);                                          //waits for data
  while (client.connected() || client.available())
  { //connected or data available
    char c = client.read();                     //gets byte from ethernet buffer
    result2 = result2 + c;
  }

  client.stop();                                      //stop client
  result2.replace('[', ' ');
  result2.replace(']', ' ');
  Serial.println(result2);
  char jsonArray [result2.length() + 1];
  result2.toCharArray(jsonArray, sizeof(jsonArray));
  jsonArray[result2.length() + 1] = '\0';
  StaticJsonBuffer<1024> json_buf;
  JsonObject &root = json_buf.parseObject(jsonArray);

  if (!root.success())
  {
    Serial.println("parseObject() failed");
  }


  float uvi = root["value"];
  weatherUvi = uvi;


}

//const char* getIconFromString(String icon) {
//   //"clear-day, clear-night, rain, snow, sleet, wind, fog, cloudy, partly-cloudy-day, or partly-cloudy-night"
//  if (icon == "clear-day") {
//    return clear_day_bits;
//  } else if (icon == "clear-night") {
//    return clear_night_bits;
//  } else if (icon == "rain") {
//    return rain_bits;
//  } else if (icon == "snow") {
//    return snow_bits;
//  } else if (icon == "sleet") {
//    return sleet_bits;
//  } else if (icon == "wind") {
//    return wind_bits;
//  } else if (icon == "fog") {
//    return fog_bits;
//  } else if (icon == "cloudy") {
//    return cloudy_bits;
//  } else if (icon == "partly-cloudy-day") {
//    return partly_cloudy_day_bits;
//  } else if (icon == "partly-cloudy-night") {
//    return partly_cloudy_night_bits;
//  }
//  return cloudy_bits;
//}

void displayWeather(String location, String description)
{

}

void displayConditions(float Temperature, float Humidity, float Pressure)
{

}

void displayGettingData()
{

}
