Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

Example:

Input: heights[] = [20, 30, 40, 20] 
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20-30|  = 10
Total Cost = 10 + 10 = 20


#include<bits/stdc++.h>
class Solution {
  public:
    int func(int ind,int n,vector<int>&arr,vector<int>&dp){
        if(ind==n-1)
          return 0;
      if(dp[ind]!=-1)
        return dp[ind];
      int onejump=abs(arr[ind]-arr[ind+1])+func(ind+1,n,arr,dp);
      int twojump=INT_MAX;
      if(ind+2<n)
       twojump=abs(arr[ind]-arr[ind+2])+func(ind+2,n,arr,dp);
      
      return dp[ind]=min(onejump,twojump);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n=height.size();
        vector<int>dp(n,-1);
        return func(0,n,height,dp);
        
    }
};