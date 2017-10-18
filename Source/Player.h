#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Player
{
protected:
	string playerName;
	float cash;
	vector<Card> hand;
	int handValue;
public:
	Player();
	Player(string);
	~Player();
	string getName();
	void addCash(float);
	void removeCash(float);
	float getCash();
	void setCash();
	void addCard(Card);
	void removeCards();
	void getHand();	
	int getHandValue();
};

#endif