#include <bits/stdc++.h> 
int knap(int ind,int capacity,vector<int> &weight,vector<int> &value,vector<vector<int>> &dp)
{
   if(ind==0)
   {
	   if(capacity>=weight[ind])
	   {
		   return value[ind];
	   }
	   return 0;
   }
   if(dp[ind][capacity]!=-1)
   {
	   return dp[ind][capacity];
   }
   int not_take=0+knap(ind-1,capacity,weight,value,dp);
   int take=INT_MIN;
   if(capacity>=weight[ind])
   {
	   take=value[ind]+knap(ind-1,capacity-weight[ind],weight,value,dp);
   }
   return dp[ind][capacity]= max(not_take,take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here

	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    return knap(n-1,maxWeight,weight,value,dp);
}