#include "card.h"

Card::Card(string name, int value) {
	this->name = name;
	this->value = value;
}

string Card::getName() {
	return name;
}

int Card::getValue() {
	return value;
}