// REMOVE DUPLICATES FROM SORTED LINKED LIST

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

Node* removeDuplicates(Node* head) {

    Node* temp = head->next;
    Node* prev = head;

    while (temp) {
        if (temp->data == prev->data) {
            // duplicate found — delete it
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            // no duplicate — move forward
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;

    cout << "Enter elements (sorted): ";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Original Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    head = removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}