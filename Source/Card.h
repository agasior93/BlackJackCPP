#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card
{
private:
	string face;
	string suit;
	int value;
public:
	Card();
	Card(string, string, int);
	~Card();
	string getFace();
	string getSuit();
	int getValue();
	string getCard();
};

#endif