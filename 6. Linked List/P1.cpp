// PRINT LINKED LIST

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;

    cout << "Enter the elements: ";

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

    vector<int> result;

    Node* temp = head;
    while (temp != NULL) {
        result.push_back(temp->data);
        temp = temp->next;
    }

    cout << "Linked List Elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}