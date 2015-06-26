/* 
 * File:   LotteryControl.h
 * Author: Marcel
 *
 */

#include "Lottery.h"
#include <vector>

#ifndef LOTTERYCONTROL_H
#define	LOTTERYCONTROL_H

class LotteryControl {
public:
    LotteryControl();
    LotteryControl(const LotteryControl& orig);
    virtual ~LotteryControl();
    void newGame();
private:
    char choose;
    std::vector<Lottery> lotteries;
    std::vector<Player> players;
};

#endif	/* LOTTERYCONTROL_H */

