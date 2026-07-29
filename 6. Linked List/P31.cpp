// DETECT LOOP IN LINKED LIST (FLOYD'S ALGORITHM)

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

bool detectLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) return true;
    }

    return false;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail       = newNode;
        }
    }

    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    int pos;
    cout << "Enter position to create loop (0 = no loop): ";
    cin >> pos;

    if (pos != 0) {
        temp        = head;
        int steps   = pos - 1;
        while (steps--) {
            temp = temp->next;
        }
        tail->next = temp;
        cout << "Loop created: last node connects back to position " << pos << endl;
    }

    if (detectLoop(head)) {
        cout << "Loop Detected: YES" << endl;
    } else {
        cout << "Loop Detected: NO" << endl;
    }

    return 0;
}