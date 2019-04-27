/* This is the implementation code for the SimonGame class.

  Author: Steen Sia
  Last Updated: November 18, 2016
*/

#include "SimonGame.h"
#include "ColorSequence.h"

SimonGame::SimonGame(int _redLEDpin, int _greenLEDpin, int _yellowLEDpin, int _blueLEDpin, bool _debugMode) {
  redLEDpin = _redLEDpin;
  greenLEDpin = _greenLEDpin;
  yellowLEDpin = _yellowLEDpin;
  blueLEDpin = _blueLEDpin;
  debugMode = _debugMode;

  pinMode(redLEDpin, OUTPUT);
  pinMode(greenLEDpin, OUTPUT);
  pinMode(yellowLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);

  if (debugMode) {
    srand(7);
  }

  roundNum = 1;
  displaySpeed = 1000;
  gameOn = true;

  colorsToDisplay.randomFill();

}

void SimonGame::displayColors() {

  if (debugMode) {
    Serial.print("Round ");
    Serial.print(roundNum);
    Serial.print(" colors to display: ");
    colorsToDisplay.print(roundNum);
  }
  for (int i = 0; i < roundNum; i++) {

    if (colorsToDisplay.getColor(i) == RED) {
      digitalWrite(redLEDpin, HIGH);
      delay(displaySpeed);
      digitalWrite(redLEDpin, LOW);
      delay(200);
    }
    else if (colorsToDisplay.getColor(i) == GREEN) {
      digitalWrite(greenLEDpin, HIGH);
      delay(displaySpeed);
      digitalWrite(greenLEDpin, LOW);
      delay(200);
    }
    else if (colorsToDisplay.getColor(i) == YELLOW) {
      digitalWrite(yellowLEDpin, HIGH);
      delay(displaySpeed);
      digitalWrite(yellowLEDpin, LOW);
      delay(200);
    }
    else if (colorsToDisplay.getColor(i) == BLUE) {
      digitalWrite(blueLEDpin, HIGH);
      delay(displaySpeed);
      digitalWrite(blueLEDpin, LOW);
      delay(200);
    }
  }
}

int SimonGame::getRoundNumber() {
  return roundNum;
}

void SimonGame::nextRound() {
  roundNum++;
}
void verifyResponses(ColorSequence responses){
}


