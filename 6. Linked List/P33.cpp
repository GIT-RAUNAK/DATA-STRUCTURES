// SPLIT CIRCULAR LINKED LIST INTO TWO HALVES

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* head) {
    if (head == NULL) {
        cout << "NULL" << endl;
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

pair<Node*, Node*> splitList(Node* head) {

    if (head == NULL || head->next == head) {
        return {head, nullptr};
    }

    int count  = 1;
    Node* temp = head;
    while (temp->next != head) {
        count++;
        temp = temp->next;
    }

    int mid = (count + 1) / 2;

    temp = head;
    for (int i = 1; i < mid; i++) {
        temp = temp->next;
    }

    Node* temp2 = temp->next;    // head of second half
    temp->next  = head;          // close first half circle

    temp = temp2;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = temp2;          // close second half circle

    return {head, temp2};
}

int main() {

    Node* head = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtEnd(head, x);
    }

    cout << "\nOriginal Circular Linked List:" << endl;
    printList(head);

    pair<Node*, Node*> result = splitList(head);
    Node* head1 = result.first;
    Node* head2 = result.second;

    cout << "\nFirst  Half: ";
    printList(head1);

    cout << "Second Half: ";
    printList(head2);

    return 0;
}