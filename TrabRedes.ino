#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

char auth[] = "token"; //Auth code sent via Email
char ssid[] = "Wifi"; //Wifi name
char pass[] = "0123456789";  //Wifi Password

void notifyBaby()
{
  int isButtonPressed = digitalRead(D2);
  if (isButtonPressed != 4) {
    Serial.println("Bebê Acordado!!!");
    Blynk.notify("Bebê Acordado!!!");
  }
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(D2,INPUT);
  timer.setInterval(1000L,notifyBaby); 
}
void loop()
{
  Blynk.run();
  timer.run();
}
