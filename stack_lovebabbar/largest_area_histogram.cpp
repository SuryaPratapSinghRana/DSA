#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextsmaller(vector<int> heights)
{
    stack<int> st;
    st.push(-1);
    int n=heights.size();
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
vector<int> prevsmaller(vector<int> heights)
{
    stack<int> st;
    st.push(-1);
    int n=heights.size();
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
int findarea(vector<int> heights)
{
    vector<int> nxt=nextsmaller(heights);
    vector<int> prev=prevsmaller(heights);
    int n=heights.size();
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
int main()
{
    vector<int> heights={1,2,5,6,3,1,2};
  int area= findarea(heights);
   cout<<" max area is "<<area;
    return 0;
}