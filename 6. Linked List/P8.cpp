// CREATING A LINKED LIST USING RECURSION

#include<iostream>
using namespace std;
#include<vector>

class Node{
public:
    int data;
    Node *next;

    Node(int x){
        this->data=x;
        this->next=NULL;
    }
};

Node* createLinkedList(const vector<int> &arr, int index){
    if(index==arr.size()) return NULL;
    Node *temp = new Node(arr[index]);
    temp->next = createLinkedList(arr, index+1);
    return temp;
}

int main(){
    int n;
    cout<<"Enter number of nodes:\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements in the Nodes:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *head = createLinkedList(arr,0);

    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}