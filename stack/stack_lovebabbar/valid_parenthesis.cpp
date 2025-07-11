#include <iostream>
#include <stack>
using namespace std;
bool validparen(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        // if opening bracket,stack push
        // if closing bracket,stacktop check and pop
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            // for closing bracket
            if (!st.empty())
            {
                char top = st.top();
                if (ch == ')' && top == '(' || ch == '}' && top == '{' || ch == ']' && top == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if(st.empty())
    {
           return true;
    }
    else
    return false;
}
int main()
{
    string str = "()(){()}";

    if (validparen(str))
    {
        cout << " balanced hai ";
    }
    else
    {
        cout << " not balanced ";
    }

    return 0;
}