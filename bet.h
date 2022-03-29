#ifndef BET_H
#define BET_H


class Bet
{
    public:

           static double balance;
           static double betPlace[6];
           static double betOt[5];
           static double table[3];

            struct Roll {
                static int dice1;
                static int dice2;

                static int diceSum;

                static double betAmount;

                static bool onPoint;

                static int point;

                static double passOdds;
            };

            struct Stored {
                static int sum;
                static int sum2;
                static double betPlace[6];
                static double betOt[5];
            };

};

#endif // BET_H
