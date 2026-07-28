// GET KTH NODE FROM LAST IN LINKED LIST

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

int getKthFromLast(Node* head, int k) {

    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    if (k > count) return -1;

    temp = head;
    int req = count - k;
    while (req--) {
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
    cout << "Enter K (Kth node from last): ";
    cin >> k;

    int result = getKthFromLast(head, k);

    if (result == -1) {
        cout << "K is greater than length of list!" << endl;
    } else {
        cout << "Kth node from last: " << result << endl;
    }

    return 0;
}