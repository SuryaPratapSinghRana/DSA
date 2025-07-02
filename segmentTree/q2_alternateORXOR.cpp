#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,vector<int>&seg,vector<int>&arr,int orxor)
{
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,seg,arr,!orxor);
    build(2*ind+2,mid+1,high,seg,arr,!orxor);
    if(orxor){ // true means bitwise or karo
       seg[ind]=seg[2*ind+1]|seg[2*ind+2];
    }
    else  // false mean xor karo
    {
        seg[ind]=seg[2*ind+1]^seg[2*ind+2];
    }
}

void update(int ind,int low,int high,int i,int value,vector<int>&seg,int orxor){
    if(low==high)
    {
        seg[ind]=value;
    }
    int mid=(low+high)/2;
    if(i<=mid)  // left mein jao wahi pe h ye i index wali range
    {
        update(2*ind+1,low,mid,i,value,seg,!orxor);
    }
    else  // warna right mein h i index wali range wahi jao
    {
          update(2*ind+2,mid+1,high,i,value,seg,!orxor);
    }
    // parent ko update karo kyunki shayad ab xor or ki value bhi change hojagi 
    if(orxor){ // true means bitwise or karo
       seg[ind]=seg[2*ind+1]|seg[2*ind+2];
    }
    else  // false mean xor karo
    {
        seg[ind]=seg[2*ind+1]^seg[2*ind+2];
    }
}

int main(){
    int n;
    cout<<"enter the n ";
    cin>>n;
    int noOfelem=pow(2,n);
    vector<int>arr(noOfelem);
    for(int i=0;i<noOfelem;i++){
        cin>>arr[i];
    }
    vector<int>seg(4*noOfelem);
    if(n%2==0)build(0,0,noOfelem-1,seg,arr,0);  // agar n even to xor first pass 0
    else
       build(0,0,noOfelem-1,seg,arr,1);  // agar n odd to or first pass 1
    cout<<"answer is  "<<seg[0];
 
}