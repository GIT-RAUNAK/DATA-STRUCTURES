// INTERSECTION OF TWO SORTED LINKED LISTS

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

Node* findIntersection(Node* head1, Node* head2) {

    Node* temp1   = head1;
    Node* temp2   = head2;
    Node* newHead = NULL;

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            Node* newNode = new Node(temp1->data);

            if (newHead == NULL) {
                newHead = newNode;
            } else {
                Node* temp3 = newHead;
                while (temp3->next) {
                    temp3 = temp3->next;
                }
                temp3->next = newNode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->data > temp2->data) {
            temp2 = temp2->next;
        }
        else {
            temp1 = temp1->next;
        }
    }

    return newHead;
}

int main() {

    int n1;
    cout << "Enter number of nodes in List 1: ";
    cin >> n1;

    Node* head1 = NULL;
    cout << "Enter elements of List 1 (sorted): ";
    for (int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (head1 == NULL) {
            head1 = newNode;
        } else {
            Node* temp = head1;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }

    int n2;
    cout << "Enter number of nodes in List 2: ";
    cin >> n2;

    Node* head2 = NULL;
    cout << "Enter elements of List 2 (sorted): ";
    for (int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (head2 == NULL) {
            head2 = newNode;
        } else {
            Node* temp = head2;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }
    }

    cout << "List 1: ";
    Node* temp = head1;
    while (temp != NULL) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;

    cout << "List 2: ";
    temp = head2;
    while (temp != NULL) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;

    Node* result = findIntersection(head1, head2);

    cout << "Intersection: ";
    if (result == NULL) {
        cout << "No common elements!" << endl;
    } else {
        temp = result;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}