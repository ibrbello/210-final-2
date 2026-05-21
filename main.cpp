// COMSC-210 | Final Part 2 | Ibrahim Bello
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include "DLL.h"
using namespace std;

void print_deque(deque<string> const &);
const int NUM_ROUNDS = 5;

int main() {
    // Milestone 1
    // This is just to make sure the data structure works. 
    // Initialize line to 3 people
    srand(time(0));
    DoublyLinkedList coffeeLine;
    deque<string> muffinsLine;

    // Assuming deque should also be initialized to 3 people
    for (int i = 0; i < 3; i++) {
        coffeeLine.push_back();
        muffinsLine.push_back(names[rand() % NUM_NAMES]);
    }

    cout << "\nBREAKFAST BOOTH QUEUE SIMULATION\n";
    cout << "Initial coffee queue:\n";
    coffeeLine.print();
    cout << "Initial blueberry muffin stand queue:\n";
    print_deque(muffinsLine);
    
    // Milestone 2
    for (int i = 1; i <= NUM_ROUNDS; i++ ) {
        cout << "Round #" << i << ": \n";
        // Always serve a customer
        coffeeLine.pop_front();
        if (muffinsLine.empty()) cout << "Muffin stand line is empty.\n";
        else muffinsLine.pop_front();

        // 50% chance of a customer joining
        int prob = rand() % 100;
        if (prob > 50) {
            coffeeLine.push_back();
        }
        // Make probabilities independent
        int prob2 = rand() % 100;
        if (prob2 > 50) {
            muffinsLine.push_back(names[rand() % NUM_NAMES]);
        }

        cout << "\nCurrent coffee line: \n";
        coffeeLine.print();
        cout << "\n Current muffin stand line:\n";
        print_deque(muffinsLine);
    }

    // Milestone 3: New booth using deque
    // Steps: create deque, with just names (this vendor only sells blueberry muffins, so no orders)
    // Then use methods to add/remove people from queue, within the main loop

    return 0;
}

void print_deque(deque<string> const & dq) {
    for (const auto & item: dq) {
        cout << item << endl;
    }
}
