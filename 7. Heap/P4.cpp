//Insert in A MinHeap

#include<iostream>
#include<vector>
using namespace std;

void heapifyUp(vector<int> &heap, int i){
    while(i>0){
        int parent=(i-1)/2;
        if(heap[i]<heap[parent]){
            swap(heap[i],heap[parent]);
            i=parent;
        }
        else{
            break;
        }
    }
}

void insertInHeap(vector<int> &arr, int val){
    arr.push_back(val);
    heapifyUp(arr, arr.size()-1);
}

int main(){
    vector<int> arr = {2,3,4,8,9,5,6,10};

    insertInHeap(arr,0);

    for(int x : arr){
        cout<<x<<" ";
    }
}