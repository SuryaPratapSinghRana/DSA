#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st,int val)
{
    if(st.empty())
    {
        st.push(val);
        return;
    }
    int top=st.top();  
     st.pop();
     // recursive call
     insertAtBottom(st,val);
     st.push(top);

}
void reverse(stack<int> &st)
{
 if(st.empty())
 {
  return;
 }
 int top=st.top();
 st.pop();
 // recursive call
 reverse(st);
 int count=0;
 int size=st.size();
 insertAtBottom(st,top);
}
int main()
{
    stack<int> st;
   st.push(6);
   st.push(3);
   st.push(7);
   st.push(9);
   st.push(5);
reverse(st);
int size=st.size();
// showing data
   for(int i=0;i<size;i++)
   {
    cout<<st.top();
    st.pop();
   }
    return 0;
}