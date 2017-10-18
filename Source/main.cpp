#include <iostream>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
#include "Game.h"
#include <string>

string playerName;


int main(void){
	srand(time(0));

	Game game;
	Deck *deck = new Deck();
	int cardCounter = 0;
	float currentBet = 0;
	int choice;

	cout << "What is your name?: ";
	cin >> playerName;	
	Player player(playerName);
	Dealer dealer;
	cout << "Cash: " << player.getCash() << endl;

	currentBet = game.makeBet(player);		
	deck->shuffle();

	game.newDeal(deck, player, dealer, cardCounter, currentBet);
	

	while(true){		
		cout << endl << "Take card(1)" << endl << "Stand(2)" << endl;
		do{
			cin >> choice;
		} while (!(choice > 0 && choice < 3));

		switch (choice)	{
		
		case 1:{
			 player.addCard(deck->selectCard(cardCounter));
			 cardCounter++;
			 game.gameInfo(player, dealer, currentBet);
			 if (game.winInFirst(player, dealer, currentBet) == true){
				 currentBet = game.makeBet(player);
				 game.newDeal(deck, player, dealer, cardCounter, currentBet);
			 }			 
		}break;

		case 2:{
				   if (game.winInFirst(player, dealer, currentBet) == true){
					   currentBet = game.makeBet(player);
					   game.newDeal(deck, player, dealer, cardCounter, currentBet);
				   }
			 
		 }break;

		}
	} 


	cout << endl;
	system("PAUSE");
}

