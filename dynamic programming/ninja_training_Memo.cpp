#include<vector>
int meritpoint(int day,int last,vector<vector<int>> & arr,vector<vector<int>> &dp,int n)
{
   if(day==0)
   { 
       int maxi=0;
       for(int i=0;i<=2;i++)
       {
          if(i!=last)
          {
              maxi=max(arr[0][i],maxi);

          }
       }
       return maxi;
   }
   if(dp[day][last]!=-1)
   {
       return dp[day][last];
   }
    int maxi=0;
   for(int i=0;i<=2;i++)
   {
       if(i!=last)
       {
           int p=arr[day][i]+meritpoint(day-1,i,arr,dp,n);
           maxi=max(p,maxi);
       }
   }
   return dp[day][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{    
    // Write your code here.

    vector<vector<int>> dp(n,vector<int>(4,-1));
    return meritpoint(n-1,3,points,dp,n);
}