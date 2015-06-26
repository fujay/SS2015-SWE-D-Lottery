/* 
 * File:   LotteryControl.cpp
 * Author: Marcel
 * 
 */

#include "LotteryControl.h"

LotteryControl::LotteryControl() {
    Lottery instance = new Lottery();
    lotteries.push_back(instance);
}

LotteryControl::LotteryControl(const LotteryControl& orig) {
}

LotteryControl::~LotteryControl() {
}

LotteryControl::newGame() {
    Lottery instance = new Lottery();
    lotteries.push_back(instance);
}