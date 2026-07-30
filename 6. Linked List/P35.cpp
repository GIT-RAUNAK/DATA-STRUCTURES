// REMOVE LOOP FROM LINKED LIST

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

void removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr) return;

    Node* slow = head;
    Node* fast = head;
    bool loopExists = false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            loopExists = true;
            break;
        }
    }

    if (loopExists) {
        if (slow == head) {
            while (fast->next != head) {
                fast = fast->next;
            }
            fast->next = nullptr;
        } else {
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = nullptr;
        }
    }
}

int main() {

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail       = newNode;
        }
    }

    int pos;
    cout << "Enter position to create loop (0 = no loop): ";
    cin >> pos;

    if (pos != 0) {
        Node* temp = head;
        int steps  = pos - 1;
        while (steps--) {
            temp = temp->next;
        }
        tail->next = temp;
        cout << "Loop created at position " << pos << endl;
    }

    removeLoop(head);

    cout << "After Removing Loop: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}