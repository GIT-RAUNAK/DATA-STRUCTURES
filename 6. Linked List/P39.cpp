//DELETE NODES WITH GREATER VALUE ON RIGHT

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    while (curr) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node* compute(Node* head) {
    Node* temp = reverse(head);
    Node* new_head = temp;

    int maxi = temp->data;
    Node* prev = temp;
    temp = temp->next;

    while (temp) {
        if (temp->data < maxi) {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            maxi = temp->data;
            prev = temp;
            temp = temp->next;
        }
    }

    temp = reverse(new_head);
    return temp;
}

Node* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = createList(arr, n);
    delete[] arr;

    cout << "Input:  ";
    printList(head);

    head = compute(head);

    cout << "Output: ";
    printList(head);

    freeList(head);
    return 0;
}