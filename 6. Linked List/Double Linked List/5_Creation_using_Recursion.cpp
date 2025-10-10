#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *prev;
    Node *next;
    Node(int value){
        data=value;
        next=NULL;
        prev=NULL;
    }
};

Node *createDLL(int arr[],int index, int size, Node *back){
    if(index==size) return NULL;
    Node *temp=new Node(arr[index]);
    temp->prev=back;
    temp->next=createDLL(arr,index+1,size,temp);
    return temp;
}

int main(){
    int n;
    cout<<"Enter number of Nodes:\n";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element in Node "<<i+1<<":\n";
        cin>>arr[i];
    }
    Node *head=createDLL(arr,0,n,NULL);
    Node *temp=head;
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