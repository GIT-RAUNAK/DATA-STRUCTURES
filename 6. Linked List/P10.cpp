// DELETE A NODE WITHOUT HEAD POINTER

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

void deleteNode(Node* del_node) {
    Node* temp = del_node->next;
    del_node->data = temp->data;
    del_node->next = temp->next;
    delete temp;
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
    cout << "\nEnter position of node to delete (1-indexed): ";
    cin >> pos;

    Node* target = head;
    for (int i = 1; i < pos; i++) {
        target = target->next;
    }

    cout << "\nDeleting node with value: " << target->data << "\n";

    deleteNode(target);

    cout << "\nOriginal Linked List:\n";
    printList(head);

    cout << "\nLinked List after deletion:\n";
    printList(head);

    return 0;
}