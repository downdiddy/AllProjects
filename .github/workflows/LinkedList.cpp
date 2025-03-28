/*
Nihal Puchakatla
LinkedList.cpp
3/22/2025
version 1.1
This program implements a linked list with operations to add nodes at start, end,
and middle, delete nodes, search for nodes and more.
*/
#include <iostream>
#include <cmath>
#include <cctype>
#include <iomanip>
using namespace std;
// Node class to represent each element in the linked list
class Node {
    public:
    int data; // Stores the value of the node
    Node* next; // Pointer to the next node in the list
    Node() {
    // Default constructor
    }
    Node(int d) {
    data = d;
    next = nullptr; // Initialize next pointer to null
    }
};
string toLower(string check) {
    string loweredCheck;
    for (char c : check) {
    loweredCheck += tolower(c);
    }
    return loweredCheck;
}
// LinkedList class to manage the linked list operations
class LinkedList {
    struct node {
        int data;
        Node* next;
    };
    private:
        Node* head; // Pointer to the first node in the list
    public:
        // Constructor initializes an empty list
        LinkedList() {
            head = nullptr;
        }
        int getSize();
        // Adds a node at specified position (start or end)
        void addNode(int a, string where) {
            // Convert input string to lowercase for case-insensitive comparison
            string lowerForm = toLower(where);
            if (lowerForm == "start") { // Add node at the beginning
                Node* n = new Node(a);
                if (head == NULL) {
                    head = n;
                    head->next = nullptr;
                }
                else {
                    n->next = head; // Link new node to current head
                    head = n; // Make new node the head
                }
            }
            else if (lowerForm == "end") { // Add node at the end
                Node* n = new Node(a);
                if (head == NULL) {
                    head == n;
                    n->next = nullptr;
                }
                else {
                    // Traverse to the last node
                    Node* curr = head;
                    while (curr->next != nullptr) {
                        curr = curr->next;
                    }
                    curr->next = n; // Link last node to new node
                    n->next = NULL;
                }
            }
        }
        // Adds a node in the middle of the list using fast/slow pointer technique
        void addNode(int a) {
            Node* n = new Node(a);
            // Handle empty list case
            if (head == nullptr) {
                head = n;
                return;
            }
            // Initialize pointers for finding middle
            Node* slow = head; // Moves one step at a time
            Node* fast = head; // Moves two steps at a time
            Node* prev = nullptr; // Keeps track of node before slow
            // Find middle of list using fast/slow pointer technique
            while (fast != nullptr && fast->next != nullptr) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            // Insert new node
            if (prev == nullptr) {
                // If list has only one node
                n->next = head;
                head = n;
            }
            else {
                // Insert in middle
                if(getSize()%2 == 0){
                    n->next = slow;
                    prev->next = n;
                }
                else{
                    n->next = slow->next;
                    slow -> next = n;
                }
            }
        }
        // Deletes a node with specified value
        void delNode(int a) {
        Node* temp = head;
        Node* curr = head;
        // Handle case where head node needs to be deleted
        if (head != NULL && head->data == a) {
            head = head->next;
            delete temp;
            cout << "The value " << a << " has been deleted.\n";
            return;
        }
        // Search for node to delete
        while (curr != NULL && curr->data != a) {
            temp = curr;
            curr = curr->next;
        }
        // If value not found
        if (curr == NULL) {
            cout << a << " is not on the list\n";
            return;
        }
        // Delete the node and maintain list structure
        temp->next = curr->next;
        delete curr;
        cout << "The value " << a << " has been deleted.\n";
        }
        int getSize() {
            int num = 0;
            Node* curr = head;
            while (curr != nullptr) {
                num++;
                curr = curr->next;
            }
            return num;
        }
        bool search(int a){
            Node* curr = head;
            // Search for node
            while (curr != NULL && curr->data != a) {
                curr = curr->next;
            }
            // If value not found
            if (curr == NULL)
                return false;
            else //if value is found
                return true;
        }
        void orderList() {
            if (head == nullptr || head->next == nullptr) {
                cout << "The list is either empty or only has one item in it";
            }
            Node* curr = head;
            Node* in = nullptr;
            int temp;
            //sorting
            while (curr != nullptr) {
                in = curr->next;
                while (in != nullptr) {
                if (curr->data > in->data) {
                    //sawp
                    temp = curr->data;
                    curr->data = in->data;
                    in->data = temp;
                    }
                    in = in->next;
                    }
                    curr = curr->next;
            }
        }
        // Displays all nodes in the list
        friend ostream& operator<<(ostream& O, const LinkedList& f) {
            if (f.head == nullptr) {
                O << "It's an empty list\n";
        }
        else {
            Node* curr = f.head;
            while (curr != nullptr) {
                O << curr->data << endl;
                curr = curr->next;
            }
        }
        return O;
        }
        bool isEmpty() const {
            return head == nullptr;
        }
};
// Main function to test the linked list implementation
int main() {
    int count;
    LinkedList f1;
    cout << "How many numbers in this list?: ";
    cin >> count;
    for (int i = 1; i <= count; i++) {
        int a;
        cout << "What is data number " << i << "?: ";
        cin >> a;
        f1.addNode(a);
    }
    string check;
    cout << "Would you like to add or delete any number? (Yes or No): ";
    cin >> check;
    string loweredCheck = toLower(check);
    if (loweredCheck == "yes") {
        string exit = "";
        string lexit = "";
        while (lexit != "yes") {
            cout << "delete or add?: ";
            cin >> check;
            loweredCheck = toLower(check);
            if (loweredCheck == "add") {
                int add;
                string locate;
                cout << "Where would you like to add it? (first, middle or last): ";
                cin >> locate;
                string loweredLocate = toLower(locate);
                cout << "What number would you like to add?: ";
                cin >> add;
                if (loweredLocate == "first")
                    f1.addNode(add, "START");
                else if (loweredLocate == "middle")
                    f1.addNode(add);
                else if (loweredLocate == "last")
                    f1.addNode(add, "END");
                cout << "Would you like to exit? ";
                cin >> exit;
                lexit = toLower(exit);
            }
            else if (loweredCheck == "delete") {
                if (!f1.isEmpty()) {
                    int del;
                    f1.orderList();
                    cout << "These are all your numbers\n" << f1 << "\
                    nWhich one would you like to remove?: ";
                    cin >> del;
                    f1.delNode(del);
                }
                else {
                    cout << "The list is empty. Cannot delete.\n";
                }
                cout << "Would you like to exit? ";
                cin >> exit;
                lexit = toLower(exit);
            }
        }
    }
    cout << "Would you like to search for a number in thie list?: ";
    cin >> check;
    loweredCheck = toLower(check);
    if (check == "yes") {
        int search;
        cout << "What number would you like to search?: ";
        cin >> search;
        if (f1.search(search))
            cout << "The number does exist in the list.\n";
        else
            cout << "The number does not exist in the list.\n";
    }
    f1.orderList();
    cout << "Thank you for the list, here is the final list ordered from least to greatest: \n" << f1;
    cout << "The size of the list is " << f1.getSize();
}
