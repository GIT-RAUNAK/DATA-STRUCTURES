// LEFT ROTATE LINKED LIST BY K PLACES

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

int main() {

    int n1;
    cout << "Enter number of nodes: ";
    cin >> n1;
    Node* head = NULL;

    cout << "Enter elements: ";

    for (int i = 0; i < n1; i++) {
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

    int k;
    cout << "Enter k (left rotation count): ";
    cin >> k;

    temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (count == 1) {
        cout << "Rotated Linked List: ";
        temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return 0;
    }

    temp = head;
    k %= count;
    if (k == 0) {
        cout << "Rotated Linked List: ";
        temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return 0;
    }

    int n = k - 1;
    while (n--) {
        temp = temp->next;
    }

    Node* oldHead = head;
    Node* temp2   = temp->next;
    head          = temp2;
    temp->next    = NULL; 

    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = oldHead;

    cout << "Rotated Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}