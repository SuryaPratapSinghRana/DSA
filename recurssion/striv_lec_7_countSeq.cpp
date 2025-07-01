#include<iostream>
#include<vector>
using namespace std;
int countsubsetsum(int index,vector<int> &ans,int arr[],int n,int s,int sum)
{
    if(index==n)
    {   if(s==sum){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return 1;
       }
        return 0;
    }
    // take or pick particular index into subsequence
    ans.push_back(arr[index]);
    s=s+arr[index];
    int l=countsubsetsum(index+1,ans,arr,n,s,sum);
    ans.pop_back();
    s=s-arr[index];
    // not take or not pick particular index into subsequence
    int r=countsubsetsum(index+1,ans,arr,n,s,sum);
    return r+l;
}
int main(){
int arr[]={1,1,2};
vector<int> ans;
int n=3;
int sum=2;
int count=countsubsetsum(0,ans,arr,n,0,sum);
cout<<"the count is "<<count;
    return 0;
}