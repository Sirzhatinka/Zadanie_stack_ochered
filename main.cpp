#include <iostream>
#include "qList.h"

int main() {
    qList bilety;

    int choice;
    do {
        std::cout << "\nChoose the action."
                     "\n1. Add the ticket."
                     "\n2. Show all tickets with given date and race."
                     "\n3. Show all tickets."
                     "\n4. Delete the ticket."
                     "\n5. Delete all tickets."
                     "\n0. Exit.\n";
        (std::cin >> choice).get();
        if (choice == 1) {
            char answer;
            do {
                bilety.addData();

                std::cout << "\nElse? y/n: ";
                (std::cin >> answer).get();
            } while (answer == 'y');
        }
        else if (choice == 2)
            bilety.showRaceAndData();
        else if (choice == 3)
            bilety.showAll();
        else if (choice == 4) {
            try {
                bilety.getData();
                std::cout << "Deleting is complete.\n";
            } catch (qList::underflow&) { }
        }
        else if (choice == 5) {
            try {
                bilety.deleteData();
                std::cout << "Now, the list is clear.";
            } catch (qList::underflow&) { }
        }
        else if (!choice) break;

    } while (true);

    return 0;
}
