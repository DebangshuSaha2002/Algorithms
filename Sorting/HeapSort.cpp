#include<iostream>
#include<queue>

using namespace std;

void heapify(int *arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[largest]<arr[left]){
        largest=left;
    }

    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    int size=n;
    while(size>0){
        swap(arr[size],arr[0]);
        size--;
        heapify(arr,size,0);
    }
}

int main()
{
    //This is max Heap using STL
    // priority_queue<int> pq;
    // pq.push(4);
    // pq.push(3);
    // pq.push(5);
    // pq.push(2);

    // cout<<"Top element is:"<<pq.top()<<endl;
    // pq.pop();
    // cout<<"Top element is:"<<pq.top()<<endl;

    // cout<<"Size is:"<<pq.size()<<endl;

    // //This is minHeap using STL
    // priority_queue<int,vector<int>,greater<int> >minHeap;
    // minHeap.push(4);
    // minHeap.push(3);
    // minHeap.push(5);
    // minHeap.push(2);

    // cout<<"\nTop element is:"<<minHeap.top()<<endl;
    // minHeap.pop();
    // cout<<"Top element is:"<<minHeap.top()<<endl;

    // cout<<"Size is:"<<minHeap.size()<<endl;

    //Working on heap sort
    int arr[6]={54,53,55,52,50,51};
    int n=5;
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }

    cout<<"After heapifying"<<endl;
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //doing the heap sort now
    heapsort(arr,n);
    cout<<"After heapsort"<<endl;
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}