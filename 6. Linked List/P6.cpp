// INSERT A NODE IN A SORTED LINKED LIST

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* sortedInsert(Node* head, int key) {

    Node* newNode = new Node(key);

    if (head == NULL || head->data > key) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;

    while (temp->next != NULL) {

        if (temp->next->data > key) {
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }

        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter elements in sorted order:\n";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "\nOriginal Linked List:\n";
    printList(head);

    int key;
    cout << "\nEnter the value to insert: ";
    cin >> key;

    head = sortedInsert(head, key);

    cout << "\nLinked List after insertion:\n";
    printList(head);

    return 0;
}