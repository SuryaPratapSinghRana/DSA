#include<iostream>
#include<queue>
using namespace std;
void reverseq(queue<int> &q)
{  // base case
    if(q.empty()){
    return;
    }
    int element=q.front();
    q.pop();
    // recursive call
    reverseq(q);
    q.push(element);

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
    return 0;
}