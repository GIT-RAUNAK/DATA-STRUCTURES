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
    cout<<"Enter number of nodes:\n";
    cin>>n;
    Node* head=NULL;
    Node* temp=NULL;
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
    if(n==0){
        cout<<"No Node Exists\n";
    }
    else if(n==1){
        temp=head;
        head=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        while(curr->next!=NULL){
            temp=curr;
            curr=curr->next;
        }
        temp->next=NULL;
        delete curr;
    }
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
}