#include <TinyGPS++.h>
#include <SoftwareSerial.h>


SoftwareSerial gpsSerial(8,9);
TinyGPSPlus gps;

float latitud,longitud;

void setup() {
  gpsSerial.begin(9600);
  Serial.begin(9600);

}

void loop() {
  while (gpsSerial.available()){
    int data = gpsSerial.read();
    if(gps.encode(data)){
      latitud = (gps.location.lat());
      longitud = (gps.location.lng());
      Serial.print("Latitud: ");
      Serial.print(latitud);
      Serial.print("Longitud");
      Serial.print(longitud);
    }
  }

}
