#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool knows(vector<vector int> &m,int a,int b,int n)
{
    if(m[a][b==1])
     return true;
     else 
     return false;
}
int celebrity(vector<vector int> &m,int n)
{
    stack<int> st;
    // push all element in stack
    for(int i=0;i<n;i++)
    {
        st.push(i);
    }
    // get two elements and compare them
    while(st.size()>1)
    {
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(knows(m,a,b,n))
        {
            st.push(b);
        }
        else
        st.push(a);
    }
    int ans=st.top();
    // single element in stack is potential candidate
    // now check row
    int zerocount=0;
    for(int i=0;i<n;i++)
{
    if(m[ans][i]==0)
    zerocount++;
}
if(zerocount!=n)
 return -1;
 // now check column
 int countones=0;
 for(int i=0;i<n;i++)
 {
    if(m[i][ans]==1)
     countones++;
 }
 if(countones!=n-1)
  return -1;
  return ans;

    

}
int main()
{
    return 0; 
}