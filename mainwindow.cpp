#include "bet.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->setStyleSheet("QGroupBox {  border: 1px solid gray;}");
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_rollButton_clicked()
{

    switch (Bet::Roll::onPoint){
    case 0:                             /// case 0: NO POINT

        roll();
        point();
        passBetOn();
        outcome();
        payOut();
        break;

    case 1:                            /// case 1: POINT

        roll();
        passBetOn();
        outcome();
        payOut();
        pointPayout();
        break;
    }

}


void MainWindow::on_depositButton_clicked()
{
    fund();
}


void MainWindow::on_placeBetButton_clicked()
{
    place();
    takeState();
}


void MainWindow::on_rBetButton_clicked()
{
    rPlace();
    takeState();
}


void MainWindow::on_betPushButton_clicked()
{
    pass();
}


void MainWindow::on_repeatButton_clicked()
{
    repeatBet();
}


void MainWindow::on_oRepeatButton_clicked()
{
    oRepeatBet();
}