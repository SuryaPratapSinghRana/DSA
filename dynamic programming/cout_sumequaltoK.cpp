class Solution{

	public:
	int find(int ind,int target,int arr[],vector<vector<int>>&dp)
	{  
	 
	    if(ind==0)
	    {  
	        if(target==0 && arr[0]==0)
	          return 2;
	        if(target==0 || arr[0]==target)
	         return 1;
	        return 0;
	    }
	      if(dp[ind][target]!=-1)
	        return dp[ind][target];
	     int not_take=find(ind-1,target,arr,dp);
	     int take=0;
	     if(target>=arr[ind])
	     {
	         take=find(ind-1,target-arr[ind],arr,dp);
	     }
	     return dp[ind][target]= not_take+take;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return find(n-1,sum,arr,dp);
	}
	
	  
};