// Extract Min in a Min-Heap

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

int extractMin(vector<int> &arr){
    int root=arr[0];
    arr[0]=arr[arr.size()-1];
    arr.pop_back();
    if(!arr.empty()){
        heapifyDown(arr,arr.size(),0);
    }
    return root;
}

int main(){
    vector<int> arr = {0,2,4,3,9,5,6,10,8};

    int ans = extractMin(arr);

    cout<<"Minimum Element in the heap is: "<<ans<<endl;
    for(int x : arr){
        cout<<x<<" ";
    }
}