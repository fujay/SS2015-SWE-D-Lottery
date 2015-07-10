/* 
 * File:   LotteryControl.h
 *
 */

#ifndef LOTTERYCONTROL_H
#define	LOTTERYCONTROL_H

#include "Player.h"
#include "Lottery.h"
#include <iomanip>

class LotteryControl {
public:
    LotteryControl();
    LotteryControl(const LotteryControl& orig);
    virtual ~LotteryControl();
private:
    char results(const int number);
    char choose;
    Lottery* lottery;
    Player* player;
    Ticket* ticket;
    std::vector<Lottery*> lotteries;
    std::vector<Player*> players;
};

#endif	/* LOTTERYCONTROL_H */

