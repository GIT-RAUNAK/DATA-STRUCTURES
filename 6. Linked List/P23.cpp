// FIND LENGTH OF LOOP IN LINKED LIST

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

int lengthOfLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

    // Step 1: detect loop using Floyd's algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            // Step 2: count length of loop
            int count  = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    // no loop found
    return 0;
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

    // CREATE LOOP for testing
    int pos;
    cout << "Enter position to create loop (0 = no loop): ";
    cin >> pos;

    if (pos != 0) {
        // connect tail to pos-th node (1-indexed)
        Node* temp  = head;
        int   steps = pos - 1;
        while (steps--) {
            temp = temp->next;
        }
        tail->next = temp;    // create loop
        cout << "Loop created: last node connects back to position " << pos << endl;
    }

    cout << "Original Linked List: ";
    if (pos == 0) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    } else {
        // can't print full list with loop (infinite)
        // print only n nodes
        Node* temp  = head;
        int   steps = n;
        while (steps--) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "... (loop)" << endl;
    }

    int result = lengthOfLoop(head);

    if (result == 0) {
        cout << "No loop found!" << endl;
    } else {
        cout << "Length of Loop: " << result << endl;
    }

    return 0;
}