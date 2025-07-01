// INSERT THE ELEMENT IN MIDDLE OF STACK
#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st,int val)
{   // base case
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
int main()
{
   stack<int> st;
   st.push(6);
   st.push(3);
   st.push(7);
   st.push(9);
   st.push(5);
   int count=0;
 
   insertAtBottom(st,8);
   cout<<"modify string is ";
     int size=st.size();
   for(int i=0;i<size;i++)
   {
    cout<<st.top();
    st.pop();
   }
   
    return 0;
}