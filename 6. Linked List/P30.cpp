// REVERSE A DOUBLY LINKED LIST

#include <iostream>
#include <vector>
using namespace std;

// Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class Solution {
  public:
    Node *reverse(Node *head) {
        Node *temp = head;
        Node *curr = NULL;
        while (temp) {
            curr = temp;
            Node* temp3 = temp->next;
            swap(temp->next, temp->prev);
            temp = temp3;
        }
        return curr;
    }
};

// Helper function to print the list forward
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to print the list backward (verifies prev pointers work)
void printListReverse(Node* tail) {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    // Creating a sample Doubly Linked List: 10 <-> 20 <-> 30 <-> 40
    vector<int> values = {10, 20, 30, 40};
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int val : values) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    cout << "Original List Forward : ";
    printList(head);

    // Run your solution
    Solution ob;
    Node* newHead = ob.reverse(head);

    cout << "Reversed List Forward : ";
    printList(newHead);

    // Find the new tail to check if prev connections survived the swap
    Node* newTail = newHead;
    while (newTail && newTail->next != nullptr) {
        newTail = newTail->next;
    }

    cout << "Reversed List Backward: ";
    printListReverse(newTail);

    // Free memory
    Node* current = newHead;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}
