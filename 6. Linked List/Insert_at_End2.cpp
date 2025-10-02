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

int main(){
    int n;
    cout<<"Enter the number of nodes:\n";
    cin>>n;
    Node* head=NULL;
    Node* t=NULL;
    int a;
    for(int i=0;i<n;i++){
        cout<<"Enter the data in Node "<<i+1<<":\n";
        cin>>a;
        if(head==NULL){
            head=new Node(a);
            t=head;
        }
        else{
            t->next=new Node(a);
            t=t->next;
        }
    }
    int key;
    cout<<"Enter the data to be inserted at last:\n";
    cin>>key;
    Node* temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    Node* t2=new Node(key);
    temp2->next=t2;
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
}