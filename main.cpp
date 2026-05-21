// COMSC-210 | Final Part 2 | Ibrahim Bello
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <string>
#include "DLL.h"
using namespace std;

int main() {
    // Milestone 1
    // This is just to make sure the data structure works. 
    // Next milestone will run the simulation for 10 rounds
    cout << "COFFEE BOOTH QUEUE SIMULATION\n";
    cout << "Coffee queue:\n";
    srand(time(0));
    DoublyLinkedList line;
    for (int i = 0; i < 5; i++) {
        line.push_back();
    }
    line.print();

    return 0;
}