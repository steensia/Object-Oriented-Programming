/* This is the implementation code for the SimonPlayer class.

   Author: Steen Sia
   Last Updated: November 18, 2016
*/
#include "SimonPlayer.h"
#include "ColorSequence.h"

SimonPlayer::SimonPlayer(int _redButtonPin, int _greenButtonPin, int _yellowButtonPin, int _blueButtonPin, bool _debugMode) {
  redButtonPin = _redButtonPin;
  greenButtonPin = _greenButtonPin;
  yellowButtonPin = _yellowButtonPin;
  blueButtonPin = _blueButtonPin;
  debugMode = _debugMode;

  pinMode(redButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(yellowButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
}

void SimonPlayer::getResponses(ColorSequence& responses, int count) {
  for (int i = 0; i < count; i ++) {
    if (redButtonPin == LOW) {
      while (redButtonPin == LOW) {
      }
      responses.setColor(i, RED);
    }
    else if (greenButtonPin == LOW) {
      while (greenButtonPin == LOW) {
      }
      responses.setColor(i, GREEN);
    }
    else if (yellowButtonPin == LOW) {
      while (yellowButtonPin == LOW) {
      }
      responses.setColor(i, YELLOW);
    }
    else if (blueButtonPin == LOW) {
      while (blueButtonPin == LOW) {
      }
      responses.setColor(i, BLUE);
    }
    else {
      i--;
    }
  }
  if (debugMode) {
    responses.print(count);
  }
}

