//#include "SimonGame.h"
//#include "SimonPlayer.h"
//
//SimonGame game(7, 6, 5, 4, true);
//SimonPlayer player(11, 10, 9, 8, true);
//
//void setup() {
//  Serial.begin(9600);
//}
//
//void loop() {
//  // Show the color sequence (light the LEDs) that player must match.
//  game.displayColors();
//
//  // (Player must wait for entire color sequence to display before pressing buttons as responses.)
//  // Collect button responses from the player and store in a ColorSequence object passed by reference.
//  ColorSequence answer;
//  player.getResponses(answer, game.getRoundNumber());
//
//  // Go to next round of play.
//  game.nextRound();
//}
