#pragma once
#ifndef BET_H
#define BET_H

class Bet {
public:
	double balance;

	Bet() : balance(0) {}

	Bet(double balance);

	void increase(double amount);

	bool decrease(double amount);

	double getBalance();

};

#endif