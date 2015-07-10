/* 
 * File:   LotteryControl.cpp
 * 
 */

#include "LotteryControl.h"

LotteryControl::LotteryControl() {
    lottery = new Lottery();
    while (true) {
        lottery->showMenu();
        std::cin >> choose;

        if (choose == '1') {
            player = new Player();
            if(player->getCancel()) {
                continue;
            }
            ticket = new Ticket();
            if(ticket->getCancel()) {
                continue;
            }
            player->setTicket(ticket);
            players.push_back(player);
        } else if (choose == '2') {
            if(players.size() < 1) {
                std::cout << "No player with tickets!" << std::endl;
                continue;
            }
            if(lottery->getDrawing()) {
                std::cout << "Lottery has already draw" << std::endl;
                continue;
            }
            std::cout << "===" << " Lottery Drawing: " << "===" << std::endl;
            lottery->lotteryDrawing();
            lotteries.push_back(lottery);
        } else if (choose == '3') {
            if(!lottery->getDrawing()) {
                std::cout << "No lottery drawing yet!" << std::endl;
                continue;
            }
            std::cout << std::setw(18) << "Lottery Numbers: " << "\t\t";
            lottery->getLotteryNumbers();
            std::cout << std::endl;
            for(int i = 0; i < players.size(); i++) {
                int winCounter = 0;
                std::cout << std::setw(3) << i + 1 << ". Player: " << std::setw(10) << players[i]->getName() << std::setw(3) << " Ticket:";
                std::vector<int> playerTickets = players[i]->getTicket()->getTicket();
                for(int j = 0; j < ticket->MAXNUMBERS; j++) {
                    std::cout << std::setw(6) << results(playerTickets[j]) << playerTickets[j] << results(playerTickets[j]);
                    if(winCounter >= 3) {
                        std::cout << std::setw(3) << "=== WINNTER === (" << winCounter << " right numbers)";
                    }
                }
                std::cout << std::endl;
            }
            players.clear();
            lottery = new Lottery();
        } else if (choose == '0') {
            std::cout << "Exit Lottery Game . . ." << std::endl;
            break;
        } else {
            std::cout << "Error: Wrong input - Try again!" << std::endl;
        }
    }
}

LotteryControl::LotteryControl(const LotteryControl& orig) {
}

LotteryControl::~LotteryControl() {
}

char LotteryControl::results(const int number) {
    for(std::vector<int>::iterator it = lottery->getTicket()->getTicket().begin(); it !=lottery->getTicket()->getTicket().end(); it++) {
        for(int i = 0; i < lottery->getTicket()->getTicket().size(); i++)
        if(number == lottery->getTicket()->getTicket()[i]) {
            return '#';
        } else {
            return ' ';
        }
    }
}