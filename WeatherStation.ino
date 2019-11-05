#include <SPI.h>
#include <Wire.h>
#include <Sodaq_SHT2x.h>
#include <Adafruit_GFX.h>                           //For OLED
#include <Adafruit_SSD1306.h>                       //For OLED
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ArduinoJson.h>
#include "icons.h"                                  //For Icons 
#include "Fonts/Nimbus_Sans_L_10.h"                 // Arial MT 10 Font for the text  
#include "Fonts/Open_Sans_Condensed_Bold_20.h"      // Open Sans Condensed Font for the numbers
#include "Fonts/Meteocons_Regular_20.h"             // For the icons
#include <math.h>                   //For use math calculations 

//Display
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

//WIFI
ESP8266WiFiMulti wifiMulti;
boolean connectioWasAlive = true;

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
int weatherUvi;
String Weather;
int temperatura;
int humedad;

void setup(){
  Serial.begin(115200);
  Wire.begin();

  //Display
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);             
  pinMode(LED_BUILTIN, OUTPUT);   

  Serial.println("Run");

  //WIFI
  WiFi.mode(WIFI_STA);
  //wifiMulti.addAP("Webcreek", "gosu2017");
  wifiMulti.addAP("GUARRODSTUDIO", "3libras#");
  Serial.println("Conectando");
  while (wifiMulti.run() != WL_CONNECTED) 
  {    
    delay(500);
    Serial.print('.');

    digitalWrite(LED_BUILTIN, LOW);  // Turn the LED off by making the voltage HIGH    
    display.drawBitmap(34, 2,  wifi, 60, 43, WHITE);  
    display.setCursor(35,50);               
    display.println("Conectando");
    display.display();
  }
 
  // Mostrar mensaje de exito, WiFI conectada y dirección IP asignada
  Serial.println();
  Serial.print("Conectado a:\t");
  Serial.println(WiFi.SSID());
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());
  display.clearDisplay();
  digitalWrite(LED_BUILTIN, HIGH);   // Turn the LED on (Note that LOW is the voltage level
  //Conexion a WIFI 

}



void loop () {
  if (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    delay(1000);
  }
  display.clearDisplay();

  display.setTextColor(WHITE);          // General to all the UI

  temperatura = SHT2x.GetTemperature();
  humedad = SHT2x.GetHumidity();

  Serial.print("Temperatura: ");
  Serial.print(SHT2x.GetTemperature());
  Serial.print("  Humedad:  ");
  Serial.println(SHT2x.GetHumidity());


  /////// INDOOR  ///////
  display.setFont(&Nimbus_Sans_L_10);
  display.setCursor(0,7);               
  display.println("Indoor");

  display.setFont(&Open_Sans_Condensed_Bold_20);
  display.setCursor(0,27);               
  display.println(temperatura); 
  display.drawCircle(23, 15, 2, WHITE);

  display.setCursor(35,27);
  display.println(humedad);
  display.drawBitmap(56, 11,  Drop, 8, 16, WHITE);              

  //display.println(SHT2x.GetDewPoint()); 
  //display.drawString(109, 25, "°C");

  /////// OUTDOOR  ///////
  display.setFont(&Nimbus_Sans_L_10);
  display.setCursor(0,41);               
  display.println("Outdoor");

  display.setFont(&Open_Sans_Condensed_Bold_20); 
  display.setCursor(0,60);      
  display.println(String(tempOut));
  display.drawCircle(23, 48, 2, WHITE);

  display.setFont(&Open_Sans_Condensed_Bold_20); 
  display.setCursor(35,60);               
  display.println(humOut);
  display.drawBitmap(56, 44,  Drop, 8, 16, WHITE);   

  display.setFont(&Open_Sans_Condensed_Bold_20); 
  display.setCursor(70,60);               
  display.println(weatherUvi);  

  display.setFont(&Nimbus_Sans_L_10);
  display.setCursor(93,60);               
  display.println("uV");


    if (Icon == "02d") {
    display.drawBitmap(75, 1,  FewCloudsDay, 35, 35, WHITE);   
  } else if (Icon == "01d") {
    display.drawBitmap(75, 1,  ClearDay, 35, 35, WHITE);  
  } else if (Icon == "01n") {
    display.drawBitmap(80, 1,  ClearNight, 35, 35, WHITE);  
  } else if (Icon == "10d") {
    display.drawBitmap(75, 1,  Rain, 35, 35, WHITE);  
  } else if (Icon == "50d" || Icon == "50n") {
    display.drawBitmap(75, 1,  Mist, 35, 35, WHITE);  
  } else if (Icon == "03d" || Icon == "03n") {
    display.drawBitmap(75, 1,  ScatteredClouds, 35, 35, WHITE);  
  } else{
    display.drawBitmap(75, 1,  NA, 35, 35, WHITE);  
    }

    if (counter == 60)    //Get new data every 10 minutes
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
  char json [result.length() + 1];
  result.toCharArray(json, sizeof(json));
  json[result.length() + 1] = '\0';
  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, json);

  if (error){
    Serial.println("parseObject() failed");
  }

  String location = doc["name"];
  String country = doc["sys"]["country"];
  float temperature = doc["main"]["temp"];
  float humidity = doc["main"]["humidity"];
  String weather = doc["weather"]["icon"];
  String description = doc["weather"]["description"];
  float pressure = doc["main"]["pressure"];
  String icon = doc["weather"]["icon"];
  Weather = weather;
  weatherDescription = description;
  weatherLocation = location;
  Country = country;
  Icon = weather;
  Temperature = temperature;
  tempOut = round(temperature);
  humOut = humidity;
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
  char json [result2.length() + 1];
  result2.toCharArray(json, sizeof(json));
  json[result2.length() + 1] = '\0';
  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, json);

  if (error){
    Serial.println("parseObject() failed");
  }


  float uvi = doc["value"];
  weatherUvi = uvi;


}

void displayWeather(String location, String description)
{

}

void displayConditions(float Temperature, float Humidity, float Pressure)
{

}

void displayGettingData()
{

}
