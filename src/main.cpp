#include <Arduino.h>
#include <BleKeyboard.h>
#include <OneButton.h>

OneButton BTN_1(13, true, true);
OneButton BTN_2(4, true, true);
OneButton BTN_3(33, true, true);
OneButton BTN_4(18, true, true);
OneButton BTN_5(32, true, true);
OneButton BTN_6(21, true, true);

BleKeyboard blekeyboard("Macro Keyboard", "Espressif", 100);

void BTN_1_CLICK() {
  // You can specify certain function here
}

void BTN_2_CLICK() {
  // You can specify certain function here
}

// Git Add and Git Commit
void BTN_3_CLICK() {
  blekeyboard.println("git add .");
  delay(500);
  blekeyboard.print("git commit -m \"\"");
  blekeyboard.write(KEY_LEFT_ARROW);

}

void BTN_4_CLICK() {
  // You can specify certain function here
}

// Mute/Unmute Google Meet
void BTN_5_CLICK() {
  blekeyboard.press(KEY_LEFT_CTRL);
  blekeyboard.press(0x64);
  delay(100);
  blekeyboard.releaseAll();
}

// Switch Camera On/Off Google Meet
void BTN_6_CLICK() {
  blekeyboard.press(KEY_LEFT_CTRL);
  blekeyboard.press(0x65);
  delay(100);
  blekeyboard.releaseAll();
}

void setup() {
  blekeyboard.begin();

  BTN_1.attachClick(BTN_1_CLICK);
  BTN_2.attachClick(BTN_2_CLICK);
  BTN_3.attachClick(BTN_3_CLICK);
  BTN_4.attachClick(BTN_4_CLICK);
  BTN_5.attachClick(BTN_5_CLICK);
  BTN_6.attachClick(BTN_6_CLICK);
}

void loop() {
  if(blekeyboard.isConnected()) {
    BTN_1.tick();
    BTN_2.tick();
    BTN_3.tick();
    BTN_4.tick();
    BTN_5.tick();
    BTN_6.tick();
  }
}