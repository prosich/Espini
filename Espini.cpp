#include "Espini.h"

Espini::Espini(ESP8266WiFiMulti wifis, 
               const char *app,  const char *ver, 
               const char *otas, const char *logs) {

  Serial.begin(74880);

  snprintf(chipId,sizeof(chipId),"%u",ESP.getChipId());

  syslog=new Syslog(udp,logs,514,chipId,app,LOG_INFO);

  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.macAddress()+" conectando a wifi");
  
  while (true) {
    for (int segs=1; segs<=15; segs++) {
      if (wifis.run() == WL_CONNECTED) {
        Serial.println(WiFi.localIP()); 
	WiFiClient client;
        ESPhttpUpdate.update(client,otas,80,
          "/espota?ser="+String(chipId)+"&app="+app+"&ver="+ver);
	return;
      }
      delay(1000);
    }
    delay(60e3);
  }
}

char *Espini::getchipid()    {return(chipId);}

void  Espini::log(const char *msg) {syslog->log(msg);}


