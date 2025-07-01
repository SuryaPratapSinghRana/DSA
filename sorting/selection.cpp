#include<iostream>
using namespace std;
void selection(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
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
selection(arr,n);
cout<<"print the array ";
for(int i=0;i<n;i++){
    cout<<arr[i];
}
    return 0;
}