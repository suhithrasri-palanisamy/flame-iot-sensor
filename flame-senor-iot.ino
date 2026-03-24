#include "thingProperties.h"
#define LED_PIN 26 // G26
#define FLAME_PIN 27 // G27

void setup() {
Serial.begin(9600);
delay(1500);

pinMode(LED_PIN, OUTPUT);
pinMode(FLAME_PIN, INPUT);

initProperties();
ArduinoCloud.begin(ArduinoIoTPreferredConnection);
// 
setDebugMessageLevel(2);
ArduinoCloud.printDebugInfo();
}

void loop() {
ArduinoCloud.update();

int flameValue = digitalRead(FLAME_PIN);

if (flameValue == LOW) { // Flame detected
digitalWrite(LED_PIN, HIGH);
Serial.println("🔥 Flame Detected - LED ON");
  flame="🔥 Flame Detected - LED ON";
} else {
digitalWrite(LED_PIN, LOW);
Serial.println("No Flame - LED OFF");
  flame="No Flame - LED OFF";
}

delay(1000);
}

/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/



/*
  Since Flame is READ_WRITE variable, onFlameChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onFlameChange()  {
  // Add your code here to act upon Flame change
}
/*
  Since Led is READ_WRITE variable, onLedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLedChange()  {
  // Add your code here to act upon Led change
}