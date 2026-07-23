// INSERT A NODE IN THE MIDDLE OF A LINKED LIST

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* insertInMiddle(Node* head, int x) {

    Node* newNode = new Node(x);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    int k = (count - 1) / 2;

    temp = head;

    for (int i = 0; i < k; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
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

    cout << "Enter elements:\n";

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

    int value;
    cout << "\nEnter the value to insert: ";
    cin >> value;

    head = insertInMiddle(head, value);

    cout << "\nLinked List after insertion:\n";
    printList(head);

    return 0;
}