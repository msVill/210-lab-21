#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;
// Requirements: mod. so that each node has a Goat class object.

// Constructor 1: (Default) randomly assign age: 1-20. name: from the 15 element array.
// color: from the 15 element array.

// TASK: In main(): create a DoublyLinkedList obj. Add it to a random nuber of Goat obj., range 5-20 ~
// TASK: In main(): call the methods to print both forward and backward
// TASK: use srand(time(0)), as one of the first lines in main() to randomize your random numbers.
const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class Goat {
    private:
    int age;
    string name;
    string color;

    string names[15] = {
        "Saige", "Bowen", "Leighton", "Kylan", "Amelie",
        "Franklin", "Marceline", "Jaylen", "Saoirse","Dilan",
        "Jolene","Antonio","Keily","Lucian","Scarlett"
    };
    string colors[15] = {
        "White","Black","Brown","Gold","Silver",
        "Red","Gray","Spotted","Cream","Tan",
        "Blue","Mauve","Yellow","Orange","Purple"
    };

    public:
    // Constructors:
    //default constructor
    Goat() {
        // needs to be randomly selected:
        age = rand() % 20 + 1;
        name = names[rand() % 15]; // wait. this is an array, so I will need to place it within the brackets.
        color = colors[rand() % 15];
    }

    // parameter constructor
    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }

    void print() {
        cout << name << " (" << color << ", " << age << ")";
    }

};

class DoublyLinkedList
{
private:
    struct Node
    {
        Goat data;
        Node *prev;
        Node *next;
        Node(Goat val, Node *p = nullptr, Node *n = nullptr)
        {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node *head;
    Node *tail;

public:
    // constructor
    DoublyLinkedList()
    {
        head = nullptr; // I updated these incorrectly before. Found my error
        tail = nullptr;
    }
    void push_back(Goat value) //take Goat parameter.
    {
        Node *newNode = new Node(value);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void push_front(Goat value) // take Goat parameter.
    {
        Node *newNode = new Node(value);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        if(!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = head;

        while (current) {
            cout << "  ";
            current->data.print();
            cout << endl;
            current = current->next;
        }
    }
    void print_reverse()
    {
        if(!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = tail;
        while (current) {
            cout << "  ";
            current->data.print();
            cout << endl;
            current = current->prev;
        }
        cout << endl;
    }
    ~DoublyLinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
// Driver program
int main()
{
    srand(time(0));

    DoublyLinkedList herd;

    int numGoats = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS;

    for (int i = 0; i < numGoats; ++i) {

      Goat g;
      herd.push_back(g);

    }

    cout << "Forward:" << endl;
    herd.print();

    cout << "Backward:" << endl;
    herd.print_reverse();

    return 0;
}
