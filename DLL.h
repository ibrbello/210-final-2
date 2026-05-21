
#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;

const int NUM_NAMES = 50;
const std::string names[NUM_NAMES] = {
    "James",   "Oliver",  "Noah",    "Liam",    "Ethan",
    "Lucas",   "Mason",   "Logan",   "Aiden",   "Jackson",
    "Emma",    "Sophia",  "Olivia",  "Ava",     "Isabella",
    "Mia",     "Harper",  "Amelia",  "Evelyn",  "Abigail",
    "Carlos",  "Jimmy",  "Devon",   "Jordan",  "Tyler",
    "Brandon", "Trevor",  "Derek",   "Dustin",  "Kyle",
    "Amber",   "Brianna", "Chelsea", "Tiffany", "Kristen",
    "Megan",   "Ashley",  "Lauren",  "Shannon", "Brooke",
    "Ahmed",   "Diego",   "Marcus",  "Victor",  "Andre",
    "Priya",   "Maya",    "Leila",   "Elena",   "Nadia"
};

const int NUM_DRINKS = 20;
const std::string drinks[NUM_DRINKS] = {
    "Espresso",           "Americano",          "Flat white",
    "Cold brew",          "Oat latte",          "Cortado",
    "Cappuccino",         "Matcha latte",        "Iced mocha",
    "Macchiato",          "Vanilla latte",       "Drip coffee",
    "Caramel cortado",    "Dirty chai",          "Pour over",
    "Ristretto",          "Honey latte",         "Nitro cold brew",
    "Iced americano",     "Hazelnut cappuccino"
};


// Copied from Lab 22
class DoublyLinkedList {
    private:
        struct Node {
            string name;
            string drink;
            Node* prev;
            Node* next;
            Node(Node* p = nullptr, Node* n = nullptr) {
                name = names[rand() % NUM_NAMES];
                drink = drinks[rand() % NUM_DRINKS];
                prev = p;
                next = n;
            }
        };
    
        Node* head;
        Node* tail;

// Operations I need:
// Push back, pop front
// No searching needed, no deleting values
    
    public:
        // constructor
        DoublyLinkedList() { head = nullptr; tail = nullptr; }
    
        void push_back() {
            Node* newNode = new Node();
            if (!tail)  // if there's no tail, the list is empty
                head = tail = newNode;
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            cout << newNode->name << " with order: " << newNode->drink <<
            " has joined the line.\n";
        }

        void pop_front() {
            if (!head) {
                cout << "There's no one to serve.\n" << endl;
                return;
            }
            Node* temp = head;
            temp->next->prev = nullptr; 
            head = temp->next;
            delete temp;
            cout << "Customer served." << endl << endl;
    
        }

        void print() {
            Node* current = head;
            if (!current) return;
            while (current) {
                cout << current->name << " " << current->drink << endl;
                current = current->next;
            }
            cout << endl << endl;
        }
    
        void print_reverse() {
            Node* current = tail;
            if (!current) return;
            while (current) {
                cout << current->name << " " << current->drink << endl;
                current = current->prev;
            }
            cout << endl << endl;
        }
    
        ~DoublyLinkedList() {
            while (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
    
        // void push_front(string nm, string drink) {
        //     Node* newNode = new Node(value);
        //     if (!head)  // if there's no head, the list is empty
        //         head = tail = newNode;
        //     else {
        //         newNode->next = head;
        //         head->prev = newNode;
        //         head = newNode;
        //     }
        // }
    
        // void insert_after(string nm, string drink, int position) {
        //     if (position < 0) { // input check
        //         cout << "Position must be >= 0." << endl;
        //         return;
        //     }
    
        //     Node* newNode = new Node(value);
        //     if (!head) { 
        //         head = tail = newNode;
        //         return;
        //     }
    
        //     Node* temp = head;
        //     for (int i = 0; i < position && temp; ++i)
        //         temp = temp->next;
    
        //     if (!temp) {
        //         cout << "Position exceeds list size. Node not inserted.\n";
        //         delete newNode;
        //         return;
        //     }
    
        //     newNode->next = temp->next;
        //     newNode->prev = temp;
        //     if (temp->next)
        //         temp->next->prev = newNode;
        //     else
        //         tail = newNode; // Inserting at the end
        //     temp->next = newNode;
        // }
    
        // void delete_val(string nm, string drink) {
        //     if (!head) {
        //         cout << "List is empty." << endl;
        //         return;
        //     }
    
        //     Node* temp = head;
        //     while (temp && temp->data != value)
        //         temp = temp->next;
    
        //     if (!temp) {
        //         cout << "Value not found." << endl << endl;
        //         return;
        //     } 
    
        //     if (temp->prev) {
        //         temp->prev->next = temp->next;
        //     } else {
        //         head = temp->next; // Deleting the head
        //     }
    
        //     if (temp->next) {
        //         temp->next->prev = temp->prev;
        //     } else {
        //         tail = temp->prev; // Deleting the tail
        //     }
    
        //     delete temp;
        //     cout << "Node deleted." << endl << endl;
        // }

        // void delete_pos(int pos) {
        //     if (!head) {
        //         cout << "List is empty." << endl;
        //         return;
        //     }
    
        //     Node* temp = head;
        //     for (int i = 0; i < pos; i++) {
        //         temp = temp->next;
        //         if (!temp) { // Check if temp is nullptr before it goes out of range
        //             cout << "Position is outside of list range. Node not deleted.";
        //             cout << endl << endl;
        //             return;
        //         }
        //     }
        //     if (temp->prev) {
        //         temp->prev->next = temp->next;
        //     } else {
        //         head = temp->next; // Deleting the head
        //     }
    
        //     if (temp->next) {
        //         temp->next->prev = temp->prev;
        //     } else {
        //         tail = temp->prev; // Deleting the tail
        //     }
    
        //     delete temp;
        //     cout << "Node deleted." << endl << endl;
        // }



        // void pop_back() {
        //     if (!tail) {
        //         cout << "List is empty." << endl;
        //         return;
        //     }
        //     Node* temp = tail;
        //     temp->prev->next = nullptr; 
        //     tail = temp->prev;
        //     delete temp;
        //     cout << "Node deleted." << endl << endl;
    
        // }
    
    };

#endif