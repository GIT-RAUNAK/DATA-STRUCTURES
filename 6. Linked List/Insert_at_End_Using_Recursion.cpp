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

Node* CreateLinkedList(vector<int> arr,int index,int size){
    if(index==size)
    return NULL;

    Node* temp=new Node(arr[index]);
    temp->next=CreateLinkedList(arr,index+1,size);
    return temp;
}

int main(){
    vector<int> arr={1,4,2,8,5,0,4,5};

    Node *head=CreateLinkedList(arr,0,arr.size());

    while(head){
        cout<<head->data<<"->";
        head=head->next;
    }
    
}