#include<iostream>
using namespace std;
int main(){
int i,j,n;
cout<<"enter the value of n";
cin>>n;
int arr[n];
cout<<"enter  the value of array";
for(i=0;i<n;i++){
cin>>arr[i];
}
cout<<"the enter  array is  ";
for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl<<"the sorting array is ";
for(i=0;i<n-1;i++){
    for(j=0;j<n-1-i;j++){
        if(arr[j+1]<arr[j]){
            int t=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=t;
        }
    }
}
for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}