#include "Espini.h"

Espini::Espini(ESP8266WiFiMulti wifis, 
               char *app,  char *ver, 
               char *otas, char *logs) {

  Serial.begin(74880);

  snprintf(chipId,sizeof(chipId),"%u",ESP.getChipId());

  syslog=new Syslog(udp,otas,514,chipId,app,LOG_INFO);

  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.macAddress()+" conectando a wifi");
  
  while (true) {
    for (int segs=1; segs<=15; segs++) {
      if (wifis.run() == WL_CONNECTED) {
        Serial.println(WiFi.localIP()); 
        ESPhttpUpdate.update("ota.rosich.es",80,
          "/cgi/ota?ser="+String(chipId)+"&app="+app+"&ver="+ver);
		return;
      }
      delay(1000);
    }
    delay(60e3);
  }
}

char *Espini::getchipid()    {return(chipId);}

void  Espini::log(char *msg) {syslog->log(msg);}


