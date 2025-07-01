#include<iostream>
using namespace std;
int fibbonaci(int n)
{
    if(n==0 )
    {
        return 0;

    }
    if(n==1)
    {
        return 1;
    }
    int fib=fibbonaci(n-1)+fibbonaci(n-2);
    return fib;
}
int main()
{
     int n=7;
   int ans= fibbonaci(n);
   cout<<" the "<<n<<" element of fibbonaci series is "<<ans;
   return 0;
}