// INSERT IN DOUBLY LINKED LIST

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int x){
        this->data=x;
        this->next=NULL;
        this->prev=NULL;
    }
};

int main(){
    int n,x,pos;
    cout<<"Enter the number of nodes in Original Linked List:\n";
    cin>>n;
    Node* head = NULL;
    Node* tail = NULL;
    cout<<"Enter elements in the node:\n";
    for(int i=0;i<n;i++){
        cin>>x;
        Node *newNode = new Node(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    cout<<"Enter the position where to insert a node:\n";
    cin>>pos;
    if(pos>n || pos<0) return -1;
    cout<<"Enter elements to be inserted in it:\n";
    cin>>x;
    Node *newNode = new Node(x);
    if(pos==0){
        if(head!=NULL){
            newNode->next=head;
            head=newNode;
        }
        head=newNode;
    }
    else{
        Node *temp = head;
        while(--pos){
            temp=temp->next;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=NULL) temp->next->prev=newNode;
        temp->next=newNode;
    }
    cout << "Updated List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}