/* 
 * File:   Lottery.cpp
 * 
 */

#include "Lottery.h"

Lottery::Lottery() {
    srand(time(0));
    setDrawing(false);
}

Lottery::Lottery(const Lottery& orig) {
}

Lottery::~Lottery() {
}

void Lottery::showMenu() {
    std::cout << "===" << " Lottery Menu " << "===" << std::endl
            << "1 Enter ticket" << std::endl
            << "2 Lottery drawing" << std::endl
            << "3 Show result" << std::endl
            << "0 Quit" << std::endl
            << "Please enter (0-3): ";
}

void Lottery::lotteryDrawing() {
    std::vector<int> lotteryNumbers;
    bool newNumber;
    const int SIZE = lottery->MAXNUMBERS;
    for(int i = 0; i < SIZE; i++) {
        int number;
        do {
            number = (rand() % 49 + 1);
            newNumber = true;
            for(int j = 0; j < i; j++) {
                if(lotteryNumbers[j] == number) {
                    newNumber = false;
                }
            }
        } while (!newNumber);
        lotteryNumbers.push_back(number);
    }
    for(int k = 0; k < lotteryNumbers.size(); k++) {
        std::cout << k + 1 << ". Number = " << lotteryNumbers[k] << std::endl;
    }
    std::cout << std::endl;
    lottery = new Ticket(lotteryNumbers);
    setDrawing(true);
}

Ticket* Lottery::getTicket() {
    return lottery;
}

bool Lottery::getDrawing() {
    return drawing;
}

void Lottery::setDrawing(bool drawing) {
    this->drawing = drawing;
}

void Lottery::getLotteryNumbers() {
    std::vector<int> tmp = lottery->getTicket();
    for(int i = 0; i < tmp.size(); i++) {
        std::cout << std::setw(7) << tmp[i] << " ";
    }
}