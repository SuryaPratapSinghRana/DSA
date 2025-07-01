#include<iostream>
using namespace std;
void merge(int arr[],int s,int e,int mid){
    int n1=mid-s+1;
    int n2=e-mid;
int arr1[n1];
int arr2[n2];
int ind=s;
for(int i=0;i<n1;i++){
   arr1[i]=arr[ind++];
}
for(int i=0;i<n2;i++){
    arr2[i]=arr[ind++];
}
ind=s;
int i=0,j=0;
while(i<n1 && j<n2){
    if(arr1[i]<arr2[j]){
        arr[ind++]=arr1[i++];
    }
    else{
        arr[ind++]=arr2[j++];
    }
}
while(i<n1){
     arr[ind++]=arr1[i++];
}
while(j<n2){
    arr[ind++]=arr2[j++];
}
}
void mergesort(int arr[],int s,int e){
    if(s<e){
        int mid=s+(e-s)/2;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        merge(arr,s,e,mid);
    }
}
int main(){
int n;
cout<<"enter the size of array ";
cin>>n;
int arr[n];
cout<<"Enter the array: ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
mergesort(arr,0,n-1);
cout<<"Array after sorting: ";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}