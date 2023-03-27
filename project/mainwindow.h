#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include "card.h"
#include "Player.h"
#include "Dealer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hit_button_clicked();
    void on_start_button_clicked();

private:
    Ui::MainWindow *ui;
    QPushButton* hit_button;
    QPushButton* stand_button;
    QLabel* player_labels[5];
    QLabel* dealer_labels[5];

    std::vector<Card> deck;
    std::vector<Card*> deckPtrs;
    Player player;
    Dealer dealer;

    void restartgame();
};

#endif // MAINWINDOW_H
