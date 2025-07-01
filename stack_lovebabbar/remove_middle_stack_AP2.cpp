// BY RECURSSION
#include<iostream>
#include<stack>
using namespace std;
void removemiddle(stack<int> &st,int count,int size)
{  // base case
   if(count==size/2)
   {
    st.pop();
    return;

   }
   int num=st.top();
   st.pop();
   // recursive call
    removemiddle(st,count+1,size);
    st.push(num);
   
}
int main()
{
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(9);
    st.push(1);
    st.push(2);
    int count=0;
    removemiddle(st,count,st.size());
     cout<<st.top();
     st.pop();
     cout<<st.top();
     st.pop();
     cout<<st.top();
     st.pop();
     cout<<st.top();
     st.pop();
    return 0 ;
}