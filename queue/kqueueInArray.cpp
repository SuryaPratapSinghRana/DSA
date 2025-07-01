#include<iostream>
using namespace std;
class kqueue
    {
    private:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int *next;
    int index;
    int freespot;
    public:
    kqueue(int n,int k)
    { this->n=n;
      this->k=k;
      front=new int[k];
      rear=new int[k];
      next=new int[n];
      arr=new int[n];
      for(int i=0;i<k;i++)
      {
        front[i]=-1;
        rear[i]=-1;
      }
      for(int i=0;i<n;i++)
      {
        next[i]=i+1;
      }
      next[n-1]=-1;
      freespot=0;
    }
    void enqueu(int data,int qn){
      if(freespot==-1)
      {
        cout<<"queue is overflow";
      }
      else if(front[qn-1]==-1)
      {
        index=freespot;
        freespot=next[index];
        next[index]=-1;
        arr[index]=data;
        front[qn-1]=index;
        rear[qn-1]=index;

      }
      else{
        // link element with previos element wala case
        index=freespot;
        freespot=next[index];
        next[rear[qn-1]]=index;
        next[index]=-1;
        arr[index]=data;
        front[qn-1]=index;
        rear[qn-1]=index;
      }
    }
    int  dequeue(int qn)
    {
      if(front[qn-1]==-1)
      {
        cout<<"queue is empty ";
        return -1;
      }
      else if(front[qn-1]==rear[qn-1])
      {
         int index=front[qn-1];
        front[qn-1]=-1;
        rear[qn-1]=-1;
        // free slot ko manage karo
       next[index]=freespot;
       freespot=index;
       return arr[index];
      }
      else{
        int index=front[qn-1];
       front[qn-1]=next[front[qn-1]];
       // free slot ko manage karo
       next[index]=freespot;
       freespot=index;
       return arr[index];
      }
    }
    };

    int main()
    {
     kqueue k(9,3);
     k.enqueu(34,1);
     k.enqueu(89,2);
     k.enqueu(23,3);
     cout<<k.dequeue(1)<<endl;
     cout<<k.dequeue(2)<<endl;
     cout<<k.dequeue(3)<<endl;
     cout<<k.dequeue(3)<<endl;
      return 0;
    }