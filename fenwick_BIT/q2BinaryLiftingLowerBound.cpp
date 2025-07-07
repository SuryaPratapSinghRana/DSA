#include<bits/stdc++.h>
using namespace std;

void update(int i,int val,vector<int>&fen){
 int n=fen.size();
 while(i<n){
    fen[i]+=val;
    i=i+(i&(-i));
 }
}

int findlowerbound(int k,vector<int>&fen){
    int n=fen.size();
    int curr=0,prevsum=0;
    for(int i=log2(n);i>=0;i--){
        if(fen[curr+(1<<i)]+prevsum<k)  // 1<<i  work as pow(2,i);
        {
            curr=curr+(1<<i);
            prevsum+=fen[curr];
        }
    }
    return curr+1;
}

int main(){
  cout<<"enter the size of array "<<endl;
  int n;
  cin>>n;
  cout<<"enter the array ";
  vector<int>arr(n),fen(n+1,0);
  for(int i=0;i<n;i++){
    cin>>arr[i];
    update(i+1,arr[i],fen); // because one base indexing ki fenwick mein
  }
  
  cout<<"enter which num lower bound "<<endl;
  int k;
  cin>>k; 
  cout<<"the answer "<<findlowerbound(k,fen);

    return 0;
}