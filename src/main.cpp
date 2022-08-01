#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard blekeyboard;

void setup() {
  Serial.begin(115200);
  blekeyboard.begin();
  Serial.print("Starting BLE Work!");
}

void loop() {
  if(blekeyboard.isConnected()){
    Serial.println("Sending 'Hello World!");
    blekeyboard.print("Hello World");
    delay(1000);

    Serial.println("Sending Enter key");
    blekeyboard.press(KEY_LEFT_CTRL);
    blekeyboard.press(0x61);
    delay(100);
    blekeyboard.releaseAll();
    blekeyboard.write(KEY_BACKSPACE);
    blekeyboard.end();
    delay(1000);

    Serial.println("Waiting 5 seconds...");
  }
}