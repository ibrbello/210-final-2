#ifndef DLL.H
#define DLL.H
#include <iostream>
using namespace std;

// Copied from Lab 22
class DoublyLinkedList {
    private:
        struct Node {
            string name;
            string drink;
            Node* prev;
            Node* next;
            Node(string nm, string d, Node* p = nullptr, Node* n = nullptr) {
                name = nm;
                drink = d;
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
    
        void push_back(string nm, string drink) {
            Node* newNode = new Node(nm, drink);
            if (!tail)  // if there's no tail, the list is empty
                head = tail = newNode;
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void pop_front() {
            if (!head) {
                cout << "List is empty." << endl;
                return;
            }
            Node* temp = head;
            temp->next->prev = nullptr; 
            head = temp->next;
            delete temp;
            cout << "Node deleted." << endl << endl;
    
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