// DELETE A NODE FROM THE LINKED LIST

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

Node* deleteNode(Node* head, int x) {
    if (head == NULL) return NULL;

    Node* temp = head;
    Node* prev = NULL;

    for (int i = 1; i < x; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
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
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pos;
    cout << "\nEnter position to delete (1-indexed): ";
    cin >> pos;

    cout << "\nOriginal Linked List:\n";
    printList(head);

    head = deleteNode(head, pos);

    cout << "\nLinked List after deletion:\n";
    printList(head);

    return 0;
}