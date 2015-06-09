/* 
 * File:   Player.h
 * Author: Fujay
 *
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <string>

class Player {
public:
    Player(std::string);
    Player(const Player& orig);
    virtual ~Player();
private:
    std::string name_;
};

#endif	/* PLAYER_H */