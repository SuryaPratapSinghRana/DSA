#include<iostream>
using namespace std;

class cirque{
    int front;
    int rear;
    int *arr;
    int size;
    public:
    cirque(){
        size=1000;
        arr=new int[size];
        front=rear=-1; // aise bhi assign kar sakte h;
    }
    bool enque(int value)
    {
        if((front==0 && rear==(size-1)) || (rear==(front-1)%(size-1))){
            cout<<"queue is full ";
            return false;
        }
        else if(front==-1) // jab dono -1 pe ho
        {
            front=rear=0;
            arr[rear]=value;
        }
        else if(rear=size-1 && front!=0) // jab rear last mein ho aur front kahi aur jgah ho mtlb element mein space h
        {
            rear=0;
            arr[rear]=value;
        }
        else{ // ya phir rear bich mein ho
            rear++;
            arr[rear]=value;
        }
        return true;
    }
    int dequeue()
    {
        if(front==-1)
         {
            cout<<"queue is empty ";
            return -1;
         }
         int ans=arr[front];
         if(front==rear) // single element present
         {
            front=rear=-1;
         }
         else if(front==size-1){ // jab front last mein ho
            front=0;
         }
         else{
            front++;
         }
         return ans;

    }

};
int main()
{
cirque q;
q.enque(12);
    return 0;
}