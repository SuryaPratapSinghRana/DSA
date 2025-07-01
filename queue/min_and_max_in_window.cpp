#include<iostream>
#include<queue>
using namespace std;
int solve(int arr[],int k,int n)
{

    deque<int> dq_min;
    deque<int> dq_max;
    // checking first window
    for(int i=0;i<k;i++)
    { 
        while(!dq_max.empty() && arr[dq_max.back()]<=arr[i])
         dq_max.pop_back();

        while(!dq_min.empty() && arr[dq_min.back()]>=arr[i])
         dq_min.pop_back();
        
         dq_max.push_back(i);
         dq_min.push_back(i);

     }
     int ans=0;
     for(int i=k;i<n;i++)
     {
        ans+=arr[dq_max.front()] +arr[dq_min.front()];
        // next window

        //removal
        while(!dq_max.empty() && i-dq_max.front()>=k){
            dq_max.pop_back();
        }

        while(!dq_min.empty() && i-dq_min.front()>=k){
            dq_min.pop_back();
        }
        // addition
          while(!dq_max.empty() && arr[dq_max.back()]<=arr[i])
           dq_max.pop_back();

        while(!dq_min.empty() && arr[dq_min.back()]>=arr[i])
         dq_min.pop_back();
        
         dq_max.push_back(i);
         dq_min.push_back(i);
           
     }
     // make sure last wali window
      ans+=arr[dq_max.front()] +arr[dq_min.front()];
     return ans;
}  
int main()
{
    int k=2; // k is window of size 2
int arr[]={2,5,-1,7,-3,-1,-2};
cout<<"the answer is  "<<solve(arr,4,6);
    return 0;
}