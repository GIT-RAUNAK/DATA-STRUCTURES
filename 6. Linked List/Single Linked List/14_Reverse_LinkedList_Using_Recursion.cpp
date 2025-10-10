#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};

Node* Reverse(Node* curr,Node* prev){
    if(curr==NULL) return prev;
    Node* temp=curr->next;
    curr->next=prev;
    Reverse(temp,curr);
}

void display(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    int n;
    cout<<"Enter number of Nodes:\n";
    cin>>n;
    Node* temp=NULL;
    Node* head=NULL;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter data in Node "<<i+1<<":\n";
        cin>>a;
        if(head==NULL){
            head=new Node(a);
            temp=head;
        }
        else{
            temp->next=new Node(a);
            temp=temp->next;
        }
    }

    head=Reverse(head,NULL);
    display(head);
}