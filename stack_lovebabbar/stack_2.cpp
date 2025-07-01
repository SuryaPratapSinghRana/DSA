#include<iostream>
using namespace std;
class twostack{
    public:
 int* arr;
 int top1;
 int top2;
 int size;
 twostack(int size)
 {
   this->size=size;
   top1=-1;
   top2=size;
   arr=new int[size];


 }
 void push1(int element)
 {
    if(top2-top1>1){
        top1++;
        arr[top1]=element;
    }
    else{
        cout<<"stack is overflow"<<endl;
    }

 }
 void push2(int element)
 {
    if(top2-top1>1){
        top2--;
        arr[top2]=element;
    }
    else{
        cout<<"stack is overflow"<<endl;
    }

 }
 int pop1()
 {
   if(top1>=0)
   { int ans=arr[top1];
    top1--;
    return ans;
   }
   else{
   return -1;
   }
 }
 int pop2()
 {
   if(top2<size)
   { int ans=arr[top2];
    top2++;
    return ans;
   }
   else{
   return -1;
   }
 }
//  int peek()
//  {
//     if(top>=0 )
//     {
//         return arr[top];
//     }
//     else 
//     {
//         cout<<" stack is empty ";
//         return -1;
//     }

//  }
//  bool isempty()
//  {
//     if(top==-1)
//        return true;
//     else
//     return false;
//      }
 };
int main()
{
 twostack st(5);
 st.push1(34);
 st.push2(56);
 st.push1(7);
 st.push2(6);

    return 0;
}