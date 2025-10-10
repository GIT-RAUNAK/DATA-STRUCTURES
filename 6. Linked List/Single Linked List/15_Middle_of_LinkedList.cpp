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
    temp=head;
    for(int i=0;i<n/2;i++){
        temp=temp->next;
    }
    while(head){
        cout<<head->next<<"\n";
        head=head->next;
    }
    cout<<"Adedress of "<<n/2<<" is:\n";
    cout<<temp->next;
}