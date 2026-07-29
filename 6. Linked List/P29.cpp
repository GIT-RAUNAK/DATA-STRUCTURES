// DELETE FROM A DOUBLY LINKED LIST

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        this->data=val;
        this->next=NULL;
        this->prev=NULL;
    }
};

int main(){
    int n,x;
    cout<<"Enter total number of nodes in the Linked List:\n";
    cin>>n;
    Node *head=NULL;
    Node* tail=NULL;
    cout<<"Enter elements in the Linked List:\n";
    for(int i=0;i<n;i++){
        cin>>x;
        Node* newNode = new Node(x);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    int pos;
    cout<<"Enter the node want to delete:\n";
    cin>>pos;
    if(pos>n || pos<0) return -1;
    Node* temp=head;
    if(pos==0){
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
    }
    else{
        while(--pos){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        if(temp->next!=NULL){
                temp->next->prev=temp->next;
        }
    }

    delete temp;

    cout << "Updated List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}