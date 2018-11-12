/* 
  Espini.h

  Combina todas las operaciones de inicio necesarias en el NodeMCU.

     Inicia consola a 74880 (concidente con arranque NodeMCU)
     Conecta a WiFi.
     Actualiza soft. si es necesario.
     Configura syslog remoto.

  Precisa de un servidor OTA que entienda lo que se le pide
  (debe haber algun ejemplo por aqui cerca).

  Precisa de servidor Syslog.

  Depende de libs. externas:
     https://github.com/arcao/Syslog
*/

#ifndef Espini_h
#define Espini_h

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <Syslog.h>

class Espini {
  private:
    char    chipId[20];
    WiFiUDP udp;
    Syslog  *syslog;
  public:
    Espini(ESP8266WiFiMulti wifis, 
           const char *app, const char *ver, 
           const char *otas, const char *logs);
    char   *getchipid();
    void   log(const char *msg);
};

#endif

