#include <iostream>
#include <QObject>
#include "mainwindow.h"
#include "card.h"
#include "func.h"
#include "ui_mainwindow.h"
#include "Player.h"
#include "Dealer.h"
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player(deckPtrs)
    , dealer(deckPtrs)
{
    ui->setupUi(this);
    hit_button = ui->hit_button;
    stand_button = ui->stand_button;
    player_labels[0] = ui->Player_card1;
    player_labels[1] = ui->Player_card2;
    player_labels[2] = ui->Player_card3;
    player_labels[3] = ui->Player_card4;
    player_labels[4] = ui->Player_card5;

    dealer_labels[0] = ui->Dealer_card1;
    dealer_labels[1] = ui->Dealer_card2;
    dealer_labels[2] = ui->Dealer_card3;
    dealer_labels[3] = ui->Dealer_card4;
    dealer_labels[4] = ui->Dealer_card5;
    deck = createdeck();
    shuffle(deck);
    deckPtrs.reserve(deck.size());
    for (auto& card : deck) {
        deckPtrs.push_back(&card);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hit_button_clicked()
{
    player.drawCard();
    player.showHand(player_labels);
    if (player.getScore() > 21) {
        player.showHand(player_labels);
        dealer.revealHoleCard();
        dealer.showDealerHand(dealer_labels);
        player.lose();
    }
}


void MainWindow::on_start_button_clicked()
{
    restartgame();
}

void MainWindow::restartgame() {
    for (int i = 0; i < 5; i++) {
        player_labels[i]->clear();
        dealer_labels[i]->clear();
    }
    hit_button->setEnabled(true);
    hit_button->setChecked(false);
    stand_button->setEnabled(true);
    stand_button->setChecked(false);
    deck = createdeck();
    shuffle(deck);
    deckPtrs.reserve(deck.size());
    for (auto& card : deck) {
        deckPtrs.push_back(&card);
    }
    player.clearHand(player_labels);
    dealer.clearHand(dealer_labels);
    int result = dealer.play(player, dealer_labels, player_labels, hit_button, stand_button);
    cout << result;
}
