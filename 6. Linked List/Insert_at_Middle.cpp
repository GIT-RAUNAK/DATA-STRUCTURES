#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to print linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr) {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 89, 3, 2, 5, 1, 7, 5, 8, 53, 0};
    int pos, val;

    cout << "Enter the position and value to be inserted respectively:\n";
    cin >> pos >> val;

    Node* head = NULL;
    Node* tail = NULL;

    // Build linked list from vector
    for (int i = 0; i < arr.size(); i++) {
        if (head == NULL) {
            head = new Node(arr[i]);
            tail = head;
        } else {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
    }

    cout << "Original List:\n";
    printList(head);

    // Insert new node
    Node* newNode = new Node(val);
    if (pos == 0) { // insert at head
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Invalid position!\n";
            return 0;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    cout << "Updated List after insertion:\n";
    printList(head);

    return 0;
}
