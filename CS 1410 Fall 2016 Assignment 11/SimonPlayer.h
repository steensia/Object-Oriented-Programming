/* This is the header file for the SimonPlayer class.

   Author: Steen Sia
   Last Updated: November 18, 2016
*/

#include "Arduino.h"
#include "ColorSequence.h"

class SimonPlayer {

  private:
    int redButtonPin;
    int greenButtonPin;
    int yellowButtonPin;
    int blueButtonPin;
    bool debugMode;

  public:
    /* Creates a SimonPlayer object.

       Parameters: int _redButtonPin - pin number for the red LED's pushbutton
                   int _greenButtonPin - pin number for the green LED's pushbutton
                   int _yellowButtonPin - pin number for the yellow LED's pushbutton
                   int _blueButtonPin - pin number for the blue LED's pushbutton
                   bool _debugMode - indication of whether to print status info
    */
    SimonPlayer(int _redButtonPin, int _greenButtonPin, int _yellowButtonPin, int _blueButtonPin, bool _debugMode);

    /*The function detects the buttons pressed by the user in response to the
      color sequence displayed via the LEDs.

       Parameters: ColorSequence& responses -
                   int count -
       Return: none
    */
    void getResponses(ColorSequence& responses, int count);


};

