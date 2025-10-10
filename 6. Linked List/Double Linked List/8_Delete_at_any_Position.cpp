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
    int pos;
    cout<<"Enter Node to be deleted:\n";
    cin>>pos;
    if(pos==1){
        if(head==NULL) return NULL;
        else{
            Node *curr=head;
            head=head->next;
            head->prev=NULL;
            delete curr;
        }
    }
    else{
        temp=head;
        if(pos==n){
            while(temp){
                temp=temp->next;
            }
            Node *curr=temp;
            temp->prev->next=NULL;
            delete curr;
        }
        else{
            temp=head;
            while(--pos) temp=temp->next;
            Node *curr=temp;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            delete curr;
        }
    }
    temp=head;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    temp=head;
    cout<<endl;
    while(temp->next) temp=temp->next;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}