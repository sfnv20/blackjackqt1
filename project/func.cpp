#include <iostream>
#include <random>
#include <algorithm>
#include "card.h"
#include "func.h"

using namespace std;


    vector<Card> createdeck() {
        vector<Card> deck;
        deck.push_back(Card("ace_of_spades", 11));
        deck.push_back(Card("2_of_spades", 2));
        deck.push_back(Card("3_of_spades", 3));
        deck.push_back(Card("4_of_spades", 4));
        deck.push_back(Card("5_of_spades", 5));
        deck.push_back(Card("6_of_spades", 6));
        deck.push_back(Card("7_of_spades", 7));
        deck.push_back(Card("8_of_spades", 8));
        deck.push_back(Card("9_of_spades", 9));
        deck.push_back(Card("10_of_spades", 10));
        deck.push_back(Card("jack_of_spades", 10));
        deck.push_back(Card("queen_of_spades", 10));
        deck.push_back(Card("king_of_spades", 10));

        deck.push_back(Card("ace_of_hearts", 11));
        deck.push_back(Card("2_of_hearts", 2));
        deck.push_back(Card("3_of_hearts", 3));
        deck.push_back(Card("4_of_hearts", 4));
        deck.push_back(Card("5_of_hearts", 5));
        deck.push_back(Card("6_of_hearts", 6));
        deck.push_back(Card("7_of_hearts", 7));
        deck.push_back(Card("8_of_hearts", 8));
        deck.push_back(Card("9_of_hearts", 9));
        deck.push_back(Card("10_of_hearts", 10));
        deck.push_back(Card("jack_of_hearts", 10));
        deck.push_back(Card("queen_of_hearts", 10));
        deck.push_back(Card("king_of_hearts", 10));

        deck.push_back(Card("ace_of_clubs", 11));
        deck.push_back(Card("2_of_clubs", 2));
        deck.push_back(Card("3_of_clubs", 3));
        deck.push_back(Card("4_of_clubs", 4));
        deck.push_back(Card("5_of_clubs", 5));
        deck.push_back(Card("6_of_clubs", 6));
        deck.push_back(Card("7_of_clubs", 7));
        deck.push_back(Card("8_of_clubs", 8));
        deck.push_back(Card("9_of_clubs", 9));
        deck.push_back(Card("10_of_clubs", 10));
        deck.push_back(Card("jack_of_clubs", 10));
        deck.push_back(Card("queen_of_clubs", 10));
        deck.push_back(Card("king_of_clubs", 10));
        deck.push_back(Card("ace_of_diamonds", 11));

        deck.push_back(Card("2_of_diamonds", 2));
        deck.push_back(Card("3_of_diamonds", 3));
        deck.push_back(Card("4_of_diamonds", 4));
        deck.push_back(Card("5_of_diamonds", 5));
        deck.push_back(Card("6_of_diamonds", 6));
        deck.push_back(Card("7_of_diamonds", 7));
        deck.push_back(Card("8_of_diamonds", 8));
        deck.push_back(Card("9_of_diamonds", 9));
        deck.push_back(Card("10_of_diamonds", 10));
        deck.push_back(Card("jack_of_diamonds", 10));
        deck.push_back(Card("queen_of_diamonds", 10));
        deck.push_back(Card("king_of_diamonds", 10));
		return deck;
	}

void shuffle(vector<Card>& deck)
{
	random_device rd;
	mt19937 g(rd());
	shuffle(deck.begin(), deck.end(), g);
}
