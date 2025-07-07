#include<bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,vector<int>&seg,vector<int>&freq)
{
    if(low==high){
        seg[ind]=freq[low];
          return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,seg,freq);
    build(2*ind+2,mid+1,high,seg,freq);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int query(int low,int high,int l,int r,int ind,vector<int>&seg){
    // no-overlap
    if(high<l || low>r){
        return 0;
    }
    // complete overlap
    if(low>=l && high<=r){
        return seg[ind];
    }
    // partial overlap
    int mid=(low+high)/2;
    int left=query(low,mid,l,r,2*ind+1,seg);
    int right=query(mid+1,high,l,r,2*ind+2,seg);
     return left+right;
}

void update(int ind,int low,int high,int i,int value,vector<int>&seg){
    if(low==high)
    {
        seg[ind]=value;
        return;
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
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

int main(){
    int n;
    cout<<"enter the size of array ";
    cin>>n;
    vector<int>arr(n);
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
    }
    vector<int>freq(maxi+1,0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    vector<int>seg(4*(maxi+1));
    build(0,0,maxi,seg,freq);
    int cnt=0;
    for(int i=0;i<n;i++){
        freq[arr[i]]--;
        update(0,0,maxi,arr[i],freq[arr[i]],seg); // freqeuency update karo of element arr[] abhi ek minus kari thi freqency
        cnt+=query(0,maxi,1,arr[i]-1,0,seg);
    }
    cout<<"total number of conversion pair is "<<cnt;

}