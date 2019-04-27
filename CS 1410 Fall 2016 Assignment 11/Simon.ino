/* This Arduino sketch runs a game of Simon.
 * https://en.wikipedia.org/wiki/Simon_(game)
 * 
 * Author: Erin Parker
 * Last updated: November 11, 2016
 */

#include "SimonGame.h"
#include "SimonPlayer.h"

SimonGame game(7, 6, 5, 4, true);
SimonPlayer player(11, 10, 9, 8, true);

void setup() {
  Serial.begin(9600);  
}

void loop() {

  if(game.isGameOver()) {
    Serial.println("GAME OVER"); 
  }
  else {
    // Show the color sequence (light the LEDs) that player must match.
    game.displayColors();
  
    // (Player must wait for entire color sequence to display before pressing buttons as responses.)
    // Collect button responses from the player and store in a ColorSequence object passed by reference.
    ColorSequence answer;
    player.getResponses(answer, game.getRoundNumber());

    // Check if the player's responses match the color pattern displayed.
    game.verifyResponses(answer);

    // Go to next round of play.
    game.nextRound();
  }

  // Pause briefly between rounds.
  delay(2000);   
}
