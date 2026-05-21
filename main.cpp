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
const int NUM_ROUNDS = 10;

int main() {
    cout << "\nBREAKFAST BOOTH QUEUE SIMULATION\n";
    srand(time(0));
    DoublyLinkedList coffeeLine;
    deque<string> muffinsLine;

    // Assuming deque should also be initialized to 3 people
    for (int i = 0; i < 3; i++) {
        coffeeLine.push_back();
        muffinsLine.push_back(names[rand() % NUM_NAMES]);
        cout << endl;
    }

    cout << "Initial coffee queue:\n";
    coffeeLine.print();
    cout << "Initial blueberry muffin stand queue:\n";
    print_deque(muffinsLine);
    
    for (int i = 1; i <= NUM_ROUNDS; i++ ) {
        cout << "Round #" << i << ": \n";
        // Always serve a customer
        coffeeLine.pop_front();
        if (muffinsLine.empty()) cout << "Muffin stand line is empty.\n";
        else { 
            muffinsLine.pop_front();
            cout << "Muffin stand customer served.\n";
        }

        // 50% chance of a customer joining
        int prob = rand() % 100;
        if (prob > 50) {
            coffeeLine.push_back();
        }
        // Make probabilities independent
        int prob2 = rand() % 100;
        if (prob2 > 50) {
            muffinsLine.push_back(names[rand() % NUM_NAMES]);
            cout << "Customer joined the muffin stand line.\n";
        }

        cout << "\nCurrent coffee line: \n";
        coffeeLine.print();
        cout << "\nCurrent muffin stand line:\n";
        print_deque(muffinsLine);
    }

    return 0;
}

void print_deque(deque<string> const & dq) {
    for (const auto & item: dq) cout << item << endl;
}
