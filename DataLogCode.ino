
#include <SD.h>

#include <TinyGPS++.h>
#include <SoftwareSerial.h>

SoftwareSerial serial_connection(24, 25); // RX pin 24, TX pin 25


TinyGPSPlus gps;


void setup() {
   Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Start");
}

void loop() {

 while(serial_connection.available())
  {
    gps.encode(serial_connection.read());
  }
  if(gps.location.isUpdated())
  {

    Serial.print("Satellite Count:");
    Serial.println(gps.satellites.value());
    Serial.print("Latitude:");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude:");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Speed MPH:");
    Serial.println(gps.speed.mph());
    Serial.print("Altitude Feet:");
    Serial.println(gps.altitude.feet());
    Serial.println("");
  }

}
