// DELETE EVERY KTH NODE FROM LINKED LIST

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

    int K;
    cout << "Enter K (delete every Kth node): ";
    cin >> K;

    if (K == 1) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Updated Linked List: NULL" << endl;
        return 0;
    }

    int count = 0;
    temp = head;
    Node* prev = NULL;

    while (temp) {
        count++;
        if (count % K == 0) {
            prev->next = temp->next;
            delete temp;            
            temp = prev->next;      
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    cout << "Updated Linked List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}