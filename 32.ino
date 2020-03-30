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
       //dia y hora

    int ano;
    byte mes, dia, hora, minuto, segundo, centesimo;
    gps.crack_datetime(&ano, &mes, &dia, &hora, &minuto, &segundo, &centesimo);

    Serial.print("Datos (GMT): ");
    Serial.print(dia);
    Serial.print("/");
    Serial.print(mes);
    Serial.print("/");
    Serial.print(ano);

    Serial.print("Horario: ");
    Serial.print(hora);
    Serial.print(":");
    Serial.print(minuto);
    Serial.print(":");
    Serial.print(segundo);
    Serial.print(":");
    Serial.print(centesimo);

    }
  }

}
