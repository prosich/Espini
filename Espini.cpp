#include "Arduino.h" // no necesario
#include "Espini.h"

Espini::Espini(WifiAPEntry wifis[], int wsc,
               char *app,  char *ver, 
               char *otas, char *logs) {

  Serial.begin(74880);

  ESP8266WiFiMulti wifiMulti;
  for(int i=0; i<=wsc; i++) 
    wifiMulti.addAP(wifis[i].ssid,wifis[i].passphrase);

  snprintf(chipId,sizeof(chipId),"%u",ESP.getChipId());

  syslog=new Syslog(udp,otas,514,chipId,app,LOG_INFO);

  WiFi.mode(WIFI_STA);
  Serial.println(WiFi.macAddress()+" conectando a wifi");
  
  while (true) {
    for (int segs=1; segs<=15; segs++) {
      if (wifiMulti.run() == WL_CONNECTED) {
        Serial.println(WiFi.localIP()); 
        ESPhttpUpdate.update("ota.rosich.es",80,
          "/cgi/ota?ser="+(String)ESP.getChipId()+"&app="+app+"&ver="+ver);
      }
      delay(1000);
    }
    delay(60e3);
  }
}

char *Espini::getchipid()    {return(chipId);}

void  Espini::log(char *msg) {syslog->log(msg);}


