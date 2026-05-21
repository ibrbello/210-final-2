// COMSC-210 | Final Part 2 | Ibrahim Bello
#include <iostream>
#include <fstream>
#include <list>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include "DLL.h"
using namespace std;
const int NUM_ROUNDS = 10;
const int ARR_SIZE = 50;

void print_deque(deque<string> const &);
void print_vector(vector<string> const &);
void print_queue(queue<string> );

int main() {
    cout << "\n=========BREAKFAST BOOTH QUEUE SIMULATION==========\n";
    srand(time(0));
    DoublyLinkedList coffeeLine;
    deque<string> muffinsLine;
    vector<string> braceletsLine;
    queue<string> croissantsLine;

    for (int i = 0; i < 3; i++) {
        coffeeLine.push_back();
        muffinsLine.push_back(names[rand() % NUM_NAMES]);
        braceletsLine.push_back(names[rand() % NUM_NAMES]);
        croissantsLine.push(names[rand() % NUM_NAMES]);
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
    cout << "Initial croissant shop queue:\n";
    print_queue(croissantsLine);
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

        if (croissantsLine.empty()) cout << "There's no one to serve in the croissant shop line.\n";
        else { 
            croissantsLine.pop();
            cout << "Croissant shop customer served.\n";
        }

        // 50% chance of a customer joining any of the lines
        int prob = rand() % 100;
        if (prob > 50) {
            coffeeLine.push_back();
        }
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

        int prob4 = rand() % 100;
        if (prob4 > 50) {
            croissantsLine.push(names[rand() % NUM_NAMES]);
            cout << "Customer joined the croissant shop line.\n";
        }

        cout << "\nCurrent coffee line: \n";
        coffeeLine.print();
        cout << "\nCurrent muffin stand line:\n";
        print_deque(muffinsLine);
        cout << "\nCurrent bracelet stand line:\n";
        print_vector(braceletsLine);
        cout << "\nCurrent croissant shop line:\n";
        print_queue(croissantsLine);
    }

    // Arrays are finicky. Maps and sets automatically sort, so that doesn't fit the 
    // store queue use case. Graphs and hash tables don't really work either
    // std:queue has been studied in the Zybook, so I think it counts as a structure 
    // studied in the course
    // Milestone 5: add std::queue queue for croissant stand
    // Once again, only one type of croissant, so everyone's order is the same

    return 0;
}

void print_deque(deque<string> const & dq) {
    for (const auto & item: dq) cout << item << endl;
}
void print_vector(vector<string> const & vec) {
    for (const auto & item : vec) cout << item << endl;
}
void print_queue(queue<string> q) {
    // continously print the first item, then remove it to print the 
    // entire queue
    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }
}
