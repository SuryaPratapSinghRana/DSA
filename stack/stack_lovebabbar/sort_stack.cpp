// INSERT THE ELEMENT IN MIDDLE OF STACK
#include<iostream>
#include<stack>
using namespace std;
void sortinsert(stack<int> &st,int value)
{
    // base case
    if(st.empty()==true || st.top()<value)
    {
        st.push(value);
        return;
    }
    int top=st.top();
    st.pop();
    // recursive call
    sortinsert(st,value);
    st.push(top);


}
void sortstack(stack<int> &st)
{
    // base case
    if(st.empty())
    {
        return;
    }
    int top=st.top();
    st.pop();
    // recursive call
    sortstack(st);
    sortinsert(st,top);

}
int main()
{
   stack<int> st;
   st.push(6);
   st.push(3);
   st.push(-7);
   st.push(9);
   st.push(5);
 
   sortstack(st);
   cout<<"modify string is ";
     int size=st.size();
   for(int i=0;i<size;i++)
   {
    cout<<st.top();
    st.pop();
   }
   
    return 0;
}