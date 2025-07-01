#include<iostream>
using namespace std;
class queue{
    int *arr;
    int qfront;
    int rear;
    int size;
    public:
    queue()
    {
        size=1000;
        arr=new int[size];
        qfront=0;
        rear=0;
    }
    void enqueue(int data)
    {
        if(rear==size)
        cout<<" queue is full "<<endl;
        else
        {
            arr[rear]=data;
            rear++;
        }

    }
    int dequeue()
    {    int ans=arr[qfront];
        if(qfront==rear)
         return -1;
         else{
            arr[qfront]=-1;
             qfront++;
             if(qfront==rear)
              qfront=0;
              rear=0;
         }
         return ans;
    }
    int front()
    {
        if(qfront==rear)
         return -1;
         else
         return arr[qfront];
    }
    bool isempty()
    {
        if(qfront==rear)
         return true;
         else
         return false;
    }
};
int main()
{
queue q1;
cout<<q1.front();
    return 0;
}