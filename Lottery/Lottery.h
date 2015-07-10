/* 
 * File:   Lottery.h
 * Author: Marcel
 *
 */

#ifndef LOTTERY_H
#define	LOTTERY_H

#include "Ticket.h"

#include <iomanip>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
#include <vector>

class Lottery {
public:
    Lottery();
    Lottery(const Lottery& orig);
    virtual ~Lottery();
    void showMenu();
    void lotteryDrawing();
    Ticket* getTicket();
    bool getDrawing();
    void setDrawing(bool drawing);
    void getLotteryNumbers();
private:
    Ticket* lottery;
    bool drawing;
};

#endif	/* LOTTERY_H */

