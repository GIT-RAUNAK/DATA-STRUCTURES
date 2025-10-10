#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};

int main(){
    int n;
    cout<<"Enter Number of Nodes:\n";
    cin>>n;
    Node *head=NULL,*temp=NULL;
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
            temp->next->prev=temp;
            temp=temp->next;
        }
    }
    int x;
    cout<<"Enter data to be inserted at last:\n";
    cin>>x;
    Node *newNode=new Node(x);
    newNode->next=nullptr;
    newNode->prev=temp;
    temp->next=newNode;
    temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=head;
    while(temp->next) temp=temp->next;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}