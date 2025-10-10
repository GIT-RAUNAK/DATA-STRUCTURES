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
    cout<<"Enter Nimber of Nodes:\n";
    cin>>n;
    if(n==0){
        cout<<"No Nodes are present";
        return 1;
    }
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
    temp=head;
    head=head->next;
    delete temp;
    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
}