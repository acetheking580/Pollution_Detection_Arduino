#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
const int ldr_pin = 7;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(1000);
  display.clearDisplay();
pinMode(A0,INPUT);
Serial.begin(9600);
pinMode(ldr_pin,INPUT);
display.clearDisplay();
display.clearDisplay();
display.clearDisplay();
display.display();
display.println("PHYSC!");
display.display();
display.clearDisplay();
}

void loop() {
// ------------------------------------------------------------------------------

int a=analogRead(A0);
int percentage=map(a,100,950,0,100);

int x = digitalRead(ldr_pin);
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0,0);
display.println("Pollution level");               //print title
  display.println("      ");                       //skip a line
  display.print(a);
  display.print("  PPM");
display.display();

Serial.print("AirQuality=");
  Serial.print(a);  
  Serial.println(" PPM");
  delay(10);
display.display();
delay(3000);
}
