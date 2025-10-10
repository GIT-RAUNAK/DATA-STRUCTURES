#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int Value){
        data=Value;
        next=NULL;
        prev=NULL;
    }
};

int main(){
    int n;
    cout<<"Enter number of Nodes:\n";
    cin>>n;
    Node *Head=NULL;
    Node *temp=NULL;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter data in Node "<<i+1<<":\n";
        cin>>a;
        if(Head==NULL){
            Head=new Node(a);
            temp=Head;
        }
        else{
            temp->next=new Node(a);
            temp->next->prev=temp;
            temp=temp->next;
        }
    }
    temp=Head;
    cout<<"Elements in the Linked List are:\n";
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    temp=Head;
    while(temp && temp->next) temp=temp->next;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}