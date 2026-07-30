// UNION OF TWO LINKED LISTS (USING HASHSET)

#include <iostream>
#include <unordered_set>
#include <vector>
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

Node* makeUnion(Node* head1, Node* head2) {

    unordered_set<int> seen;
    vector<int>        elements;

    Node* temp = head1;
    while (temp) {
        if (seen.find(temp->data) == seen.end()) {
            seen.insert(temp->data);
            elements.push_back(temp->data);
        }
        temp = temp->next;
    }

    temp = head2;
    while (temp) {
        if (seen.find(temp->data) == seen.end()) {
            seen.insert(temp->data);
            elements.push_back(temp->data);
        }
        temp = temp->next;
    }

    Node* newHead = NULL;
    Node* tail    = NULL;

    for (int x : elements) {
        Node* newNode = new Node(x);
        if (newHead == NULL) {
            newHead = newNode;
            tail    = newNode;
        } else {
            tail->next = newNode;
            tail       = newNode;
        }
    }

    return newHead;
}

int main() {

    int n1;
    cout << "Enter number of nodes in List 1: ";
    cin >> n1;

    Node* head1 = NULL;
    cout << "Enter elements of List 1: ";
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
    cout << "Enter elements of List 2: ";
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

    cout << "\nList 1: ";
    Node* temp = head1;
    while (temp != NULL) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;

    cout << "List 2: ";
    temp = head2;
    while (temp != NULL) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;

    Node* result = makeUnion(head1, head2);

    cout << "\nUnion:  ";
    temp = result;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}