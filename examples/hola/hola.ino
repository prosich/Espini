#include <Espini.h>

void setup() { 
  Espini cosa(wifis(),"test","10","ota.rosich.es","syslog.rosich.es");
  cosa.log("Hola 10!");
  delay(300e3);
  ESP.reset();
}

void loop() {
}


