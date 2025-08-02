// memoization
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


// tabulation

#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

    int ninjaTraining(int n, vector<vector<int>> &points)
   {    
    // Write your code here.

    vector<int> dp(4,0);
    dp[0]=max(points[0][1],points[0][2]);
     dp[1]=max(points[0][0],points[0][2]);
      dp[2]=max(points[0][1],points[0][0]);
       dp[3]=max(points[0][0],max(points[0][2],points[0][1]));
       for(int day=1;day<n;day++)
       { vector<int> temp(4,0);
           for(int last=0;last<4;last++)
           {    
              temp[last]=0;
               for(int i=0;i<3;i++)
               {
                   if(i!=last)
                   {
                       int p=points[day][i]+dp[i];
                       temp[last]=max(p,temp[last]);
                   }
               }
           }
           dp=temp;
       }
       return dp[3];
}