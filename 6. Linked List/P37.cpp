// INTERSECTION POINT IN Y SHAPED LINKED LIST

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

Node* intersectPoint(Node* head1, Node* head2) {
    int count1 = 0;
    int count2 = 0;
    Node* temp = head1;
    while (temp) {
        count1++;
        temp = temp->next;
    }
    temp = head2;
    while (temp) {
        count2++;
        temp = temp->next;
    }
    if (count2 >= count1) {
        temp = head2;
        int req = count2 - count1;
        for (int i = 0; i < req; i++) {
            temp = temp->next;
        }
        Node* temp2 = head1;
        while (temp && temp2) {
            if (temp == temp2) {
                return temp;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    if (count2 < count1) {
        temp = head1;
        int req = count1 - count2;
        for (int i = 0; i < req; i++) {
            temp = temp->next;
        }
        Node* temp2 = head2;
        while (temp && temp2) {
            if (temp == temp2) {
                return temp;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    return nullptr;
}

int main() {
    int common_nodes;
    cout << "Enter number of nodes in the common intersection part: ";
    cin >> common_nodes;

    Node* common_head = nullptr;
    Node* common_tail = nullptr;
    if (common_nodes > 0) {
        cout << "Enter common elements: ";
        for (int i = 0; i < common_nodes; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node(x);
            if (common_head == nullptr) {
                common_head = newNode;
                common_tail = newNode;
            } else {
                common_tail->next = newNode;
                common_tail = newNode;
            }
        }
    }

    int n1;
    cout << "Enter number of specific nodes for List 1: ";
    cin >> n1;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;
    if (n1 > 0) {
        cout << "Enter List 1 unique elements: ";
        for (int i = 0; i < n1; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node(x);
            if (head1 == nullptr) {
                head1 = newNode;
                tail1 = newNode;
            } else {
                tail1->next = newNode;
                tail1 = newNode;
            }
        }
        tail1->next = common_head;
    } else {
        head1 = common_head;
    }

    int n2;
    cout << "Enter number of specific nodes for List 2: ";
    cin >> n2;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;
    if (n2 > 0) {
        cout << "Enter List 2 unique elements: ";
        for (int i = 0; i < n2; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node(x);
            if (head2 == nullptr) {
                head2 = newNode;
                tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
        tail2->next = common_head;
    } else {
        head2 = common_head;
    }

    Node* intersection = intersectPoint(head1, head2);

    if (intersection != nullptr) {
        cout << "Intersection found at node with data: " << intersection->data << endl;
    } else {
        cout << "No intersection point found" << endl;
    }

    return 0;
}
