/* 
 * File:   Player.h
 *
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <string>
#include "Ticket.h"

class Player {
public:
    Player();
    Player(const Player& orig);
    virtual ~Player();
    void inputName();
    std::string getName();
    void proofName();
    bool proofChars();
    bool getCancel();
    void setCancel(bool bcancel);
    Ticket* getTicket();
    void setTicket(Ticket* ticket);
private:
    std::string name;
    Ticket* ticket;
    bool cancel;
};

#endif	/* PLAYER_H */