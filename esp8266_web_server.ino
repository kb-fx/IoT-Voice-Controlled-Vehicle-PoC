#include <ESP8266WiFi.h>

const char* ssid = "ABCD";           // Replace with your Wi-Fi SSID
const char* password = "1234";   // Replace with your Wi-Fi password

WiFiServer server(80);

void setup() {
  Serial.begin(9600);  // Set baud rate to 9600
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to Wi-Fi");
  Serial.println("IP Address: " + WiFi.localIP().toString());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    while (client.connected() && !client.available()) {
      delay(1);
    }

    if (client.available()) {
      String request = client.readStringUntil('\r');
      client.flush();

      // Serve HTML content
      String response = "<!DOCTYPE HTML><html><head><title>ESP8266 Control</title>";
      response += "<style>";
      response += "body { font-family: Arial, sans-serif; text-align: center; margin: 0; padding: 0; background-color: #f0f0f0; }";
      response += ".button { padding: 15px; font-size: 24px; margin: 10px; border: none; border-radius: 5px; color: white; cursor: pointer; }";
      response += ".arrow { font-size: 30px; }";
      response += ".up { background-color: cyan; }";
      response += ".down { background-color: cyan; }";
      response += ".left { background-color: cyan; }";
      response += ".right { background-color: cyan; }";
      response += ".stop { background-color: red; }";
      response += ".follow { background-color: blue; }";
      response += ".spin { background-color: yellow; color: black; }";
      response += ".mic { background-color: black; color: red; font-weight: bold; }";
      response += "</style></head><body>";
      response += "<div><button class='button arrow up' onclick=\"sendCommand('up')\">&#8593;</button></div>";
      response += "<div><button class='button arrow left' onclick=\"sendCommand('left')\">&#8592;</button>";
      response += "<button class='button arrow right' onclick=\"sendCommand('right')\">&#8594;</button></div>";
      response += "<div><button class='button arrow down' onclick=\"sendCommand('down')\">&#8595;</button></div>";
      response += "<div><button class='button stop' onclick=\"sendCommand('stop')\">Stop</button></div>";
      response += "<div><button class='button follow' onclick=\"sendCommand('follow')\">Follow Me</button></div>";
      response += "<div><button class='button spin' onclick=\"sendCommand('spin')\">Spin</button></div>";
      response += "<div><button class='button mic' onclick=\"sendCommand('mic')\">MIC</button></div>";
      response += "<script>";
      response += "function sendCommand(command) {";
      response += "  var xhr = new XMLHttpRequest();";
      response += "  xhr.open('GET', '/' + command, true);";
      response += "  xhr.send();";
      response += "}";
      response += "</script></body></html>";

      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println("Connection: close");
      client.println();
      client.println(response);

      // Handle client request
      if (request.indexOf("/up") != -1) {
        Serial.println("UP command received");
        // Add code to handle "up" command
      } else if (request.indexOf("/down") != -1) {
        Serial.println("DOWN command received");
        // Add code to handle "down" command
      } else if (request.indexOf("/left") != -1) {
        Serial.println("LEFT command received");
        // Add code to handle "left" command
      } else if (request.indexOf("/right") != -1) {
        Serial.println("RIGHT command received");
        // Add code to handle "right" command
      } else if (request.indexOf("/stop") != -1) {
        Serial.println("STOP command received");
        // Add code to handle "stop" command
      } else if (request.indexOf("/follow") != -1) {
        Serial.println("FOLLOW command received");
        // Add code to handle "follow" command
      } else if (request.indexOf("/spin") != -1) {
        Serial.println("SPIN command received");
        // Add code to handle "spin" command
      } else if (request.indexOf("/mic") != -1) {
        Serial.println("MIC command received");
        // Add code to handle "mic" command
      }
    }
  }
}
