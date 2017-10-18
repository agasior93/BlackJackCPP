#include "Card.h"

Card::Card(){}

Card::Card(string f, string s, int v){
	face = f;
	suit = s;
	value = v;
}

Card::~Card(){}

string Card::getFace(){	return face; }

string Card::getSuit(){	return suit; }

string Card::getCard(){ return face + " of " + suit + "s"; }

int Card::getValue(){ return value; }