//Extract Max in a Max-Heap

#include<iostream>
#include<vector>
using namespace std;

void heapifyDown(vector<int> &heap, int n, int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]>heap[largest]) largest=right;

    if(largest!=i){
        swap(heap[i],heap[largest]);
        heapifyDown(heap,n,largest);
    }
}

int extractMax(vector<int>&arr){
    if(arr.empty()) {
        cout << "Heap Underflow!" << endl;
        return -1; 
    }
    int n = arr.size();
    int root = arr[0];
    arr[0]=arr[n-1];
    arr.pop_back();
    if(!arr.empty()){
        heapifyDown(arr,n-1,0);
    }
    return root;
}

int main(){
    vector<int> arr = {85,9,8,5,3,2,7,1};
    int ans = extractMax(arr);

    cout<<"Maximum Element is: "<<ans<<endl;
    for(int x : arr){
        cout<<x<<" ";
    }
}