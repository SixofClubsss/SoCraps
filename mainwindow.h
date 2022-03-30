#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rulespopup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void point();
    void passBetOn();
    void roll();
    void fund();
    void pass();
    void place();
    void rPlace();
    void outcome();
    void payOut();
    void pointPayout();
    void takeState();
    void repeatBet();
    void oRepeatBet();


private slots:
    void on_rollButton_clicked();

    void on_depositButton_clicked();

    void on_placeBetButton_clicked();

    void on_rBetButton_clicked();

    void on_betPushButton_clicked();

    void on_repeatButton_clicked();

    void on_oRepeatButton_clicked();
    
    void on_heloButton_clicked();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
