#include "Player.h"
#include "qlabel.h"
#include <iostream>

Player::Player(vector<Card*>& deck) : deck(deck) {}

Player::~Player() {}

void Player::drawCard() {
    hand.push_back(deck.back());
    deck.pop_back();
}

int Player::getScore() {
    int score = 0;
    int aceCount = 0;
    for (const auto& card : hand) {
        score += card->getValue();
        if (card->getValue() == 11) {
            aceCount++;
        }
    }
    while (aceCount > 0 && score > 21) {
        score -= 10;
        aceCount--;
    }

    return score;
}

void Player::showHand(QLabel* player_labels[]) {
    int i = 0;
    for (const auto& card : hand) {
        QString path = QString(":/cards/cards/%1.png").arg(QString::fromStdString(card->getName()));
        QPixmap pixmap(path);
        int w = player_labels[i]->width();
        int h = player_labels[i]->height();
        player_labels[i]->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
        i++;
        cout << card->getName() << ", ";
    }
    cout << "(Total: " << getScore() << ")\n";
}

void Player::win() {
    cout << "Congratulations! You win!\n";
}

void Player::lose() {
    cout << "Sorry, you lose.\n";
}

void Player::clearHand(QLabel* player_labels[]) {
    while (!hand.empty()) {
        delete hand.back();
        hand.pop_back();
    }
    score = 0;
    aceCount = 0;
}
