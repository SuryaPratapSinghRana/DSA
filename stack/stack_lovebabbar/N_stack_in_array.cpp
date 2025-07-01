#include<iostream>
using namespace std;
class nstack
{
    int *arr;
    int *top;
    int *next;

    int n,s;
    int freespot;
    public:
    nstack(int N,int s)
    {
        n=N;
        arr=new int[s];
        top=new int[n];
        next=new int[s];

        // top intiallize
        for(int i=0;i<n;i++)
        {
            top[i]=-1;
            
        }

        // next intiallize
        for(int i=0;i<s;i++)
        {
            next[i]=i+1;
        }
        // update last index value to -1
        next[s-1]=-1;
        // intialize free spot
        freespot=0;
        
    }
    bool push(int x,int m)
    {
        // check overflow
        if(freespot==-1)
        return false;
        // find index
        int index=freespot;
        // update freespot
         freespot=next[index];
         // insert element into array  
         arr[index]=x;
         // update next
         next[index]=top[m-1];
         // update top
         top[m-1]=index;
         return true;
    }
    int pop( int m)
    {
        // check underflow condition
        if(top[m-1]==-1)
        return -1;
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }

};
int main()
{
    nstack* st=new nstack(3,9);

}