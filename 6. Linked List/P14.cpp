// REMOVE NTH NODE FROM END OF LINKED LIST

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

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;

    cout << "Enter elements: ";

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

    int k;
    cout << "Enter N (remove Nth node from end): ";
    cin >> k;

    temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (count == k) {
        Node* newHead = head->next;
        delete head;
        head = newHead;
        cout << "Updated Linked List: ";
        temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        return 0;
    }

    temp = head;
    int req = count - k - 1;
    while (req--) {
        temp = temp->next;
    }

    Node* temp2 = temp->next;
    temp->next  = temp2->next;
    delete temp2;

    cout << "Updated Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}