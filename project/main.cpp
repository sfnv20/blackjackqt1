#include "mainwindow.h"
#include <QApplication>
#include "card.h"
#include "bet.h"
#include "func.h"
#include "Dealer.h"
#include "Player.h"
#include <iostream>
#include <clocale>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
