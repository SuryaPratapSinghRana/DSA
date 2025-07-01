#include<iostream>
using namespace std;
void countsort(int arr[],int arr2[],int n){
    int max=arr[0];
    for(int i=0;i<n;i++){
       if(max<arr[i]){
          max=arr[i];
       }
    }
    int freq[max+1];
    for(int i=0;i<max+1;i++){
        freq[i]=0;
    }
    int cf[max+1];
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    cf[0]=freq[0];
    for(int i=1;i<max+1;i++)
    {
        cf[i]=cf[i-1]+freq[i];
    }
   for(int i=n-1;i>=0;i--){
    arr2[cf[arr[i]]-1]=arr[i];
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
int arr2[n];
countsort(arr,arr2,n);
cout<<"print the array ";
for(int i=0;i<n;i++){
    cout<<arr2[i]<<" ";
}
    return 0;
}