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

Node* reverse(Node* head){
    Node* temp=head,*prev=NULL,*fut=NULL;
    while(temp){
        fut=temp->next;
        temp->next=prev;
        prev=temp;
        temp=fut;
    }
    head=prev;
    return head;
}

void display(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

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

    head=reverse(head);
    display(head);

}