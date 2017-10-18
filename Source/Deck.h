#ifndef DECK_H
#define DECK_H

#include <cstdlib>
#include <time.h>
#include "Card.h"

class Deck
{
private:
	Card *deck = new Card[52];
public:	
	Deck();
	~Deck();
	Card selectCard(int);
	void shuffle();
};

#endif
