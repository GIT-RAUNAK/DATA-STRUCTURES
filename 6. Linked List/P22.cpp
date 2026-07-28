// REMOVE DUPLICATES FROM UNSORTED LINKED LIST

#include <iostream>
#include <unordered_map>
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

    unordered_map<int, int> mpp;
    Node* temp = head;
    Node* prev = nullptr;

    while (temp) {
        if (mpp.count(temp->data)) {
            prev->next  = temp->next;
            Node* temp2 = temp;
            temp        = temp->next;
            delete temp2;
        } else {
            mpp[temp->data] = 1;
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