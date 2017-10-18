#include "Dealer.h"

#include <iostream>

using namespace std;

Dealer::Dealer(){
	playerName = "Dealer";
	vector<Card> hand;
	int handValue;
}
void Dealer::showOne()
{	
	cout << hand[0].getCard() << endl << "### Hole Card ###" << endl;
}



