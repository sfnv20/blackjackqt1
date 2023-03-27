#pragma once
#include "qpushbutton.h"
#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : public Player {
private:
	bool isHoleCardHidden;
    QPushButton* hit_button;

public:

    Dealer(vector<Card*>& deck);

	~Dealer();

	void dealCards(Player& player);

	bool checkDealerHand();

    int play(Player& player, QLabel* dealer_labels[], QLabel *player_labels[], QPushButton *hit_button, QPushButton *stand_button);

    void showDealerHand(QLabel* dealer_labels[]);

	void revealHoleCard();

    void clearHand(QLabel *dealer_labels[]);

protected:
    int score;

};

#endif
