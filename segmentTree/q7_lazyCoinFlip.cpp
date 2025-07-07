#include<bits/stdc++.h>
#include<vector>
using namespace std;

void build(int ind,int low,int high,vector<int>&seg,vector<int>&arr){
    if(low==high){
        seg[ind]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,seg,arr);
    build(2*ind+2,mid+1,high,seg,arr);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
void RangeUpdate(int ind,int low,int high,int l,int r,vector<int>&seg,vector<int>&lazy){
    if(lazy[ind]!=0){ // update first if have lazy value  1 means flip
        seg[ind]=(high-low+1)-seg[ind];
       // propogate for down
       if(low!=high)// mtlb child h iske pass ye internal node h propogate kro
       {
           lazy[2*ind+1]=!lazy[ind];
           lazy[2*ind+2]=!lazy[ind];
       }
       lazy[ind]=0;
    }
    //no-overlap
    if(low>r || high<l){
        return;
    }
    // complete-overlap
    if(low>=l && high<=r){
        seg[ind]=(high-low+1)-seg[ind]; 
        if(low!=high){  // now propogate for child if have
        lazy[2*ind+1]=!lazy[2*ind+1];  // agar pehle flip set that lazy mein ab not flip kardo vice versa
        lazy[2*ind+2]=!lazy[2*ind+2];
       }
    return;
    }
    // partial overlap
    int mid=(low+high)/2;
   RangeUpdate(2*ind+1,low,mid,l,r,seg,lazy);
   RangeUpdate(2*ind+2,mid+1,high,l,r,seg,lazy);
   seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r,vector<int>&seg,vector<int>&lazy){
    if(lazy[ind]!=0){ // update first if have lazy value  1 means flip
        seg[ind]=(high-low+1)-seg[ind];
       // propogate for down
       if(low!=high)// mtlb child h iske pass ye internal node h propogate kro
       {
           lazy[2*ind+1]=!lazy[2*ind+1];
           lazy[2*ind+2]=!lazy[2*ind+1];
       }
       lazy[ind]=0;
    }

    //no-overlap
    if(low>r || high<l){
        return 0;
    }
    // complete-overlap
    if(low>=l && high<=r){
        return seg[ind];
    }
    // partial overlap
    int mid=(low+high)/2;
   int left=query(2*ind+1,low,mid,l,r,seg,lazy);
   int right=query(2*ind+2,mid+1,high,l,r,seg,lazy);
   return seg[ind]=left+right;
}

int main()
{
   cout<<"enter n ";
   int n;
   cin>>n;
   vector<int>arr(n);
   vector<int>seg(4*n);
   vector<int>lazy(4*n,0);
   cout<<"enter the array "<<endl;
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   build(0,0,n-1,seg,arr);
   cout<<"before RangeUpdate root is: "<<seg[0]<<endl;
   RangeUpdate(0,0,n-1,2,4,seg,lazy);
   cout<<"afer Rangeupdate root is: "<<seg[0]<<endl;
   cout<<"query for l,r: "<<query(0,0,n-1,0,3,seg,lazy)<<endl;

    return 0;
}