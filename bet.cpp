#include "bet.h"

Bet::Bet(double balance) {
	this->balance = balance;
}

void Bet::increase(double amount) {
	balance += amount;
}

bool Bet::decrease(double amount) {
	if (balance - amount < 0) {
		return false;
	}

	balance -= amount;
	return true;
}

double Bet::getBalance() {
	return balance;
}
