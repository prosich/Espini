ESP8266WiFiMulti wm;

ESP8266WiFiMulti wifis() {

  wm.addAP("LGG3","xxxxx");
  wm.addAP("RMUP","xxxxx");

  return(wm);
  }

