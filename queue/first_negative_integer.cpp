#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> firstneg(int arr[],int k,int n)
{
  deque<int> dq;
  vector<int> ans;
  // processing first window of size k
  for(int i=0;i<k;i++)
  {
     if(arr[i]<0)
      dq.push_back(i);
  }
  // store answer of first window
   if(dq.size()>0)
   {
    ans.push_back(arr[dq.front()]);
   }
   else{
    ans.push_back(0);
   }
   // process for remaining window
    for(int i=k;i<n;i++)
    {
        // removal
        if(!dq.empty() && i-dq.front()>=k)
        {
            dq.pop_front();
        }
        // addition
        if(arr[i]<0)
        {
            dq.push_back(i);
        }
        // ans store
        if(dq.size()>0)
        {
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }

    }
    return ans;

}
int main()
{
    int k=2; // k is window of size 2
int arr[]={-8,3,4,-6,5,2};
vector<int> ans=firstneg(arr,k,6);
for(int i : ans)
{
    cout<<i<<" ";
}
    return 0;
}