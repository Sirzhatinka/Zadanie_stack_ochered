//
// Created by mazur on 05.12.2020.
//

#ifndef ZADANIE_STACK_OCHERED_STACKLIST_H
#define ZADANIE_STACK_OCHERED_STACKLIST_H

#include <iostream>
#include <string>

struct airTickets {
    std::string pointTo;
    std::string passengerFIO;
    long long numberRace;
    int dayOut, monthOut, yearOut;
    airTickets(): numberRace(0LL), dayOut(0), monthOut(0), yearOut(0) { }
};


struct Node {
    Node *next;
    airTickets data;
    Node(): next(nullptr) { }
};


class qList {
    Node *first;
    Node *last;
    int counter;
    void showData(Node*);
public:
    qList(): first(nullptr), last(nullptr), counter(0) { }
    ~qList();

    void addData();
    airTickets getData();
    void deleteData();

    void showRaceAndData();

    void showAll();

    class underflow { public: underflow(); };

};




#endif //ZADANIE_STACK_OCHERED_STACKLIST_H
