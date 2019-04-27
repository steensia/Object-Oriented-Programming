/* This is the header file for the ColorSequence class.
   A ColorSequence object is a list of colors (choosing from red, green, yellow, blue).

   A ColorSequence object is used by SimonGame to store the random sequence of colors
   to display via LEDs. Another ColorSequence object is used by SimonPlayer to store
   the sequence of button presses (each associated with a color) given as the
   "answer" or "response" in each round of the game.

   Author: Erin Parker
   Last Updated: November 11, 2016

   Use, but DO NOT MODIFY any part of this class for Programming Assignment 11.
*/

// These macros prevent the compiler from reading the class definition twice,
// even though both SimonGame and SimonPlayer include "ColorSequence.h".
#ifndef COLORSEQUENCE_H
#define COLORSEQUENCE_H

#include "Arduino.h"

// Global constants for color values -- use these names instead of integers in
// your code to make it easier to read.
const int RED = 0;
const int GREEN = 1;
const int YELLOW = 2;
const int BLUE = 3;

class ColorSequence {

  private:

    // NOTE: No Simon game is expected to go more than 100 rounds.
    // But, if it does, the color sequence cycles back to reuse the first 0-99 colors.
    const static int SIZE = 100;
    int colors[SIZE];    // the "list" of colors

  public:

    /* Constructs a ColorSequence object.

       Parameters: none
    */
    ColorSequence();

    /* Randomly fills the "list" of colors.

       Parameters: none
       Return: none
    */
    void randomFill();

    /* Gets the individual color from the "list", at the given index.
       Indexes start at 0.

       Parameter: int index - the position of color to be returned
       Return: int - the individual color at index
    */
    int getColor(int index);

    /* Sets the individual color in the "list", at the given index,
       with the given color.

       Parameters: int index - the position of color to be set / assigned
                   int color - the color value to assign
       Return: none
    */
    void setColor(int index, int color);

    /* Prints a textual representation of the ColorSequence object to the
       Serial monitor. Used for debugging purposes.

       Parameters: int limit - how many colors to print
                               (i.e., index at which to stop printing)
       Return: none
    */
    void print(int limit);

    /* Determines whether two ColorSequence objects are the same
       (i.e., each "list" has the same color values at each index).

       Parameters: ColorSequence other - the second object to compare
                   int limit - how many colors to check for equality
                               (i.e., index at which to stop comparing)
       Return: bool - true if colors at indexes 0 to limit-1 are the same
    */
    bool equals(ColorSequence other, int limit);
};

#endif
