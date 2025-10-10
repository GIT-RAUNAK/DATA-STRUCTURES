#include<iostream>
#include<vector>
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

Node* reverse_LinkedList(Node* Head){
    Node* t=Head;
    vector<int> arr;
    while(t!=NULL){
        arr.push_back(t->data);
        t=t->next;
    }
    t=Head;
    int n=arr.size()-1;
    while(t){
        t->data=arr[n];
        n--;
        t=t->next;
    }
    return Head;
}

void display(Node* Head){
    while(Head!=NULL){
        cout<<Head->data<<" ";
        Head=Head->next;
    }
}

int main(){
    int n;
    cout<<"Enter size of the LinkedList:\n";
    cin>>n;
    Node* head=NULL;
    Node* temp=NULL;
    for(int i=0;i<n;i++){
        int a;
        cout<<"Enter data in node "<<i+1<<":\n";
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

    head=reverse_LinkedList(head);
    display(head);

}