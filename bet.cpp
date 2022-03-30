#include <cstdlib>
#include "bet.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

double SixEightPay = 1.16667;
double FiveNinePay = 1.4;              /// odds for payout
double FourTenPay = 1.8;
double SevenPay = 4;
double ThreeElevenPay = 15;
double TwoTwelvePay = 30;

double PassLinePay = 2;

double Bet::balance;               /// player balance
double Bet::betPlace[6];          /// array to hold place bets
double Bet::betOt[5];            /// array to hold one time bets
double Bet::table[3];

int Bet::Roll::dice1;
int Bet::Roll::dice2;
int Bet::Roll::diceSum;
double Bet::Roll::betAmount;
bool Bet::Roll::onPoint;
int Bet::Roll::point;
double Bet::Roll::passOdds;

int Bet::Stored::sum;               /// stored used for repeat bet
int Bet::Stored::sum2;
double Bet::Stored::betPlace[6];
double Bet::Stored::betOt[5];


void MainWindow::point()       /// sets point and holds untill 7 rolled
{
       if(Bet::Roll::diceSum == 4){
            Bet::Roll::point = 4;
            Bet::Roll::onPoint = true;
            ui->pointButton->setChecked(Bet::Roll::onPoint);

        }else if(Bet::Roll::diceSum == 5){
            Bet::Roll::point = 5;
            Bet::Roll::onPoint = true;
            ui->pointButton->setChecked(Bet::Roll::onPoint);

        }else if(Bet::Roll::diceSum == 6){
            Bet::Roll::point = 6;
            Bet::Roll::onPoint = true;
            ui->pointButton->setChecked(Bet::Roll::onPoint);

        }else if(Bet::Roll::diceSum == 8){
           Bet::Roll::point = 8;
           Bet::Roll::onPoint = true;
           ui->pointButton->setChecked(Bet::Roll::onPoint);

        }else if(Bet::Roll::diceSum == 9){
           Bet::Roll::point = 9;
           Bet::Roll::onPoint = true;
           ui->pointButton->setChecked(Bet::Roll::onPoint);

        }else if(Bet::Roll::diceSum == 10){
           Bet::Roll::point = 10;
           Bet::Roll::onPoint = true;
           ui->pointButton->setChecked(Bet::Roll::onPoint);

       }else
            Bet::Roll::onPoint = false;
            ui->pointButton->setChecked(Bet::Roll::onPoint);
            ui->pointLabel->setNum(Bet::Roll::point);

}


void MainWindow::passBetOn()        /// enable/disable pass line bets
{
    if(Bet::Roll::onPoint == true){
       ui->betPushButton->setEnabled(false);
    }

}


void MainWindow::roll()         /// rolls dice
{
    srand(time(0));

    Bet::Roll::dice1 = (int) (1+rand()%6);

    Bet::Roll::dice2 = (int) (1+rand()%6);

    Bet::Roll::diceSum = Bet::Roll::dice1 + Bet::Roll::dice2;

    ui->label->setText(tr(" "));

    ui->oRepeatButton->setEnabled(true);       /// enable repeat onetime bet button


}


void MainWindow::fund()     /// deposit funds
{
    if(Bet::balance <= 0){
        Bet::balance = ui->doubleSpinBox->value();
        ui->fundsSpinBox->setValue(Bet::balance);

    }else{
        Bet::balance = ui->fundsSpinBox->value();
        double addBal = ui->doubleSpinBox->value();
        ui->fundsSpinBox->setValue(Bet::balance + addBal);
      }

    ui->label->setText(tr("DEPOSIT\nSUCCESSFUL"));
}


void MainWindow::pass()             /// make a pass or don't pass bet
{
    int index = ui->comboBox->currentIndex();

    if(ui->fundsSpinBox->value() <= 0){
        ui->label->setText(tr("NOT ENOUGH\nFUNDS"));
        return;

        }else

        Bet::Roll::betAmount = ui->amountSpinBox_2->value();
        Bet::balance = ui->fundsSpinBox->value();
        ui->fundsSpinBox->setValue(Bet::balance - Bet::Roll::betAmount);

         switch (index){
          case 0:
          Bet::table[0] += Bet::Roll::betAmount;
          ui->label->setText(tr("PASS LINE BET"));
         break;
          case 1:
          Bet::table[1] += Bet::Roll::betAmount;
          ui->label->setText(tr("DONT PASS BET"));
         break;
          }
     ui->passSpinBox->setValue(Bet::table[0]);
     ui->dontSpinBox->setValue(Bet::table[1]);
}


