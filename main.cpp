// COMSC-210 | Final Part 2 | Ibrahim Bello
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include "DLL.h"
using namespace std;

const int NUM_ROUNDS = 10;

int main() {
    // Milestone 1
    // This is just to make sure the data structure works. 
    // Initialize line to 3 people
    srand(time(0));
    DoublyLinkedList line;
    for (int i = 0; i < 3; i++) {
        line.push_back();
    }
    cout << "COFFEE BOOTH QUEUE SIMULATION\n";
    cout << "Initial coffee queue:\n";
    line.print();

    for (int i = 0; i < NUM_ROUNDS; i++ ) {
        // Serve a customer
        line.pop_front();
        // 50% chance of a customer joining
        int prob = rand() % 100;
        if (prob > 50) {
            line.push_back();
        }
        cout << "\nCurrent line: \n";
        line.print();
    }

    return 0;
}