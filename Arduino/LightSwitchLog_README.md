ESP8266 Web Server for Controlling an LED
This is an Arduino sketch for the ESP8266 WiFi module that creates a web server to control an LED connected to the device. 
The web page allows the user to turn the LED on and off using an ON-OFF switch.

Prerequisites
To use this sketch, you will need:

An ESP8266-based development board
Arduino IDE installed on your computer
The following libraries installed in the Arduino IDE:
ESP8266WiFi
ESP8266WebServer
WiFiClientSecure

How to Use
Connect the LED to the ESP8266 development board according to the schematic.
Open the sketch in the Arduino IDE.
Modify the network credentials (ssid and pass) and the Google Docs server domain name (host) to match your network configuration.
Compile and upload the sketch to the ESP8266 development board.
Open a web browser and navigate to the IP address of the ESP8266 development board to access the web page.
Use the ON-OFF switch on the web page to control the LED.

License
This code is released under the MIT License.
https://opensource.org/license/mit/
