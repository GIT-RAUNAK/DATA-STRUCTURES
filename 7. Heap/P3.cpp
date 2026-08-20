// Insert into A MaxHeap

#include<iostream>
#include<vector>
using namespace std;

void heapifyUp(vector<int> &heap, int i){
    while(i>0){
        int parent=(i-1)/2;
        if(heap[i]>heap[parent]){
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
    heapifyUp(arr,arr.size()-1);
}

int main(){
    vector<int> arr = {9,5,8,1,3,7,4};
    
    insertInHeap(arr,60);

    for(int i : arr){
        cout<<i<<" ";
    }
}