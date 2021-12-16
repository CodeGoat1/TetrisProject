#include <Wire.h>
#include "Adafruit_MCP23008.h"

// Basic toggle test for i/o expansion. flips pin #0 of a MCP23008 i2c
// pin expander up and down. Public domain

// Connect pin #1 of the expander to Analog 5 (i2c clock)
// Connect pin #2 of the expander to Analog 4 (i2c data)
// Connect pins #3, 4 and 5 of the expander to ground (address selection)
// Connect pin #6 and 18 of the expander to 5V (power and reset disable)
// Connect pin #9 of the expander to ground (common ground)

// Output #0 is on pin 10 so connect an LED or whatever from that to ground

Adafruit_MCP23008 mcp1;
Adafruit_MCP23008 mcp2;
Adafruit_MCP23008 mcp3;
Adafruit_MCP23008 mcp4;
Adafruit_MCP23008 mcp5;
Adafruit_MCP23008 mcp6;
Adafruit_MCP23008 mcp7;
  
void setup() {
  mcp1.begin(0);  
  mcp2.begin(2);
  mcp3.begin(3);
  mcp4.begin(4);
  mcp5.begin(5);
  mcp6.begin(6);
  mcp7.begin(7);

  mcp1.pinMode(0, OUTPUT);
  mcp1.pinMode(1, OUTPUT);
  mcp1.pinMode(2, OUTPUT);
  mcp1.pinMode(3, OUTPUT);
  mcp1.pinMode(4, OUTPUT);
  
  mcp2.pinMode(0, OUTPUT);
  mcp2.pinMode(1, OUTPUT);
  mcp2.pinMode(2, OUTPUT);
  mcp2.pinMode(3, OUTPUT);
  mcp2.pinMode(4, OUTPUT);
  
  mcp3.pinMode(0, OUTPUT);
  mcp3.pinMode(1, OUTPUT);
  mcp3.pinMode(2, OUTPUT);
  mcp3.pinMode(3, OUTPUT);
  mcp3.pinMode(4, OUTPUT);

  mcp4.pinMode(0, OUTPUT);
  mcp4.pinMode(1, OUTPUT);
  mcp4.pinMode(2, OUTPUT);
  mcp4.pinMode(3, OUTPUT);
  mcp4.pinMode(4, OUTPUT);

  mcp5.pinMode(0, OUTPUT);
  mcp5.pinMode(1, OUTPUT);
  mcp5.pinMode(2, OUTPUT);
  mcp5.pinMode(3, OUTPUT);
  mcp5.pinMode(4, OUTPUT);

  mcp6.pinMode(0, OUTPUT);
  mcp6.pinMode(1, OUTPUT);
  mcp6.pinMode(2, OUTPUT);
  mcp6.pinMode(3, OUTPUT);
  mcp6.pinMode(4, OUTPUT);

  mcp7.pinMode(0, OUTPUT);
  mcp7.pinMode(1, OUTPUT);
  mcp7.pinMode(2, OUTPUT);
  mcp7.pinMode(3, OUTPUT);
  mcp7.pinMode(4, OUTPUT);
}


// flip the pin #0 up and down

void loop() { 

  for(int x = 0; x < 5; x++) {
  mcp7.digitalWrite(x, HIGH);
  delay(100);
  mcp7.digitalWrite(x, LOW);
  delay(100);
  mcp6.digitalWrite(x, HIGH);
  delay(100);
  mcp6.digitalWrite(x, LOW);
  delay(100);
  mcp5.digitalWrite(x, HIGH);
  delay(100);
  mcp5.digitalWrite(x, LOW);
  delay(100);
  mcp4.digitalWrite(x, HIGH);
  delay(100);
  mcp4.digitalWrite(x, LOW);
  delay(100);
  mcp3.digitalWrite(x, HIGH);
  delay(100);
  mcp3.digitalWrite(x, LOW);
  delay(100);
  mcp2.digitalWrite(x, HIGH);
  delay(100);
  mcp2.digitalWrite(x, LOW);
  delay(100);
  mcp1.digitalWrite(x, HIGH);
  delay(100);
  mcp1.digitalWrite(x, LOW);
  delay(100);
  }

}
