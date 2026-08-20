// Build MaxHeap

#include<iostream>
#include<vector>
using namespace std;

void heapifyDown(vector<int> &heap, int n, int i){
    int largest=i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]>heap[largest]) largest=right;
    if(largest!=i){
        swap(heap[largest],heap[i]);
        heapifyDown(heap,n,largest);
    }
}

void buildHeap(vector<int> &arr){
    int n=arr.size();
    int lastNonLeaf = n/2-1;
    for(int i=lastNonLeaf;i>=0;i--){
        heapifyDown(arr,n,i);
    }
}

int main(){
    vector<int> arr = {5,1,7,2,9,4,11,5,9,33,55,100};

    buildHeap(arr);

    for(int x : arr){
        cout<<x<<" ";
    }
}