/* This is the source code file for the ColorSequence class.
   A ColorSequence object is a list of colors (choosing from red, green, yellow, blue).

   A ColorSequence object is used by SimonGame to store the random sequence of colors
   to display via LEDs. Another ColorSequence object is used by SimonPlayer to store
   the sequence of button presses (each associated with a color) given as the
   "answer" or "response" in each round of the game.

   Author: Erin Parker
   Last Updated: November 11, 2016

   Use, but DO NOT MODIFY any part of this class for Programming Assignment 11.
*/

#include "ColorSequence.h"

ColorSequence::ColorSequence() {
  // (purposely does nothing)
}

void ColorSequence::randomFill() {
  for (int i = 0; i < SIZE; i++) {
    colors[i] = rand() % 4;
  }
}

int ColorSequence::getColor(int index) {
  return colors[index] % SIZE;
}

void ColorSequence::setColor(int index, int color) {
  colors[index % SIZE] = color;
}

void ColorSequence::print(int limit) {
  for (int i = 0; i < limit; i++) {
    String colorName = "";
    switch (colors[i]) {
      case (RED):
        Serial.print("red ");
        break;
      case (GREEN):
        Serial.print("green ");
        break;
      case (YELLOW):
        Serial.print("yellow ");
        break;
      case (BLUE):
        Serial.print("blue ");
        break;
      default:
        Serial.print("error ");
    }
  }
  Serial.println();
}

bool ColorSequence::equals(ColorSequence other, int limit) {
  for (int i = 0; i < limit; i++) {
    if (colors[i] != other.getColor(i)) {
      return false;
    }
  }
  return true;
}
