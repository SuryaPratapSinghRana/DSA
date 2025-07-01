#include<iostream>
#include<stack>
using namespace std;
int mincost(string str)
{
 if(str.length()%2==1)
 {
    return -1;
 }
 stack<char> st;
 for(int i=0;i<str.length();i++){
    char ch=str[i];
    if(ch=='{')
    st.push(ch);
    else{
         // closing braces hoga
         if(!st.empty() && st.top()=='{')
          st.pop();
          else
          st.push(ch);

    }
     
 }
 // now stack contain invalid expression
 int a=0,b=0;
  while(!st.empty())
  {
    if(st.top()=='{')
    a++;
    else 
    b++;
    st.pop();
  }
  int ans=(a+1)/2 +(b+1)/2;
  return ans;

}
int main()
{
    string str="))((((";
  int cost=mincost(str);
  cout<<" the answer is "<<cost;
    return 0;
}