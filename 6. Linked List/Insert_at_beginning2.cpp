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
    cout<<"Enter number of Nodes:\n";
    cin>>n;
    int a;
    Node* head=NULL;
    Node* t=NULL;
    Node* temp=NULL;
    for(int i=0;i<n;i++){
        cout<<"Enter data to be inserted in Node "<<i+1;
        cin>>a;
        if(head==NULL){
            head=new Node(a);
            t=head;
        }
        else{
            temp=new Node(a);
            t->next=temp;
            t=temp;
        }
    }
    int key;
    cout<<"Enter the value to be inserted at the beginning:\n";
    cin>>key;
    Node* temp2=new Node(key);
    temp2->next=head;
    head=temp2;
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
}