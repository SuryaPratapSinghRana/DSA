#include<iostream>
using namespace std;
void merge(int arr1[],int n1,int arr2[],int n2,int arr3[])
{int i=0,j=0,k=0;
  while(i<n1 && j<n2)
  {
    if(arr1[i]<arr2[j])
    {
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    else
    {
        arr3[k]=arr2[j];
        j++;
        k++;
    }
  }
  while(i<n1)
  {
    arr3[k]=arr1[i];
    i++;
    k++;
  }
  while(j<n2)
  {
    arr3[k]=arr2[j];
    j++;
    k++;
  }
}
void print(int arr3[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr3[i];
    }
}
int main()
{
    int arr1[5]={1,3,5,7,8};
    int arr2[5]={2,4,6};
    int arr3[8]={0};
     merge(arr1,5,arr2,3,arr3);
     print(arr3,8);
    return 0;
}