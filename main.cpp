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
void print_vector(vector<string> const &);

const int NUM_ROUNDS = 10;

int main() {
    cout << "\n=========BREAKFAST BOOTH QUEUE SIMULATION==========\n";
    srand(time(0));
    DoublyLinkedList coffeeLine;
    deque<string> muffinsLine;
    vector<string> braceletsLine;

    for (int i = 0; i < 3; i++) {
        coffeeLine.push_back();
        muffinsLine.push_back(names[rand() % NUM_NAMES]);
        braceletsLine.push_back(names[rand() % NUM_NAMES]);
        cout << endl;
    }

    cout << "Initial coffee queue:\n";
    coffeeLine.print();
    cout << "Initial blueberry muffin stand queue:\n";
    print_deque(muffinsLine);
    cout << endl;
    cout << "Initial friendship bracelet stand queue:\n";
    print_vector(braceletsLine);
    cout << endl;
    
    for (int i = 1; i <= NUM_ROUNDS; i++ ) {
        cout << "\n=======Round #" << i << "========\n";
        // Always serve a customer
        coffeeLine.pop_front();
        if (muffinsLine.empty()) cout << "There's no one to serve in the muffin stand line.\n";
        else { 
            muffinsLine.pop_front();
            cout << "Muffin stand customer served.\n";
        }
        if (braceletsLine.empty()) cout << "There's no one to serve in the bracelet stand line.\n";
        else { 
            braceletsLine.erase(braceletsLine.begin());
            cout << "Bracelet stand customer served.\n";
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

        int prob3 = rand() % 100;
        if (prob3 > 50) {
            braceletsLine.push_back(names[rand() % NUM_NAMES]);
            cout << "Customer joined the bracelet stand line.\n";
        }

        cout << "\nCurrent coffee line: \n";
        coffeeLine.print();
        cout << "\nCurrent muffin stand line:\n";
        print_deque(muffinsLine);
        cout << "\nCurrent bracelet stand line:\n";
        print_vector(braceletsLine);
    }
    // Milestone 4: Add vector queue
    // Steps: Create vector structure (again just names, all friendship bracelets are the same)
    // Do same thing that was done for the deque

    return 0;
}

void print_deque(deque<string> const & dq) {
    for (const auto & item: dq) cout << item << endl;
}

void print_vector(vector<string> const & vec) {
    for (const auto & item : vec) cout << item << endl;
}

