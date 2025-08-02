#include <bits/stdc++.h> 
int knap(int ind,int capacity,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp)
{
   if(ind==0)
   {
	  return (capacity/weight[0])*value[0];
   }
   if(dp[ind][capacity]!=-1)
   {
	   return dp[ind][capacity];
   }
   int not_take=knap(ind-1,capacity,weight,value,dp);
   int take=INT_MIN;
   if(capacity>=weight[ind])
   {
	   take=value[ind]+knap(ind,capacity-weight[ind],weight,value,dp);
   }
   return dp[ind][capacity]= max(not_take,take);
}

int unboundedKnapsack(int n, int w, vector<int> &value, vector<int> &weight){
    // Write Your Code Here.
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return knap(n-1,w,weight,value,dp);
}