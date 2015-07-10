/* 
 * File:   Ticket.h
 *
 */

#ifndef TICKET_H
#define	TICKET_H

#include <vector>
#include <set>
#include <iostream>

class Ticket {
public:
    Ticket();
    Ticket(const std::vector<int>&);
    Ticket(const Ticket& orig);
    virtual ~Ticket();
    void inputTicket();
    void proofTicket();
    bool proofTicketSize();
    bool proofTicketNumbers();
    bool proofTicketTwice();
    std::vector<int> getTicket();
    bool getCancel();
    void setCancel(bool bcancel);
    static const int MAXNUMBERS = 6;
    static const int MAXRANGE = 49;
    static const int MINRANGE = 1;
private:
    std::vector<int> numbers;
    bool cancel;
};

#endif	/* TICKET_H */
