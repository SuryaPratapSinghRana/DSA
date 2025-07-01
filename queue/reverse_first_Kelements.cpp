#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> reversek( queue<int> q,int k)
{  stack<int> st;
    // step 1. pop first k elements from queue to stack
     for(int i=0;i<k;i++)
     {
        int element=q.front();
        q.pop();
        st.push(element);
     }
     // step 2: fetch from stack push into queue
     while(!st.empty())
     {
        int val=st.top();
        st.pop();
        q.push(val);
     }
     // step 3 : fetch first n-k element from queue and push_back
     int t=q.size()-k;
     while(t--)
     { int val=q.front();
        q.pop();
        q.push(val);

     }
     return q;
}
int main()
{ int k=3;
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(1);
    q.push(3);
    queue<int> ans=reversek(q,k);
    int size=ans.size();
for(int i=0;i<size;i++)
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
    return 0;
}