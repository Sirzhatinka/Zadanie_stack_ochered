//
// Created by mazur on 05.12.2020.
//

#include "qList.h"


qList::underflow::underflow() { std::cerr << "\nQueue is empty!\n"; }

void qList::showData(Node* ptr) {
    if (ptr)
        std::cout << "\nPoint to: " << ptr->data.pointTo << "\nFull name: "
                  << ptr->data.passengerFIO << "\nRace number: "
                  << ptr->data.numberRace << "\nDate out: "
                  << ptr->data.dayOut << '/'
                  << ptr->data.monthOut << '/'
                  << ptr->data.yearOut << '\n';
}

qList::~qList() {
    Node *temp = first;
    Node* curr;
    while (temp) {
        curr = temp->next;
        delete temp;
        temp = curr;
    }
}

void qList::addData() {
    if (counter) {
        auto nLink = new Node;
        last->next = nLink;
        last = nLink;
        last->next = nullptr;
    }
    else {
        auto nLink = new Node;
        first = last = nLink;
        first->next = nullptr;
    }

    std::cout << "\nAdding passenger."
                 "\npassengerFIO: ";
    std::getline(std::cin, last->data.passengerFIO);
    std::cout << "Point to: ";
    std::getline(std::cin, last->data.pointTo);
    std::cout << "Race number: ";
    std::cin >> last->data.numberRace;

    char dummy;
    std::cout << "Data out as dd/mm/yyyy: ";
    std::cin >> last->data.dayOut >> dummy
             >> last->data.monthOut >> dummy >> last->data.yearOut;
    counter++;
}

airTickets qList::getData() {
    if (counter > 1) {
        airTickets temp = first->data;

        auto tempPtr = first->next;
        delete first;
        first = tempPtr;

        counter--;
        return temp;
    }
    else if (counter == 1) {
        airTickets temp = first->data;

        delete first;
        first = last = nullptr;

        counter--;
        return temp;
    }
    else
        throw underflow();
}

void qList::deleteData() {
    auto curr = first;
    first = nullptr;
    while (curr) {
        auto temp = curr;
        curr = curr->next;
        delete temp;
    }
}

void qList::showRaceAndData() {
    char dummy;
    int d, m, y;
    std::cout << "Enter the data you're interested as dd/mm/yyyy: ";
    std::cin >> d >> dummy >> m >> dummy >> y;

    long long num;
    std::cout << "Enter the race: ";
    std::cin >> num;
    auto curr = first;
    int8_t count = 0;
    while (curr) {
        bool date = curr->data.dayOut == d && curr->data.monthOut == m && curr->data.yearOut == y;
        if (date && curr->data.numberRace == num) {
            std::cout << "\nHere it is:\n";
            showData(curr);

            auto &refCount = count;
            refCount++;
        }
        curr = curr->next;
    }
    if (!count)
        std::cout << "\nNo such races.\n";
}

void qList::showAll() {
    auto curr = first;
    std::cout << "Showing all:\n";
    int8_t count = 0;
    while (curr) {
        showData(curr);
        curr = curr->next;
        int8_t &refCount = count;
    }
    if (!count)
        std::cout << "List is empty.";
}