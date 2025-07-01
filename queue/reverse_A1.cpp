#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverseq(queue<int> &q)
{
    stack<int> st;
    int size=q.size();
    for(int i=0;i<size;i++)
    {
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<size;i++)
    {
        q.push(st.top());
        st.pop();
    }
}
int main()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(1);
    q.push(3);
    reverseq(q);
    int size=q.size();
    for(int i=0;i<size;i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}