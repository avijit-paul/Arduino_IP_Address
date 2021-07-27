// partialy taken from Arduino Library example
//Initialize header files
#include <WiFi.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

//Declearing the variables for Wifi username and password
const char* ssid  = "Enter_your_WiFi_name";
const char* password = "Enter_your_WiFi_password";

//Resetting the display 
#define OLED_RESET 0 //GPIO0
Adafruit_SSD1306 display(OLED_RESET);

//Fixing the display
#if (SSD1306_LCDHEIGHT != 48)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

//Setup code
void setup() {
  Serial.begin(115200);
  delay (500);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500); //in miliseconds
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");
  Serial.print("IP address: \t");
  Serial.println(WiFi.localIP());
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  //delay(500);

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello \n");
  display.println(WiFi.localIP());

  display.display();
  delay(2000);
  display.clearDisplay();
}

// Loop control(if necessary)
void loop() {

}
