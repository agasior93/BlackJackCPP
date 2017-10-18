#include "Player.h"
#include <iostream>


Player::Player(){}

Player::Player(string name){
	playerName = name;
	cash = 1000;	
	handValue = 0;
}

Player::~Player(){}

string Player::getName(){
	return playerName;
}

void Player::addCash(float quantity){
	cash += quantity;
}

void Player::removeCash(float quantity){
	cash -= quantity;
}

float Player::getCash(){
	return cash;
}

void Player::setCash(){
	cash = 1000;
}

void Player::addCard(Card card){
	hand.push_back(card);
}

void Player::removeCards(){
	hand.clear();
}

int Player::getHandValue(){
	handValue = 0;
	for (int i = 0; i < hand.size(); i++){
		handValue += hand[i].getValue();
	}
	return handValue;
}

void Player::getHand(){
	
	for (int i = 0; i < hand.size(); i++){
		std::cout << hand[i].getCard() << endl;
	}
}

