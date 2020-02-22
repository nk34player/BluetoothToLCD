#include <TFT.h> // Hardware-specific library
#include <SPI.h>

#define CS   10
#define DC   9
#define RESET  8

// pin definition for the Leonardo
// #define CS   7
// #define DC   0
// #define RESET  1

TFT myScreen = TFT(CS, DC, RESET);
String data;
char sensorPrintout[40];
void setup() {
  Serial.begin(9600);
  myScreen.begin();
  myScreen.background(0, 0, 0); // clear the screen with black
  myScreen.stroke(140, 10, 100);
  myScreen.setTextSize(2);
  myScreen.setTextWrap(true);
  // write text to the screen in the top left corner
  myScreen.setRotation(3);

}

void loop() {
  while (Serial.available() == 0)
  {
    //myScreen.text("Trying", 10, 10);
  }

  delay(500);
  data = Serial.readString();
  myScreen.background(255, 0, 0);
  data.toCharArray(sensorPrintout, 40);
  myScreen.background(0, 0, 0); // clear the screen with black
  //  myScreen.text(Serial.readString(), 10, 10);
  //myScreen.print(data);
  myScreen.text(sensorPrintout, 10, 10);
}
