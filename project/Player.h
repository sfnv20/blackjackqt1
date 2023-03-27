#pragma once
#include "qlabel.h"
#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <QObject>
#include "Card.h"

using namespace std;

class Player{
protected:
    vector<Card*> hand;
    vector<Card*>& deck;
    int score;
    int aceCount;

public:
    Player(vector<Card*>& deck);

    virtual ~Player();

    virtual void drawCard();

    virtual int getScore();

    virtual void win();

    virtual void lose();

    void showHand(QLabel* player_labels[]);

    void clearHand(QLabel* player_labels[]);
};

#endif
