#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include <string>

class Dealer : public Player
{
public:
	Dealer();
	void showOne();
};

#endif 

/*
switch (choice)	{

case 1:{
player.addCard(deck->selectCard(cardCounter));
cardCounter++;
game.gameInfo(player, dealer, currentBet);
if (game.whoWin(player, dealer) == (-2)) {
game.gameSummary(player, dealer, currentBet);
cout << endl << "Dealer won" << endl << "You lost " << currentBet << endl << "Current cash: " << player.getCash() << endl;
cout << endl << "#NEW GAME#" << endl;
currentBet = game.makeBet(player);
game.newDeal(deck, player, dealer, cardCounter, currentBet);
}
else if (game.whoWin(player, dealer) == 2) {
game.gameSummary(player, dealer, currentBet);
player.addCash(currentBet * 3);
cout << endl << "Dealer lost" << endl << "You win " << currentBet * 3 << endl << "Current cash: " << player.getCash() << endl;
cout << endl <<"#NEW GAME#" << endl;
currentBet = game.makeBet(player);
game.newDeal(deck, player, dealer, cardCounter, currentBet);
}
}break;

case 2:{
game.gameSummary(player, dealer, currentBet);
if (game.whoWin(player, dealer) == 1){
player.addCash(currentBet * 2);
cout << endl << "Winner!" << endl << "You win " << currentBet * 2 << endl << "Current cash: " << player.getCash() << endl;
cout << endl << "#NEW GAME#" << endl;
currentBet = game.makeBet(player);
game.newDeal(deck, player, dealer, cardCounter, currentBet);
}

else if (game.whoWin(player, dealer) == 0){
player.addCash(currentBet);
cout << endl << "Tie!" << endl << "Current cash: " << player.getCash() << endl;
cout << endl << "#NEW GAME#" << endl;
currentBet = game.makeBet(player);
game.newDeal(deck, player, dealer, cardCounter, currentBet);
}

else if (game.whoWin(player, dealer) == (-1)){
cout << endl << "Dealer won" << endl << "You lost " << currentBet << endl << "Current cash: " << player.getCash() << endl;
cout << endl << "#NEW GAME#" << endl;
currentBet = game.makeBet(player);
game.newDeal(deck, player, dealer, cardCounter, currentBet);
}

else if (game.whoWin(player, dealer) == 3) {
game.gameSummary(player, dealer, currentBet);
player.addCash(currentBet * 3);
cout << endl << "BlackJack!" << endl << "You win " << currentBet * 3 << endl << "Current cash: " << player.getCash() << endl;
cout << endl << "#NEW GAME#" << endl;
currentBet = game.makeBet(player);
game.newDeal(deck, player, dealer, cardCounter, currentBet);
}

}break;

}
}
*/