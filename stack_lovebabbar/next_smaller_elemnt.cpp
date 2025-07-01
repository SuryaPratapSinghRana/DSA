#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextsmaller(vector<int> arr)
{
  stack<int> st;
  st.push(-1);
  int size=arr.size();
  vector<int> ans(size);
 
 for(int i=size-1;i>=0;i--)
 {
   while(st.top()>=arr[i])
   {
    st.pop();
   }
   ans[i]=st.top();
   st.push(arr[i]);
 }
 
 return ans;

}
int main()
{
    vector<int> arr;
    arr={4,3,1,2};
    vector<int> ans=nextsmaller(arr);
    for(int i=0;i<(arr.size());i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}