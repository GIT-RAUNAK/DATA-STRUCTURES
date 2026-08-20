// Heap Sort - Decreasing Order

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
    int n=arr.size();
    int lastNonLeafNode=n/2-1;
    for(int i=lastNonLeafNode;i>=0;i--){
        heapifyDown(arr,n,i);
    }
}

void heapSort(vector<int> &arr){
    int n=arr.size();
    buildHeap(arr);
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapifyDown(arr,i,0);
    }
}

int main(){
    vector<int> arr = {7,2,9,1,5,3,4,8,6};
    heapSort(arr);
    cout<<"Sorted Array:\n";
    for(int x : arr){
        cout<<x<<" ";
    }
}