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

Node* CreateLinkedList(vector<int>arr,int index,int size,Node* prev){
    if(index==size)
    return prev;

    Node* temp=new Node(arr[index]);
    temp->next=prev;
    return CreateLinkedList(arr,index+1,size,temp);
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,2,3,4,5,7,8,9};
    Node* Head=CreateLinkedList(arr,0,arr.size(),NULL);

    while(Head){
        cout<<Head->data<<"->";
        Head=Head->next;
    }
}