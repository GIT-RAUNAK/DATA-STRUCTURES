#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int value){
        data=value;
        next=NULL;
    }
};

int main(){
    int arr[]={2,5,10,5,8};
    Node *head=NULL;
    for(int i=0;i<5;i++){
       if(head==NULL){
            head=new Node(arr[i]);
        }
        else{
            Node *temp;
            temp=new Node(arr[i]);
            temp->next=head;
            head=temp;
        }
    }
    Node *temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}