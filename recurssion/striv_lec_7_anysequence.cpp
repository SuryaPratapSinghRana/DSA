#include<iostream>
#include<vector>
using namespace std;
bool printanyseq(int index,vector<int> &ans,int arr[],int n,int s,int sum)
{
    if(index==n)
    {   if(s==sum){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return true;
       }
        return false;
    }
    // take or pick particular index into subsequence
    ans.push_back(arr[index]);
    s=s+arr[index];
    if(printanyseq(index+1,ans,arr,n,s,sum)==true){
      return true;
    }
    ans.pop_back();
    s=s-arr[index];
    // not take or not pick particular index into subsequence
    if(printanyseq(index+1,ans,arr,n,s,sum)==true)
    {
        return true;
    }
    return false;
}
int main(){
int arr[]={1,1,2};
vector<int> ans;
int n=3;
int sum=2;
printanyseq(0,ans,arr,n,0,sum);
    return 0;
}