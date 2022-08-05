# BLE Macro Keyboard

### About this project

- The goals of this project is to make a macro keyboard that can simply our life by pressing some button combination or typing something.
- This project use ESP32 Development board that have bluetooth capability.
- The main source of this code is using [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) library. So better you check the documentation from that library.
- Also for the button I use [OneButton](https://github.com/mathertel/OneButton) library to simply debounce the button. You can also add certain function like double click, long press, and multiple click by using this library.

### Note

Because this macro keyboard is using BLE as a communication to the computer, we need to pay attention to the delay. Unless some character will be missing.
Example:

Instead of doing this

```CPP
void BTN_4_CLICK() {
	blekeyboard.println("GciOiJIUzI1NijM0NTY3ODkwIiwibmFtZSI6Ikpv");
 	delay(100);
  	blekeyboard.write(KEY_RETURN);
}
```

You can separate the text and add `delay()` between the text like this

```CPP
void BTN_4_CLICK() {
	blekeyboard.print("GciOiJIUzI");
	delay(100);
	blekeyboard.print("1NijM0NTY3");
	delay(100);
	blekeyboard.print("ODkwIiwibm");
	delay(100);
	blekeyboard.println("FtZSI6Ikpv");
	delay(100);
	blekeyboard.write(KEY_RETURN);
}
```

You can change the `delay()` as you need. Previously I use 50 miliseconds delay and sometimes the text is missing some characters, so I add the delay to 100 miliseconds, and it works well for me.
