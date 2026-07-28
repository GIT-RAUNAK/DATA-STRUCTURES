// COUNT PAIRS FROM TWO LINKED LISTS WITH SUM EQUAL TO X

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

int countPairs(Node* head1, Node* head2, int x) {

    unordered_map<int, int> mpp;
    Node* temp = head1;
    while (temp) {
        mpp[temp->data] = 1;
        temp = temp->next;
    }

    temp = head2;
    int count = 0;
    while (temp) {
        int req = x - temp->data;
        if (mpp.find(req) != mpp.end()) count++;
        temp = temp->next;
    }

    return count;
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

    cout << "List 1: ";
    Node* temp = head1;
    while (temp != NULL) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;

    cout << "List 2: ";
    temp = head2;
    while (temp != NULL) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;

    int x;
    cout << "Enter target sum X: ";
    cin >> x;

    int result = countPairs(head1, head2, x);
    cout << "Number of pairs with sum " << x << ": " << result << endl;

    return 0;
}