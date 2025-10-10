#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next,*prev;
    Node(int Value){
        data=Value;
        next=NULL;
        prev=NULL;
    }
};

int main(){
    int n;
    cout<<"Enter number of nodes:\n";
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
    Node *curr=temp;
    temp->prev->next=NULL;
    delete curr;

    temp=Head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    temp=Head;
    cout<<endl;
    while(temp->next) temp=temp->next;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}