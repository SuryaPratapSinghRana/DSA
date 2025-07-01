#include<bits/stdc++.h>
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(w+1,0));
      for(int i=0;i<=w;i++)
	  {
		  if(i<weights[0])
		  {
          dp[0][i]=0;
		  }
		  else
		  {
            dp[0][i]=values[0];
		  }

	  }

	  for(int ind=1;ind<n;ind++)
	  {
		  for(int capacity=0;capacity<=w;capacity++)
		  {
			  int not_take=0+dp[ind-1][capacity];
			  int take=INT_MIN;
			  if(capacity>=weights[ind])
			  {
				  take=values[ind]+dp[ind-1][capacity-weights[ind]];
			  }
			  dp[ind][capacity]=max(not_take,take);
		  }
	  }
	  return dp[n-1][w];
    }
