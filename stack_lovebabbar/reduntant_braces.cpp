#include<iostream>
#include<stack>
using namespace std;
bool findredundant(string str)
{
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        char ch=str[i];
        if(ch=='{' || ch=='*' || ch=='+' || ch=='-' || ch=='/')
        {
            st.push(ch);
        }
        else{
            if(ch=='}')
            {
                bool isredundant=true;
                while(st.top()!='{')
                {
                    char top=st.top();
                    if( top=='*' || top=='+' || top=='-' || top=='/')
                    isredundant=false;
                  st.pop();
                }
                if(isredundant==true)
                {
                    return isredundant;
                }
                  st.pop();
            } 
        }
    }
    return false;
}

int main()
{
 string str="{{a+b}}";
 if(findredundant(str))
 {
    cout<<"braces is reduntant"<<endl;

 }
 else
 cout<<" brace is not reduntant "<<endl;
    return 0;
}