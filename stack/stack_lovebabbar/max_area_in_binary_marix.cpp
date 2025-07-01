#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextsmaller(int* heights,int n)
{
    stack<int> st;
    st.push(-1);
    //int n=heights.size();
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        while(st.top()!=-1 && heights[st.top()]>heights[i])
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevsmaller(int* heights,int n)
{
    stack<int> st;
    st.push(-1);
   // int n=heights.size();
    vector<int> ans(n);
    for(int i=0;i<n;i++)
    {
        while(st.top()!=-1 && heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
int largestrectanglearea(int* heights,int n)
{
    vector<int> nxt=nextsmaller(heights,n);
    vector<int> prev=prevsmaller(heights,n);
    //int n=heights.size();
    int area=0;
    for(int i=0;i<n;i++)
    {
        int next=nxt[i];
        if(nxt[i]==-1)
     {
        next=n;
     }
      
      int previous=prev[i];
      int breadth=next-previous-1;
      int newarea=(heights[i])*breadth;
    //   if(area<=newarea){
    //     area=newarea;   // ya max  func lga do
    //   }
    area=max(newarea,area);
    }
    return area;


}
int maxarea(int M[3][3],int n,int m)
{
    // compute area for firs row
    int area=largestrectanglearea(M[0],m);
    // for remaining row
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            // row update by adding previos value
            if(M[i][j]!=0)
             M[i][j]=M[i][j]+M[i-1][j];
             else
             M[i][j]=0;
        }
        // entire row is updated row
        area=max(area,largestrectanglearea(M[i],n));
    }
    return area;
}
int main()
{
  int m[3][3];
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
        cin>>m[i][j];
    }
  }
  int area=maxarea(m,3,3);
  cout<<" the max area is "<<area;
    return 0;
}