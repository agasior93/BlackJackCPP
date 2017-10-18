#include "Deck.h"

	Deck::Deck(){		
		deck[0] = *new Card("two", "heart", 2);
		deck[1] = *new Card("three", "heart", 3);
		deck[2] = *new Card("four", "heart", 4);
		deck[3] = *new Card("five", "heart", 5);
		deck[4] = *new Card("six", "heart", 6);
		deck[5] = *new Card("seven", "heart", 7);
		deck[6] = *new Card("eight", "heart", 8);
		deck[7] = *new Card("nine", "heart", 9);
		deck[8] = *new Card("ten", "heart", 10);
		deck[9] = *new Card("jack", "heart", 10);
		deck[10] = *new Card("queen", "heart", 10);
		deck[11] = *new Card("king", "heart", 10);
		deck[12] = *new Card("ace", "heart", 11);

		deck[13] = *new Card("two", "diamond", 2);
		deck[14] = *new Card("three", "diamond", 3);
		deck[15] = *new Card("four", "diamond", 4);
		deck[16] = *new Card("five", "diamond", 5);
		deck[17] = *new Card("six", "diamond", 6);
		deck[18] = *new Card("seven", "diamond", 7);
		deck[19] = *new Card("eight", "diamond", 8);
		deck[20] = *new Card("nine", "diamond", 9);
		deck[21] = *new Card("ten", "diamond", 10);
		deck[22] = *new Card("jack", "diamond", 10);
		deck[23] = *new Card("queen", "diamond", 10);
		deck[24] = *new Card("king", "diamond", 10);
		deck[25] = *new Card("ace", "diamond", 11);

		deck[26] = *new Card("two", "club", 2);
		deck[27] = *new Card("three", "club", 3);
		deck[28] = *new Card("four", "club", 4);
		deck[29] = *new Card("five", "club", 5);
		deck[30] = *new Card("six", "club", 6);
		deck[31] = *new Card("seven", "club", 7);
		deck[32] = *new Card("eight", "club", 8);
		deck[33] = *new Card("nine", "club", 9);
		deck[34] = *new Card("ten", "club", 10);
		deck[35] = *new Card("jack", "club", 10);
		deck[36] = *new Card("queen", "club", 10);
		deck[37] = *new Card("king", "club", 10);
		deck[38] = *new Card("ace", "club", 11);

		deck[39] = *new Card("two", "spade", 2);
		deck[40] = *new Card("three", "spade", 3);
		deck[41] = *new Card("four", "spade", 4);
		deck[42] = *new Card("five", "spade", 5);
		deck[43] = *new Card("six", "spade", 6);
		deck[44] = *new Card("seven", "spade", 7);
		deck[45] = *new Card("eight", "spade", 8);
		deck[46] = *new Card("nine", "spade", 9);
		deck[47] = *new Card("ten", "spade", 10);
		deck[48] = *new Card("jack", "spade", 10);
		deck[49] = *new Card("queen", "spade", 10);
		deck[50] = *new Card("king", "spade", 10);
		deck[51] = *new Card("ace", "spade", 11);
	}	

	Deck::~Deck(){}

	Card Deck::selectCard(int i){
		return deck[i];
	}

	void Deck::shuffle(){		
		for (int i = 0; i < 52; i++){
			int rnd = rand() % 52;
			Card temp = deck[i];
			deck[i] = deck[rnd];
			deck[rnd] = temp;
		}
	}
	