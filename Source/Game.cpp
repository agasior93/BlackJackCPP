#include "Game.h"
#include "Player.h"
#include <iostream>
using namespace std;

void Game::newDeal(Deck *deck, Player &player, Dealer &dealer, int &cardCounter, float &bet)
{
	player.removeCards(); // Kasowanie kart z r¹k gracza i dealera
	dealer.removeCards();

	if (cardCounter > 40){ // Jezeli licznik kart przekorczy 40 nastepuje tasowanie
		deck->shuffle();
		cardCounter = 0;
	}

	player.addCard(deck->selectCard(cardCounter)); // Rozdawanie kart wedlug licznika oraz inkrementacja licznika
	cardCounter++;
	dealer.addCard(deck->selectCard(cardCounter));
	cardCounter++;
	player.addCard(deck->selectCard(cardCounter));
	cardCounter++;
	dealer.addCard(deck->selectCard(cardCounter));
	cardCounter++;		

	gameInfo(player, dealer, bet);
	
	dealerPlay(deck, dealer, cardCounter); // Ruch dealera	
	if (whoWin(player, dealer) == 2){
		gameSummary(player, dealer, bet);
		player.addCash(bet * 3);
		cout << endl << "Dealer Lost" << endl << "You win " << bet * 3 << endl << "Current cash: " << player.getCash() << endl;
		

		cout << endl << "New Deal" << endl;
		bet = makeBet(player);
		newDeal(deck, player, dealer, cardCounter, bet);
	}
}

float Game::makeBet(Player &player){
	float bet = 0;
	bool ok = true;
	cout << "Make a bet (minimum 50$): ";
	do{
		cin >> bet;		
		if (bet < 50) cout << "Minimum bet is 50$!" << endl;
		else if (bet > player.getCash()) cout << "You don't have enough cash!" << endl;
		
	} while (!((bet >= 50) && (bet <= player.getCash())));
	player.removeCash(bet);
		return bet;
}

void Game::dealerPlay(Deck *deck, Dealer &dealer, int cardCounter){
	while (dealer.getHandValue() < 17){
		dealer.addCard(deck->selectCard(cardCounter));
		cardCounter++;
	}
}



bool Game::winner(Player &player, Dealer &dealer, float &bet)
{
	if (player.getHandValue() < 21 && player.getHandValue() < dealer.getHandValue()){
		gameSummary(player, dealer, bet);
		cout << endl << "Dealer won" << endl << "You lost " << bet << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() < 21 && player.getHandValue() == dealer.getHandValue()){
		player.addCash(bet);
		gameSummary(player, dealer, bet);
		cout << endl << "Tie!" << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() < 21 && player.getHandValue() > dealer.getHandValue()){
		player.addCash(bet * 2);
		gameSummary(player, dealer, bet);
		cout << endl << "Winner!" << endl << "You win " << bet * 2 << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() > 21){
		gameSummary(player, dealer, bet);
		cout << endl << "Dealer won" << endl << "You lost " << bet << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}	
	else if (player.getHandValue() == 21){
		player.addCash(bet * 3);
		gameSummary(player, dealer, bet);
		cout << endl << "BlackJack!" << endl << "You win " << bet * 3 << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (dealer.getHandValue() > 21){
		player.addCash(bet * 3);
		gameSummary(player, dealer, bet);		
		cout << endl << "Dealer lost" << endl << "You win " << bet * 3 << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}	
}

bool Game::winInFirst(Player &player, Dealer &dealer, float &bet)
{
	if (player.getHandValue() > 21){
		gameSummary(player, dealer, bet);
		cout << endl << "Dealer won" << endl << "You lost " << bet << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (player.getHandValue() == 21){
		player.addCash(bet * 3);
		gameSummary(player, dealer, bet);
		cout << endl << "BlackJack!" << endl << "You win " << bet * 3 << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
	else if (dealer.getHandValue() > 21){
		player.addCash(bet * 3);
		gameSummary(player, dealer, bet);
		cout << endl << "Dealer lost" << endl << "You win " << bet * 3 << endl << "Current cash: " << player.getCash() << endl << endl << "#NEW GAME#" << endl;
		return true;
	}
}

void Game::gameInfo(Player &player, Dealer &dealer, float &bet)
{
	system("cls");
	cout << "Player " << player.getName() << endl << "Cash: " << player.getCash() << endl << "Current bet : " << bet << endl << endl << "Cards on hand: " << endl;

	player.getHand(); 
	cout << "Score: " << player.getHandValue() << endl;

	cout << endl << "Dealer's hand: " << endl;
	dealer.showOne(); 
}

void Game::gameSummary(Player &player, Dealer &dealer, float &bet)
{
	system("cls");
	cout << "Player " << player.getName() << endl << "Cash: " << player.getCash() << endl << "Current bet : " << bet << endl << endl << "Cards on hand: " << endl;

	player.getHand();  
	cout << "Score: " << player.getHandValue() << endl;

	cout << endl << "Dealer's hand: " << endl;
	dealer.getHand();
	cout << "Score: " << dealer.getHandValue() << endl;
}

int Game::whoWin(Player &player, Dealer &dealer){
	if (player.getHandValue() > 21) return -2; // przegrana -bet
	else if (dealer.getHandValue() > 21) return 2; // przegrana dealera, 3:1
	else if (player.getHandValue() == 21) return 3; // wygrana 3:1 , blackjack
	else if (player.getHandValue() < 21 && player.getHandValue() > dealer.getHandValue()) return 1; //wygrana 2:1
	else if (player.getHandValue() < 21 && player.getHandValue() == dealer.getHandValue()) return 0; // remis, 1:1
	else if (player.getHandValue() < 21 && player.getHandValue() < dealer.getHandValue()) return -1; // przegrana -bet
}