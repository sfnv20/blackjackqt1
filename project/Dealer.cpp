#include "Dealer.h"
#include "qapplication.h"
#include "qeventloop.h"
#include <QObject>
#include <QPushButton>
#include <iostream>

Dealer::Dealer(vector<Card*>& deck) : Player(deck) {
    isHoleCardHidden = true;
}

Dealer::~Dealer() {}

void Dealer::dealCards(Player& player) {
    drawCard();
    player.drawCard();
    drawCard();
    player.drawCard();
}

bool Dealer::checkDealerHand() {
    int score = getScore();
    if (score >= 17) {
        return false;
    }
    return true;
}

int Dealer::play(Player& player, QLabel* dealer_labels[], QLabel* player_labels[], QPushButton *hit_button, QPushButton *stand_button) {
    clearHand(dealer_labels);
    player.clearHand(player_labels);
    bool turn = false;
    dealCards(player);
    showDealerHand(dealer_labels);
    player.showHand(player_labels);
    bool playerTurnFinished = false;
    QObject::connect(stand_button, &QPushButton::clicked, [&]() {
        playerTurnFinished = true;
    });

    while (!playerTurnFinished) {
        QApplication::processEvents();
    }

    revealHoleCard();
    while (checkDealerHand()) {
        turn = true;
        drawCard();
        showDealerHand(dealer_labels);
    }

    if (getScore() > 21) {
        player.win();
        return 1;
    }
    else {
        int playerScore = player.getScore();
        int dealerScore = getScore();
        if (dealerScore > playerScore) {
            if (turn == false) showDealerHand(dealer_labels);
            player.lose();
            return 2;
        }
        else if (dealerScore < playerScore) {
            if(turn == false) showDealerHand(dealer_labels);
            player.win();
            return 1;
        }
        else {
            if(turn == false) showDealerHand(dealer_labels);
            cout << "It's a tie!" << endl;
            return 3;
        }
    }
}

void Dealer::showDealerHand(QLabel* dealer_labels[]) {

    //isHoleCardHidden = false;
    int j = 0;
    if (isHoleCardHidden) {
        cout << "Dealer's hand: [hidden card], " << hand[1]->getName() << endl;
        QString path = ":/cards/cards/coverage.png";
        int w = dealer_labels[0]->width();
        int h = dealer_labels[0]->height();
        QPixmap pixmap(path);
        dealer_labels[0]->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
        path = QString(":/cards/cards/%1.png").arg(QString::fromStdString(hand[1]->getName()));
        w = dealer_labels[1]->width();
        h = dealer_labels[1]->height();
        pixmap = path;
        dealer_labels[1]->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
    }
    else {

        cout << "Dealer's hand: ";
        for (const auto& card : hand) {
            QString path = QString(":/cards/cards/%1.png").arg(QString::fromStdString(card->getName()));
            QPixmap pixmap(path);
            int w = dealer_labels[j]->width();
            int h = dealer_labels[j]->height();
            dealer_labels[j]->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
            j++;
        }
        cout << "(Total: " << getScore() << ")" << endl;
    }
}

void Dealer::revealHoleCard() {
    isHoleCardHidden = false;
}

void Dealer::clearHand(QLabel* dealer_labels[]) {
    while (!hand.empty()) {
        delete hand.back();
        hand.pop_back();
    }
    score = 0;
}
