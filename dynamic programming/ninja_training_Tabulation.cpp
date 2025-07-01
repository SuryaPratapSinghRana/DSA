#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
int ninjaTraining(int n, vector<vector<int>> &points)
{    
    // Write your code here.

    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0]=max(points[0][1],points[0][2]);
     dp[0][1]=max(points[0][0],points[0][2]);
      dp[0][2]=max(points[0][1],points[0][0]);
       dp[0][3]=max(points[0][0],max(points[0][2],points[0][1]));
       for(int day=1;day<n;day++)
       {
           for(int last=0;last<4;last++)
           {  int maxi=0;
               for(int i=0;i<3;i++)
               {
                   if(i!=last)
                   {
                       int p=points[day][i]+dp[day-1][i];
                       maxi=max(p,maxi);
                   }
               }
               dp[day][last]=maxi;
           }
       }
       return dp[n-1][3];
}

/* doing below space optimization */
/*

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



*/