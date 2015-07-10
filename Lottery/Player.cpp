/* 
 * File:   Player.cpp
 * 
 */

#include "Player.h"

Player::Player() {
    setCancel(false);
    inputName();
    proofName();
}

Player::Player(const Player& orig) {
}

Player::~Player() {
}

void Player::inputName() {
    std::cout << "Your name (q to abort): ";
    std::cin >> name;
    if(name.size() >= 1) {
        if(name[0] == 'q' || name[0] == 'Q') {
            std::cout << "Canceled Player!" << std::endl;
            this->setCancel(true);
            return;
        }
    }
}

std::string Player::getName() {
    return name;
}

void Player::proofName() {
    while(proofChars()) {
        std::cerr << "Name is incorrect!" << std::endl;
        inputName();
    }
}

bool Player::proofChars() {
    for(int i = 0; i < name.size(); i++) {
        if(!isalpha(name[i])) {
            return true;
        }
    }
    return false;
}

bool Player::getCancel() {
    return cancel;
}

void Player::setCancel(bool bcancel) {
    this->cancel = bcancel;
}

Ticket* Player::getTicket() {
    return ticket;
}

void Player::setTicket(Ticket* ticket) {
    this->ticket = ticket;
}