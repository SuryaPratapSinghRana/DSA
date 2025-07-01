#include<iostream>
using namespace std;
void heapify(int arr[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int max=i;
    if(left<n && arr[left]>arr[max]){
        max=left;
    }
    if(right<n && arr[right]>arr[max])
    {
        max=right;
    }
    if(max!=i){
        swap(arr[i],arr[max]);
        heapify(arr,max,n);
    }
    else{
        return;
    }
}
void heapsort(int arr[],int n){
if(n==0)
{
    return;
}
swap(arr[0],arr[n-1]);
heapify(arr,0,n-1);
heapsort(arr,n-1);
}

// void heapsort(int arr[],int n){
//     int size=n;
//     while(size>0)
//     {
//         swap(arr[0],arr[size-1]);
//         size--;
//         heapify(arr,0,size);
//     }
// }
int main(){
  int n;
cout<<"enter the value of n ";
cin>>n;
int arr[n];
cout<<"enter the array ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
for(int i=n/2;i>=0;i--){
    heapify(arr,i,n);
}
heapsort(arr,n);
cout<<"print the array ";
for(int i=0;i<n;i++){
    cout<<arr[i];
}
    return 0;
}