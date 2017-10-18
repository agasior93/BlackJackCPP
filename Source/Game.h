#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"
using namespace std;

class Game
{
public:
	//void newGame(Deck*, Player&, Dealer&, int, float);
	void newDeal(Deck*, Player&, Dealer&, int&, float&);
	float makeBet(Player&);
	void dealerPlay(Deck*, Dealer&, int);
	void gameInfo(Player&, Dealer&, float&);	
	void gameSummary(Player&, Dealer&, float&);
	int whoWin(Player&, Dealer&);
	bool winner(Player&, Dealer&, float&);
	bool winInFirst(Player&, Dealer&, float&);
};

#endif

/*
void Game::newGame(Deck *deck, Player &player, Dealer &dealer, int cardCounter, float bet)
{
player.setCash();
newDeal(deck, player, dealer, cardCounter, bet);
}
*/
/*
int Game::whoWin(Player &player, Dealer &dealer){
	if (player.getHandValue() > 21) return -2; // przegrana -bet
	else if (dealer.getHandValue() > 21) return 2; // przegrana dealera, 3:1
	else if (player.getHandValue() == 21) return 3; // wygrana 3:1 , blackjack
	else if (player.getHandValue() < 21 && player.getHandValue() > dealer.getHandValue()) return 1; //wygrana 2:1
	else if (player.getHandValue() < 21 && player.getHandValue() == dealer.getHandValue()) return 0; // remis, 1:1
	else if (player.getHandValue() < 21 && player.getHandValue() < dealer.getHandValue()) return -1; // przegrana -bet
}
*/