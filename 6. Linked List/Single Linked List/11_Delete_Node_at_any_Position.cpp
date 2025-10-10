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
        cout<<"No Node exist.";
        return 1;
    }
    if(n==1){
        delete head->next;
        return 0;
    }
    int pos;
    cout<<"Enter Node's position that to deleted:\n";
    cin>>pos;
    Node* temp2=NULL;
    temp=head;
    if(pos==1){
        temp2=head;
        head=head->next;
        delete temp2;
    }
    else{
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        temp2=temp;
        temp->next=temp->next->next;
        delete temp2;
    }
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}