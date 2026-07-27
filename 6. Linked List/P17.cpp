// SUM OF LAST N NODES OF LINKED LIST

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

int sumofNodes(Node* head, int n) {

    Node* temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }

    temp = head;
    int req = count - n;
    while (req--) {
        temp = temp->next;
    }

    int sum = 0;
    while (temp) {
        sum += temp->data;
        temp = temp->next;
    }

    return sum;
}

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

    cout << "Linked List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    int k;
    cout << "Enter N (sum of last N nodes): ";
    cin >> k;

    int result = sumofNodes(head, k);
    cout << "Sum of last " << k << " nodes: " << result << endl;

    return 0;
}