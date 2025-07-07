#include<bits/stdc++.h>
using namespace std;

void update(int i,int val,vector<int>&fen){
 int n=fen.size();
 while(i<n){
    fen[i]+=val;
    i=i+(i&(-i));
 }
}

// return sum from 0 to i;
int sum(int i,vector<int>&fen)
{   int s=0;
    while(i>0){
        s+=fen[i];
        i=i-(i&(-i));
    }
    return s;
}

int range(int l,int r,vector<int>&fen){
    return sum(r,fen)-sum(l-1,fen);
}

int main(){
  cout<<"enter the size of array "<<endl;
  int n;
  cin>>n;
  cout<<"enter the array ";
  vector<int>arr(n),fen(n+1,0);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    update(i+1,arr[i],fen); // because on base indexing ki fenwick mein
  }
  
  cout<<"enter range to find sum "<<endl;
  int l,r;
  cin>>l>>r;  // l-r jo enter karenge wo one-based indexing hoga
  cout<<"the answer "<<range(l,r,fen);

    return 0;
}