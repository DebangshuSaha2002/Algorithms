#include<iostream>
#include<vector>
using namespace std;

void merge(int *arr,int s,int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int[len1];
    int *second=new int[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }
        else{
            arr[k++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[k++]=first[index1++];    
    }

    while(index2<len2){
        arr[k++]=second[index2++];
    }
}

void mergesort(int *arr,int s,int e){
    int mid=s+(e-s)/2;
    if(s>=e){
        return;
    }
    //merge sort the left side
    mergesort(arr,s,mid);
    //merge sort the right side
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
}

int main(){
    int arr[9]={4,1,7,3,5,2,6,0,9};
    mergesort(arr,0,8);

    for(int i=0;i<=8;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}