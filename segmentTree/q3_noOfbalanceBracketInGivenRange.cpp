#include<bits/stdc++.h>
using namespace std;
struct info{
    int open,close,full;
    info(){}
    info(int _open,int _close,int _full)
    {
        open=_open;
        close=_close;
        full=_full;
    }
};
info merge(info left,info right)
{
    int full=left.full+right.full+min(left.open,right.close);
    int open=left.open+right.open-min(left.open,right.close);  // jo full banane mein use hue open braces vo minus karo
    int close=left.close+right.close-min(left.open,right.close); //jo full banane mein istmal hue close braces unhe minus karo
    info parent=info(open,close,full);
    return parent;
}
void build(int ind,int low,int high,vector<info>&seg,string&str)
{
    if(low==high){
        seg[ind]=info(str[low]=='(',str[low]==')',0);  // ye set kardega seg[ind] ko full shurur mein 0 rahega and open ,close 0 ya 1 set hojaenge vo condition 1 ya 0 pass karegi check karke
        return;
    }
    int mid=(low+high)/2;
    build(2*ind+1,low,mid,seg,str);
    build(2*ind+2,mid+1,high,seg,str);
    seg[ind]=merge(seg[2*ind+1],seg[2*ind+2]);
}


info query(int ind,int low,int high,int l,int r,vector<info>&seg){
    if(low>=l && high<=r){  // complete overlapping
        return seg[ind];
    }
    if(low>r || high<l){  // no-overlapping
        return info(0,0,0);
    }
   // partial-overlapping
   int mid=(low+high)/2;
    info left=query(2*ind+1,low,mid,l,r,seg);
    info right=query(2*ind+2,mid+1,high,l,r,seg);
    return merge(left,right);
}

int main(){
    string str;
    cout<<"enter the string ";
    cin>>str;
    int n=str.length();
    vector<info>seg(4*n);
    build(0,0,n-1,seg,str);
   cout<<"enter the query [l,r] "<<endl;
   int l,r;
   cin>>l>>r;
   cout<<"number of balanced between range"<<l<<" "<<r<<" is "<<query(0,0,n-1,l,r,seg).full;

}