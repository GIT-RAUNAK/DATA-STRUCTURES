#include<iostream>
#include<vector>
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
    vector<int> arr={1,3,4,6,2,8,6,9};
    Node *head=NULL;
    Node *tail=NULL;
    for(int i=0;i<arr.size();i++){
        if(head==NULL){
            head=new Node(arr[i]);
            tail=head;
        }
        else{
            tail->next=new Node(arr[i]);
            tail=tail->next;
        }
    }

    Node *temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}