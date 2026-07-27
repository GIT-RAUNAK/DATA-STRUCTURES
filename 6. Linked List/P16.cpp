// CHECK IF LINKED LIST IS PALINDROME

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

Node* reverse(Node* head) {
    Node* temp  = head;
    Node* prev  = NULL;
    Node* temp2 = NULL;
    while (temp) {
        temp2      = temp->next;
        temp->next = prev;
        prev       = temp;
        temp       = temp2;
    }
    return prev;
}

bool isPalindrome(Node* head) {

    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (count == 1) return true;

    int mid = count / 2;
    temp = head;
    Node* prev = NULL;
    while (mid--) {
        prev = temp;
        temp = temp->next;
    }

    Node* temp2 = reverse(temp);

    temp = head;
    prev->next = NULL;

    while (temp && temp2) {
        if (temp->data != temp2->data) return false;
        temp  = temp->next;
        temp2 = temp2->next;
    }

    return true;
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

    if (isPalindrome(head)) {
        cout << "Is Palindrome: YES" << endl;
    } else {
        cout << "Is Palindrome: NO" << endl;
    }

    return 0;
}