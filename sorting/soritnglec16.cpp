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
int minindex=i;
for(j=i+1;j<n;j++){
   if(arr[j]<arr[minindex]) 
   minindex=j;
}
int t=arr[minindex];
arr[minindex]=arr[i];
arr[i]=t;
}
for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
    return 0;
}