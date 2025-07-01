#include<iostream>
using namespace std;
int main(){
int arr[8]={2,0,1,5,0,6,0,0};
int j=0;
for(int i=0;i<8;i++)
{
   
       if(arr[i]!=0)
       {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        j++;
       }
     
}
for(int i=0;i<8;i++)
{
    cout<<arr[i]<<" ";
}
    return 0;
}