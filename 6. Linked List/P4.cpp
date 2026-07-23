// CHECK CIRCULAR LINKED LIST

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

    Node(int x){
        this->data=x;
        this->next=NULL;
    }
};

bool checkCircular(Node *head){
    Node *temp=head;
    while(temp){
        if(temp->next==head) return true;
        temp=temp->next;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter number of nodes:\n";
    cin>>n;

    Node *head=NULL;
    Node* temp=head;

    cout<<"Enter Elements:\n";

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node *newNode = new Node(x);
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            temp=newNode;
        }
    }

    if(temp!=NULL) temp->next=head;

    cout<<checkCircular(head);
}