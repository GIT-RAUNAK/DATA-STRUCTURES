// Build MinHeap

#include<iostream>
#include<vector>
using namespace std;

void heapifyDown(vector<int> &heap, int n, int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && heap[left]<heap[smallest]) smallest=left;
    if(right<n && heap[right]<heap[smallest]) smallest=right;

    if(smallest!=i){
        swap(heap[i],heap[smallest]);
        heapifyDown(heap,n,smallest);
    }
}

void buildHeap(vector<int> &arr){
    int n = arr.size();
    int lastNonLeaf=n/2-1;
    for(int i=lastNonLeaf;i>=0;i--){
        heapifyDown(arr,n,i);
    }
}

int main(){
    vector<int> arr = {3,1,8,2,6,4,9,11,2,66,55,3,421};

    buildHeap(arr);

    for(int x : arr){
        cout<<x<<" ";
    }
}