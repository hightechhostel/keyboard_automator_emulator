#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  Serial1.begin(9600);
  Serial1.println("S2S-Keyboard-Emu-0.1 started");
}

void loop() {
  if (Serial1.available()) {
    Keyboard.print((char)Serial1.read());
  }
}
