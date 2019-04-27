/* This is the header file for the SimonGame class.
   A SimonGame object is a single instance of play for the Simon game
   https://en.wikipedia.org/wiki/Simon_(game).

   Author: Erin Parker
   Last Updated: November 11, 2016
*/

#include "Arduino.h"
#include "ColorSequence.h"

class SimonGame {

  private:

    // Four pins, one for each colored LED
    int redLEDpin;
    int greenLEDpin;
    int yellowLEDpin;
    int blueLEDpin;

    ColorSequence colorsToDisplay;   // "list" of random colors
    int roundNum;                    // how many colors to show
    int displaySpeed;                // pause between each color displayed (will be adjustable in Part 2)
    bool debugMode;                  // set to true to print status info
    bool gameOn;                     // set to false when game is over / lost

  public:

    /* Creates a SimonGame object.

       Parameters: int _redLEDpin - pin number for the red LED
                   int _greenLEDpin - pin number for the green LED
                   int _yellowLEDpin - pin number for the yellow LED
                   int _blueLEDpin - pin number for the blue LED
                   bool _debugMode - indication of whether to print status info
    */
    SimonGame(int _redLEDpin, int _greenLEDpin, int _yellowLEDpin, int _blueLEDpin, bool _debugMode);

    /* Displays the color sequence of this round of play by lighting the LEDs.

       Parameters: none
       Return: none
    */
    void displayColors();

    /* Gets the number of rounds of play so far in the game.
       (Same as the number of colors to display in this round.)

       Parameters: none
       Return: int - the round number
    */
    int getRoundNumber();

    /* Advances play to the next round by incrementing the
       round number.

       Parameters: none
       Return: none
    */
    void nextRound();
    /* Checks that the color sequence entered by the user matches the
      colors display (through this round).
      Play continues if the colors match, otherwise the game is over.

      Parameters: ColorSequence responses - the user's "list" of colors
    */
    void verifyResponses(ColorSequence responses);

    /* Indicates whehter the game is over or in active play.

       Parameters: none
       Return: bool - true if the game is over, false otherwise
    */
    bool isGameOver();
};
