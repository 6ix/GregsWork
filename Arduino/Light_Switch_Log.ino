
//ESP 8266
//NODE J6
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClientSecure.h>

static const char ssid[] = "SSRAC";
static const char pass[] = "password";
static const char host[] = "docs.google.com";

//standard hdd port for info
ESP8266WebServer server(80);
WiFiClientSecure client;


//---------------------
//usingmy link
void pushData(unsigned int status) {
  client.setInsecure();
  Serial.println("Connecting to Google Docs...");
   if (client.connect(host, 443) == false)  //443 is secure ssl port
  {
    Serial.println("---CONNECTION FAILED---");
  }
  else 
  {
    client.print(String("GET /forms/d/e/1FAIpQLSeGrvdZ3Yg2xKyprN0iCt0NqfPy_mubjEqqMO3qQT8eHtDdCQ/formResponse?entry.1209698214=DATA-RECEIVED&entry.1260539806=") + 
                        String(status) + 
                        " HTTP/1.1\r\n" +
                        "Host: " + 
                        host + "\r\n" + 
                        "Connection: close\r\n\r\n");
    Serial.println("---REQUEST SENT---");
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
}

//----------------

String content() {
  String http = "<html>";
  http += "<title> IoT WebServer </title>";
  http += "<h1> ON - OFF SWITCH </h1>";
  http += "<a href= \"/on\"><button>ON</button></a>";
  http += "<a href= \"/off\"><button>OFF</button></a>";
  if (digitalRead(D4) == LOW)
    http += "<div><font color=green> LED ON</font></div>";
  else
    http += "<div><font color=red> LED OFF</font></div>";
  http += "</html>";


  return http;
}

void handlerRoot() {
  // 200 = ok, format, content
  //reply
  server.send(200, "text/html", content());
}

void handlerOn() {
  digitalWrite(D4, LOW);
  server.send(200, "text/html", content());
  pushData(1);
}

void handlerOff() {
  digitalWrite(D4, HIGH);
  server.send(200, "text/html", content());
   pushData(0);
}

void setup() {
  Serial.begin(115200);
  pinMode(D4, OUTPUT);

  //initialise wifi cinnection
  WiFi.begin(ssid, pass);
  Serial.print("Connecting");

  //checking if connected
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  //printing ip address
  Serial.println("");
  Serial.print("Connected to IP Address: ");
  Serial.println(WiFi.localIP());

  //when request comes in on root dir
  server.on("/", handlerRoot);
  server.on("/on", handlerOn);
  server.on("/off", handlerOff);
  server.begin();
}
 

void loop() 
{
  server.handleClient();

}
