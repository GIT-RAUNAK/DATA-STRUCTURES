// Find data of node at position ceil(n/k)

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

int fractionalNode(Node* head, int k) {

    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    int req = (count + k - 1) / k;

    temp = head;
    while (--req) {
        temp = temp->next;
    }

    return temp->data;
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
    cout << "Enter K: ";
    cin >> k;

    int result = fractionalNode(head, k);
    cout << "Fractional Node (ceil(n/" << k << ") = " 
         << "position " << (n + k - 1) / k << "): " 
         << result << endl;

    return 0;
}