void MainWindow::place()        /// place bets on table, they will remain untill 7 rolled
{

    if(ui->fundsSpinBox->value() <= 0){
        ui->label->setText(tr("NOT ENOUGH\nFUNDS"));
        return;

        }else

            Bet::Roll::betAmount = ui->amountSpinBox->value();
            Bet::balance = ui->fundsSpinBox->value();

            ui->fundsSpinBox->setValue(Bet::balance - Bet::Roll::betAmount);

                if(ui->betSpinBox->value() == 4){
                    Bet::betPlace[0] += Bet::Roll::betAmount;
                    ui->label->setText(tr("BET PLACED\nON 4"));

                    if(ui->fourSpinBox->value() <= 0){
                    ui->fourSpinBox->setValue(Bet::betPlace[0]);
                    }else
                        ui->fourSpinBox->setValue(ui->fourSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 5){
                    Bet::betPlace[1] += Bet::Roll::betAmount;
                    ui->label->setText(tr("BET PLACED\nON 5"));

                    if(ui->fiveSpinBox->value() <= 0){
                    ui->fiveSpinBox->setValue(Bet::betPlace[1]);
                    }else
                        ui->fiveSpinBox->setValue(ui->fiveSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 6){
                    Bet::betPlace[2] += Bet::Roll::betAmount;
                    ui->label->setText(tr("BET PLACED\nON 6"));

                    if(ui->sixSpinBox->value() <= 0){
                    ui->sixSpinBox->setValue(Bet::betPlace[2]);
                    }else
                        ui->sixSpinBox->setValue(ui->sixSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 8){
                    Bet::betPlace[3] += Bet::Roll::betAmount;
                    ui->label->setText(tr("BET PLACED\nON 8"));

                    if(ui->eightSpinBox->value() <= 0){
                    ui->eightSpinBox->setValue(Bet::betPlace[3]);
                    }else
                        ui->eightSpinBox->setValue(ui->eightSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 9){
                    Bet::betPlace[4] += Bet::Roll::betAmount;
                    ui->label->setText(tr("BET PLACED\nON 9"));

                    if(ui->nineSpinBox->value() <= 0){
                    ui->nineSpinBox->setValue(Bet::betPlace[4]);
                    }else
                        ui->nineSpinBox->setValue(ui->nineSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 10){
                    Bet::betPlace[5] += Bet::Roll::betAmount;
                    ui->label->setText(tr("BET PLACED\nON 10"));

                    if(ui->tenSpinBox->value() <= 0){
                    ui->tenSpinBox->setValue(Bet::betPlace[5]);
                    }else
                        ui->tenSpinBox->setValue(ui->tenSpinBox->value() + Bet::Roll::betAmount);



                }else if(ui->betSpinBox->value() == 2){
                    Bet::betOt[0] += Bet::Roll::betAmount;
                    ui->label->setText(tr("ONE TIME BET\n PLACED ON 2"));

                    if(ui->twoSpinBox->value() <= 0){
                        ui->twoSpinBox->setValue(Bet::betOt[0]);
                    }else
                        ui->twoSpinBox->setValue(ui->twoSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 3){
                    Bet::betOt[1] += Bet::Roll::betAmount;
                    ui->label->setText(tr("ONE TIME BET\n PLACED ON 3"));

                    if(ui->threeSpinBox->value() <= 0){
                        ui->threeSpinBox->setValue(Bet::betOt[1]);
                    }else
                        ui->threeSpinBox->setValue(ui->threeSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 7){
                    Bet::betOt[2] += Bet::Roll::betAmount;
                    ui->label->setText(tr("ONE TIME BET\n PLACED ON 7"));

                    if(ui->sevenSpinBox->value() <= 0){
                        ui->sevenSpinBox->setValue(Bet::betOt[2]);
                    }else
                        ui->sevenSpinBox->setValue(ui->sevenSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 11){
                    Bet::betOt[3] += Bet::Roll::betAmount;
                    ui->label->setText(tr("ONE TIME BET\n PLACED ON 11"));

                    if(ui->elevenSpinBox->value() <= 0){
                        ui->elevenSpinBox->setValue(Bet::betOt[3]);
                    }else
                        ui->elevenSpinBox->setValue(ui->elevenSpinBox->value() + Bet::Roll::betAmount);


                }else if(ui->betSpinBox->value() == 12){
                    Bet::betOt[4] += Bet::Roll::betAmount;
                    ui->label->setText(tr("ONE TIME BET\n PLACED ON 12"));

                    if(ui->twelveSpinBox->value() <= 0){
                        ui->twelveSpinBox->setValue(Bet::betOt[4]);


                }else
                    ui->twelveSpinBox->setValue(ui->twelveSpinBox->value() + Bet::Roll::betAmount);

                }else;

}


void MainWindow::rPlace()       /// remove a place bet or a one time bet
{
        Bet::balance = ui->fundsSpinBox->value();

        Bet::Roll::betAmount = ui->amountSpinBox->value();

            if(ui->RBetSpinBox->value() == 4){
                Bet::balance += ui->fourSpinBox->value();
                Bet::betPlace[0] = 0;
                Bet::Stored::betPlace[0] = Bet::betPlace[0];
                ui->fourSpinBox->setValue(Bet::betPlace[0]);
                ui->label->setText(tr("BET CLEARED\nON 4"));

            }else if(ui->RBetSpinBox->value() == 5){
                Bet::balance += ui->fiveSpinBox->value();
                Bet::betPlace[1] = 0;
                Bet::Stored::betPlace[1] = Bet::betPlace[1];
                ui->fiveSpinBox->setValue(Bet::betPlace[1]);
                ui->label->setText(tr("BET CLEARED\nON 5"));

            }else if(ui->RBetSpinBox->value() == 6){
                Bet::balance += ui->sixSpinBox->value();
                Bet::betPlace[2] = 0;
                Bet::Stored::betPlace[2] = Bet::betPlace[2];
                ui->sixSpinBox->setValue(Bet::betPlace[2]);
                ui->label->setText(tr("BET CLEARED\nON 6"));

            }else if(ui->RBetSpinBox->value() == 8){
                Bet::balance += ui->eightSpinBox->value();
                Bet::betPlace[3] = 0;
                Bet::Stored::betPlace[3] = Bet::betPlace[3];
                ui->eightSpinBox->setValue(Bet::betPlace[3]);
                ui->label->setText(tr("BET CLEARED\nON 8"));

            }else if(ui->RBetSpinBox->value() == 9){
                Bet::balance += ui->nineSpinBox->value();
                Bet::betPlace[4] = 0;
                Bet::Stored::betPlace[4] = Bet::betPlace[4];
                ui->nineSpinBox->setValue(Bet::betPlace[4]);
                ui->label->setText(tr("BET CLEARED\nON 9"));

            }else if(ui->RBetSpinBox->value() == 10){
                Bet::balance += ui->tenSpinBox->value();
                Bet::betOt[5] = 0;
                Bet::Stored::betPlace[5] = Bet::betPlace[5];
                ui->tenSpinBox->setValue(Bet::betPlace[5]);
                ui->label->setText(tr("BET CLEARED\nON 10"));


            }else if(ui->RBetSpinBox->value() == 2){
                Bet::balance += Bet::betOt[0];
                Bet::betOt[0] = 0;
                ui->label->setText(tr("BET CLEARED\nON 2"));
                ui->twoSpinBox->setValue(Bet::betOt[0]);

            }else if(ui->RBetSpinBox->value() == 3){
                Bet::balance += Bet::betOt[1];
                Bet::betOt[1] = 0;
                ui->label->setText(tr("BET CLEARED\nON 3"));
                ui->threeSpinBox->setValue(Bet::betOt[1]);

            }else if(ui->RBetSpinBox->value() == 7){
                Bet::balance += Bet::betOt[2];
                Bet::betOt[2] = 0;
                ui->label->setText(tr("BET CLEARED\nON 3"));
                ui->sevenSpinBox->setValue(Bet::betOt[2]);

            }else if(ui->RBetSpinBox->value() == 11){
                Bet::balance += Bet::betOt[3];
                Bet::betOt[3] = 0;
                ui->label->setText(tr("BET CLEARED\nON 11"));
                ui->elevenSpinBox->setValue(Bet::betOt[3]);

            }else if(ui->RBetSpinBox->value() == 12){
                Bet::balance += Bet::betOt[4];
                Bet::betOt[4] = 0;
                ui->label->setText(tr("BET CLEARED\nON 12"));
                ui->twelveSpinBox->setValue(Bet::betOt[4]);
            }else;

        ui->fundsSpinBox->setValue(Bet::balance);

}


void MainWindow::outcome()
{

    ui->lcdNumber->display(Bet::Roll::dice1);
    ui->lcdNumber_2->display(Bet::Roll::dice2);             /// display for dice
    ui->lcdNumber_3->display(Bet::Roll::diceSum);

    switch (Bet::Roll::onPoint){
    case 0:

        if(Bet::Roll::diceSum == 7){

            std::fill_n(Bet::betPlace, 6, 0);                  /// clears place bets if 7 rolled

            Bet::Roll::point = 0;
            ui->pointLabel->setNum(Bet::Roll::point);       /// clears point int

            Bet::Roll::onPoint = false;
            ui->pointButton->setChecked(Bet::Roll::onPoint);    /// point button on/off

            ui->betPushButton->setEnabled(true);             /// resets pass line bet
            ui->repeatButton->setEnabled(true);

            ui->fundsSpinBox->setValue(Bet::balance += Bet::table[0] -= Bet::table[1]);  /// ?weird start glitch added +10 for pass line if 7 rolled?
            std::fill_n(Bet::table, 2, 0);
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);

            ui->fourSpinBox->setValue(Bet::betPlace[0]);
            ui->fiveSpinBox->setValue(Bet::betPlace[1]);
            ui->sixSpinBox->setValue(Bet::betPlace[2]);
            ui->eightSpinBox->setValue(Bet::betPlace[3]);
            ui->nineSpinBox->setValue(Bet::betPlace[4]);
            ui->tenSpinBox->setValue(Bet::betPlace[5]);
        }

         else if(Bet::Roll::diceSum == 11){

            ui->fundsSpinBox->setValue(Bet::balance += Bet::table[0] -= Bet::table[1]);
            std::fill_n(Bet::table, 2, 0);
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);

        }else if(Bet::Roll::diceSum == 12){

            Bet::table[0] = 0;
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);


        }else if(Bet::Roll::diceSum == 2){

            ui->fundsSpinBox->setValue(Bet::balance += Bet::table[1] -= Bet::table[0]);
            std::fill_n(Bet::table, 2, 0);
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);


        }else if(Bet::Roll::diceSum == 3){

            ui->fundsSpinBox->setValue(Bet::balance += Bet::table[1] -= Bet::table[0]);         /// 2 || 3 kept ending in this outcome
            std::fill_n(Bet::table, 2, 0);
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);


        }else {
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);
        }break;


    case 1:

        if(Bet::Roll::diceSum == 7){

            std::fill_n(Bet::betPlace, 6, 0);                  /// clears place bets if 7 rolled

            Bet::Roll::point = 0;
            ui->pointLabel->setNum(Bet::Roll::point);       /// clears point int

            Bet::Roll::onPoint = false;
            ui->pointButton->setChecked(Bet::Roll::onPoint);    /// point button on/off

            ui->betPushButton->setEnabled(true);             /// resets pass line bet
            ui->repeatButton->setEnabled(true);
               
            ui->fourSpinBox->setValue(Bet::betPlace[0]);
            ui->fiveSpinBox->setValue(Bet::betPlace[1]);
            ui->sixSpinBox->setValue(Bet::betPlace[2]);
            ui->eightSpinBox->setValue(Bet::betPlace[3]);
            ui->nineSpinBox->setValue(Bet::betPlace[4]);
            ui->tenSpinBox->setValue(Bet::betPlace[5]);

        }else {
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);
        }

    }
}


void MainWindow::payOut()       /// payout if a bet is placed on the number rolled
{

    Bet::balance = ui->fundsSpinBox->value();

        if(Bet::Roll::diceSum == 4){
            Bet::balance += ui->fourSpinBox->value() * FourTenPay;

        }else if(Bet::Roll::diceSum == 5){
            Bet::balance += ui->fiveSpinBox->value() * FiveNinePay;

        }else if(Bet::Roll::diceSum == 6){
            Bet::balance += ui->sixSpinBox->value() * SixEightPay;

        }else if(Bet::Roll::diceSum == 7){
            Bet::balance += ui->sevenSpinBox->value() * SevenPay;

        }else if(Bet::Roll::diceSum == 8){
            Bet::balance += ui->eightSpinBox->value() * SixEightPay;

        }else if(Bet::Roll::diceSum == 9){
            Bet::balance += ui->nineSpinBox->value() * FiveNinePay;

        }else if(Bet::Roll::diceSum == 10){
            Bet::balance += ui->tenSpinBox->value() * FourTenPay;

        }else if(Bet::Roll::diceSum == 2){
             Bet::balance += ui->twoSpinBox->value() * TwoTwelvePay;

         }else if(Bet::Roll::diceSum == 3){
             Bet::balance += Bet::betOt[1] * ThreeElevenPay;

         }else if(Bet::Roll::diceSum == 11){
             Bet::balance += Bet::betOt[2] * ThreeElevenPay;

         }else if(Bet::Roll::diceSum == 12){
             Bet::balance += Bet::betOt[3] * TwoTwelvePay;

         }else;


    ui->fundsSpinBox->setValue(Bet::balance);
    std::fill_n(Bet::betOt, 5, 0);
    ui->twoSpinBox->setValue(Bet::betOt[0]);
    ui->threeSpinBox->setValue(Bet::betOt[1]);
    ui->sevenSpinBox->setValue(Bet::betOt[2]);
    ui->elevenSpinBox->setValue(Bet::betOt[3]);
    ui->twelveSpinBox->setValue(Bet::betOt[4]);



}

void MainWindow::pointPayout()
{
    if(Bet::Roll::diceSum == Bet::Roll::point){
            Bet::balance += Bet::table[0] * PassLinePay;
            ui->fundsSpinBox->setValue(Bet::balance);
            Bet::Roll::onPoint = false;
            ui->pointButton->setChecked(Bet::Roll::onPoint);
            Bet::Roll::point = 0;                               /// pays out pass line if point hit 1 to 1
            ui->betPushButton->setEnabled(true);               /// and pass bet cleared added to balance
            ui->pointLabel->setNum(Bet::Roll::point);
            std::fill_n(Bet::table, 2, 0);
            ui->pointLabel->setNum(Bet::Roll::point);
            ui->passSpinBox->setValue(Bet::table[0]);
            ui->dontSpinBox->setValue(Bet::table[1]);

    }else if(Bet::Roll::diceSum == 7){
            Bet::balance += Bet::table[1] * PassLinePay;
            ui->fundsSpinBox->setValue(Bet::balance);                   /// pays out don't pass line if
            std::fill_n(Bet::table, 2, 0);                             /// 7 comes before point hit and
            ui->dontSpinBox->setValue(Bet::table[0]);                 /// don't pass returned to balance
            ui->passSpinBox->setValue(Bet::table[1]);
    }



}


void MainWindow::takeState()            ///used to take bet values for repeat bet
{
    Bet::Stored::betPlace[0] = ui->fourSpinBox->value();
    Bet::Stored::betPlace[1] = ui->fiveSpinBox->value();
    Bet::Stored::betPlace[2] = ui->sixSpinBox->value();
    Bet::Stored::betPlace[3] = ui->eightSpinBox->value();
    Bet::Stored::betPlace[4] = ui->nineSpinBox->value();
    Bet::Stored::betPlace[5] = ui->tenSpinBox->value();

    Bet::Stored::betOt[0] = ui->twoSpinBox->value();
    Bet::Stored::betOt[1] = ui->threeSpinBox->value();
    Bet::Stored::betOt[2] = ui->sevenSpinBox->value();
    Bet::Stored::betOt[3] = ui->elevenSpinBox->value();
    Bet::Stored::betOt[4] = ui->twelveSpinBox->value();

}


void MainWindow::repeatBet()        /// repeat last bet  (place only)
{
    Bet::Stored::sum = 0;
    for(auto& num : Bet::Stored::betPlace)              /// adds array total sum and
        Bet::Stored::sum += num;                       /// minus from balance

    ui->fundsSpinBox->setValue(Bet::balance -= Bet::Stored::sum);
    ui->repeatButton->setEnabled(false);


    ui->fourSpinBox->setValue(Bet::Stored::betPlace[0]);
    ui->fiveSpinBox->setValue(Bet::Stored::betPlace[1]);
    ui->sixSpinBox->setValue(Bet::Stored::betPlace[2]);
    ui->eightSpinBox->setValue(Bet::Stored::betPlace[3]);
    ui->nineSpinBox->setValue(Bet::Stored::betPlace[4]);
    ui->tenSpinBox->setValue(Bet::Stored::betPlace[5]);

}

void MainWindow::oRepeatBet()
{
    Bet::Stored::sum2 = 0;
    for(auto& num : Bet::Stored::betOt)
        Bet::Stored::sum2 += num;

    ui->fundsSpinBox->setValue(Bet::balance -= Bet::Stored::sum2);
    ui->oRepeatButton->setEnabled(false);

    ui->twoSpinBox->setValue(Bet::Stored::betOt[0]);
    ui->threeSpinBox->setValue(Bet::Stored::betOt[1]);
    ui->sevenSpinBox->setValue(Bet::Stored::betOt[2]);
    ui->elevenSpinBox->setValue(Bet::Stored::betOt[3]);
    ui->twelveSpinBox->setValue(Bet::Stored::betOt[4]);
}

