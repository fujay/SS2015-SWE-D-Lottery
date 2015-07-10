/* 
 * File:   main.cpp
 *
 */
#include "LotteryControl.h"
using namespace std;

/*
 * Entry main point for the lottery game Program
 * @version 1.0
 * @author Sarwat Khan, Marcel Klamm, Meeraf Golja
 */
int main(int argc, char** argv) {
    LotteryControl* lotteryGame = new LotteryControl();
    delete lotteryGame;
    return 0;
}