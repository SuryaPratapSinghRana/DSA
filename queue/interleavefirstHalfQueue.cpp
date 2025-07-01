#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void interleave(queue<int> &q)
{
    stack<int> st;
 int n=q.size();
 // step 1: put first half in stack;
 for(int i=0;i<n/2;i++)
 {
    int val=q.front();
    q.pop();
    st.push(val);
 }
 // step 2: push stack elements in queue
 while(!st.empty())
 {
    int val=st.top();
    st.pop();
    q.push(val);
 }
 // step3:now first half push in q last
  for(int i=0;i<n/2;i++)
  {
    int val=q.front();
    q.pop();
    q.push(val);
  }
  // step 1: put first half in stack again;
 for(int i=0;i<n/2;i++)
 {
    int val=q.front();
    q.pop();
    st.push(val);
 }
// step 5: now push stack element in queue altenate with exist element
while(!st.empty())
{
    int val=st.top();
    st.pop();
    q.push(val);
    val=q.front();
    q.pop();
    q.push(val);
}
}
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
  interleave(q);
  while(!q.empty())
  {
    cout<<q.front()<<" ";
    q.pop();
  }
    return 0;
}