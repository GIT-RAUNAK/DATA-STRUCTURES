// MERGE TWO SORTED LINKED LISTS

#include <iostream>
using namespace std;

class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(Node* head1, Node* head2) {
    Node* temp1=head1;
    Node* temp2=head2;
    Node* temp3=NULL;
    while(temp1 && temp2){
        if(temp1->data > temp2->data){
            Node* hold = temp2->next;
            if(temp3!=NULL){
                temp3->next=temp2;
                temp3=temp2;
                temp2->next=temp1;
            }
            else{
                temp2->next=temp1;
                head1=temp2;
                temp3=temp2;
            }
            temp2=hold;
        }
        else{
            temp3=temp1;
            temp1=temp1->next;
        }
    }
    if(temp2){
            temp3->next = temp2;
        }
    return head1;
}

int main() {
    int n1, n2;
    cout << "Enter number of nodes for List 1: ";
    cin >> n1;

    Node* head1 = NULL;
    Node* tail1 = NULL;
    if (n1 > 0) {
        cout << "Enter List 1 sorted elements: ";
        for (int i = 0; i < n1; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node(x);
            if (head1 == NULL) {
                head1 = newNode;
                tail1 = newNode;
            } else {
                tail1->next = newNode;
                tail1 = newNode;
            }
        }
    }

    cout << "Enter number of nodes for List 2: ";
    cin >> n2;

    Node* head2 = NULL;
    Node* tail2 = NULL;
    if (n2 > 0) {
        cout << "Enter List 2 sorted elements: ";
        for (int i = 0; i < n2; i++) {
            int x;
            cin >> x;
            Node* newNode = new Node(x);
            if (head2 == NULL) {
                head2 = newNode;
                tail2 = newNode;
            } else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    Node* mergedHead = sortedMerge(head1, head2);

    cout << "Merged Sorted List: ";
    Node* temp = mergedHead;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
