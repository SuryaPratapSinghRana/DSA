#include<iostream>
using namespace std;
class DEque{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    DEque()
    {
        size=5;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    void pushfront(int value)
    { 
        if((rear+1)%size==front)
        {
            cout<<"queue is full ";
        }
        else{
            if(front==-1){
             front++;
             rear++;
            }
            else if(front==0){
                front=size-1;
            }
             else{
                front--;
            }
        }
        arr[front]=value;
    }
    void pushback(int value)
    {
        if((rear+1)%size==front)
        {
            cout<<" dequeue is full ";

        }
        else{
            if(front==-1)
             {
                front++;
             rear++;
             }
            else{
             rear=(rear+1)%size;
            }
            arr[rear]=value;
        }
    }
    int popfront()
    {
        if(front==-1)
        {
            cout<<" queue is empty "<<endl;
            return -1;
        }
        else if(front==rear)
        {
            int temp=arr[front];
            front=-1;
            rear=-1;
            return temp;
        }
        else{
            int temp=arr[front];
            front=(front+1)%size;
            return temp;
        }
        
    }
    int popback()
    {
        if(front==-1)
        {
            cout<<" queue is empty "<<endl;
            return -1;
        }
        else if(front==rear)
        {
            int temp=arr[rear];
            rear=-1;
            front=-1;
            return temp;
        }
        else if(rear==0 ){
           int temp=arr[rear];
           rear=size-1;
           return temp;
        }
        else{
            int temp=arr[rear];
            rear--;
            return temp;
        }
    }
    void display()
{ int f=front;
    while(f!=rear)
    {
       printf(" %d ",arr[f]);
      f=(f+1)%size;
    }
   printf(" %d \n",arr[f]);
}
};
int main()
{
DEque q;
q.pushfront(3);
q.pushfront(1);
q.pushfront(6);
q.pushback(4);
q.pushback(2);
q.display();
q.popfront();
q.display();
q.popback();
q.display();
    return 0;
}