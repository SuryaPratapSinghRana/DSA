#include<iostream>
#include<time.h>
using namespace std;
int partition(int arr[],int s,int e){
    srand(time(NULL));
    int random=s+rand()%(e-s+1);
    swap(arr[random],arr[e]);
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
void quick(int arr[],int s,int e){
    if(s<e){
        int pivot=partition(arr,s,e);
        quick(arr,s,pivot-1);
        quick(arr,pivot+1,e);
    }
}
int main(){
int n;
cout<<"enter the value of n ";
cin>>n;
int arr[n];
cout<<"enter the array ";
for(int i=0;i<n;i++){
    cin>>arr[i];
}
quick(arr,0,n-1);;
cout<<"print the array ";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}