// SORTED INSERT IN CIRCULAR LINKED LIST

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to " << head->data << ")" << endl;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next    = newNode;
    newNode->next = head;
    return head;
}

Node* sortedInsert(Node* head, int data) {
    Node* newNode = new Node(data);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    if (head->data > data) {
        Node* curr = head;
        while (curr->next != head) {
            curr = curr->next;
        }
        curr->next    = newNode;
        newNode->next = head;
        head          = newNode;
        return head;
    }

    Node* temp = head;
    while (temp->next != head && temp->next->data < data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next    = newNode;

    return head;
}

int main() {

    Node* head = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements (need not be sorted): ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtEnd(head, x);
    }

    cout << "\nOriginal Circular Linked List:" << endl;
    printList(head);

    int data;
    cout << "\nEnter value to insert (sorted): ";
    cin >> data;

    head = sortedInsert(head, data);

    cout << "\nAfter Sorted Insert of " << data << ":" << endl;
    printList(head);

    return 0;
}