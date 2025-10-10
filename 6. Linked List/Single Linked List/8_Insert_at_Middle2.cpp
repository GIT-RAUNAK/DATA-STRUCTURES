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
    Node* Head=NULL;
    Node* temp=NULL;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter the data in Node "<<i+1<<":\n";
        cin>>a;
        if(Head==NULL){
            Head=new Node(a);
            temp=Head;
        }
        else{
            temp->next=new Node(a);
            temp=temp->next;
        }
    }
    int pos,key;
    cout<<"Enter the position where a node should be inserted:\n";
    cin>>pos;
    cout<<"Enter data to be inserted:\n";
    cin>>key;
    Node* temp2=new Node(key);
    temp=Head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    temp2->next=temp->next;
    temp->next=temp2;
    while(Head){
        cout<<Head->data<<"->";
        Head=Head->next;
    }
}