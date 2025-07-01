#include<iostream>
#include<stack>
using namespace std;
class specialstack{
    stack<int> st;
     int mini;
    public:
    void push(int data)
    {
         if(st.empty())
         {
            mini=data;
            st.push(data);
         }
         else{
            if(data<mini)
            {
                int value=2*data-mini;
                st.push(value);
                mini=data;
            }
            else
            st.push(data);
         }
    }
    int pop()
    {
        if(st.empty())
        {
            return -1;
        }
        int curr=st.top();
        st.pop();
        if(curr>mini){
            return curr;
        }
        else{
            int prevmini=mini;
            int value=2*mini-curr;
            mini=value;
            return prevmini;
        }

    }
int top()
{
    if(st.empty())
    {
        return -1;
    }
    int curr=st.top();
    if(curr<mini)
    {
        return mini;
    }
    else{
        return curr;
    }
}
bool empty()
{
    return st.empty();
}
int getmin()
{
    if(st.empty())
    {
      return -1;
    }
    return mini;
}
};
int main()
{
    specialstack s;
    s.push(3);
    s.push(5);
    s.push(2);
    s.push(4);
    s.push(1);
    cout<<s.getmin();
}