#pragma once
#ifndef CARD_H
#define CARD_H

#include <string>

const int DECK_SIZE = 52;

using namespace std;

class Card {
private:
	string name;
	int value;

public:
	Card(string name, int value);

	string getName();

	int getValue();
};


#endif
