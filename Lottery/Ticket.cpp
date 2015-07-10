/* 
 * File:   Ticket.cpp
 * 
 */

#include "Ticket.h"

Ticket::Ticket() {
    setCancel(false);
    inputTicket();
    if(!getCancel()) {
        proofTicket();
    }
}

Ticket::Ticket(const std::vector<int>& ticket) {
    numbers = ticket;
    //proofTicket();
}

Ticket::Ticket(const Ticket& orig) {
}

Ticket::~Ticket() {
}

void Ticket::inputTicket() {
    int number;
    std::cout << "Lottery Ticket (" << MINRANGE << "-" << MAXRANGE << ") 0 to abort" << std::endl;
    for(int i = 0; i < MAXNUMBERS; i++) {
        std::cout << "Lottery Number [" << i + 1 << "/" << MAXNUMBERS << "]: ";
        std::cin >> number;
        if(number == 0) {
            std::cout << "Canceled ticket!" << std::endl;
            this->setCancel(true);
            break;
        }
        numbers.push_back(number);
    }
}

void Ticket::proofTicket(){
    while(!proofTicketSize() || !proofTicketNumbers() || !proofTicketTwice()) {
        numbers.clear();
        std::cerr << "Ticket is incorrect!" << std::endl;
        inputTicket();
    }
}

bool Ticket::proofTicketSize() {
    if(numbers.size() == MAXNUMBERS) {
        return true;
    } else {
        return false;
    }
}

bool Ticket::proofTicketNumbers() {
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] < MINRANGE || numbers[i] > MAXRANGE) {
            return false;
        }
    }
    return true;
}

bool Ticket::proofTicketTwice() {
    std::set<int> twice(numbers.begin(), numbers.end());
    if(twice.size() < MAXNUMBERS) {
        return false;
    }
    return true;
}

std::vector<int> Ticket::getTicket() {
    return numbers;
}

bool Ticket::getCancel() {
    return cancel;
}

void Ticket::setCancel(bool bcancel) {
    this->cancel = bcancel;
}