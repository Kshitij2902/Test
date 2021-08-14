#include<iostream>
#include<vector>
using namespace std;

int length, x, i;
void Heapify(vector<int> &arr,int cur,int n){
    int high = cur;
    int l = 2*cur + 1;
    int r = 2*cur + 2;
    if(l<n && arr[l]>arr[high])
        high = l;
    if(r<n && arr[r]>arr[high])
        high = r;
    if(high != cur){
        int temp = arr[cur];
        arr[cur] = arr[high];
        arr[high] = temp;
        Heapify(arr,high,n);
    }
}

void HeapSort(vector<int> &arr){
    for(i=arr.size()/2-1;i>=0;i--)
        Heapify(arr,i,arr.size());

    for(i = arr.size()-1; i>0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Heapify(arr,0,i);
    }
}

int main()
{
    cout<<"Enter the no. of elements: ";
    cin>>length;
    vector<int> heap;
    cout<<"Enter the elements: ";
    for(i=0; i<length; i++){
        cin>>x;
        heap.push_back(x);
    }
    HeapSort(heap);
    cout<<"\nElements after heap sort are : ";
    for(i=0; i<heap.size(); i++)
        cout<<heap[i]<<" ";
    printf("\n");
    return 0;
}