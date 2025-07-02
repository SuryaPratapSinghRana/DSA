#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,vector<int>&seg,vector<int>&arr)
{
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,seg,arr);
    build(2*ind+2,mid+1,high,seg,arr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int low,int high,int l,int r,int ind,vector<int>&seg){
    // no-overlap
    if(high<l || low>r){
        return INT_MAX;
    }
    // complete overlap
    if(low>=l && high<=r){
        return seg[ind];
    }
    // partial overlap
    int mid=(low+high)/2;
    int left=query(low,mid,l,r,2*ind+1,seg);
    int right=query(mid+1,high,l,r,2*ind+2,seg);
     return min(left,right);
}

void update(int ind,int low,int high,int i,int value,vector<int>&seg){
    if(low==high)
    {
        seg[ind]=value;
    }
    int mid=(low+high)/2;
    if(i<=mid)  // left mein jao wahi pe h ye i index wali range
    {
        update(2*ind+1,low,mid,i,value,seg);
    }
    else  // warna right mein h i index wali range wahi jao
    {
          update(2*ind+2,mid+1,high,i,value,seg);
    }
    // parent ko update karo kyunki shayad min update hogya ho
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>seg(4*n);
    build(0,0,n-1,seg,arr);

}