#include<iostream>
using namespace std;
class heap{
    public:
int arr[100];
int size=0;
heap(){
    arr[0]=-1;
    size=0;
}
void insert(int val){
    size=size+1;
    int index=size;
    arr[index]=val;
   while(index>1){
    int parent=index/2;
    if(arr[index]>arr[parent]){
        swap(arr[index],arr[parent]);
        index=parent;
    }
    else{
        return;
    }
   }
}
 void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }
void deleteion(){
    if(size==0){
        cout<<"nothing to delete ";
        return;
    }
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size)
    {
        int leftindex=2*i;
        int rightindex=2*i+1;
        int large=i;
        if(leftindex<=size && arr[leftindex]>arr[i]){
            large=leftindex;
        }
        if(rightindex<=size && arr[rightindex]>arr[i]){
            large=rightindex;
        }
        if(large!=i){
            swap(arr[large],arr[i]);
            i=large;
        }
        else{
            return;
        }

    }
}

};
void heapify(int arr[],int n ,int i){
    int large=i;
    int right=2*i;
    int left=2*i+1;
    if(left<=n && arr[left]>arr[large]){
        large=left;
    }
    if(right<=n && arr[right]>arr[large]){
        large=right;
    }
    if(large!=i){
        swap(arr[large],arr[i]);
         heapify(arr,n,large);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
    // step 1
     swap(arr[size],arr[1]);
     size--;
     // step 2
    heapify(arr,size,1);
    }
}
int main(){
    heap h;
    h.insert(10);
    h.insert(3);
    h.insert(2);
   // h.insert(3);
   // h.insert(2);
    h.print();
    h.deleteion();
    h.print();
    int n=5;
    int arr1[]={-1,54,53,55,52,50};
    for(int i=n/2;i>0;i--){

    heapify(arr1,n,i);
    }
    cout<<" print the array heapified ";
    for(int i=1;i<=n;i++){
        cout<<arr1[i]<<" ";
    }
    heapsort(arr1,n);
    cout<<endl<<" print the array sorted ";
    for(int i=1;i<=n;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}