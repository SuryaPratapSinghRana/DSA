class Solution {
  public:
 // at index ind lenght of rod is ind+1
    int func(int ind,int N,vector<int>&price,vector<vector<int>>&dp){
        if(ind==0)
        {
             return N*price[0];
        }
        if(dp[ind][N]!=-1)
          return dp[ind][N];
        int not_take=func(ind-1,N,price,dp);
        int take=INT_MIN;
        int rodlength=ind+1; // at ind lenght is ind+1;
        if(rodlength<=N){
            take=price[ind]+func(ind,N-rodlength,price,dp);
        }
        return dp[ind][N]=max(take,not_take);
    }
    int cutRod(vector<int> &price) {
        // code here
        int N=price.size(); // rod lenth;
        
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return func(N-1,N,price,dp);
        
    }
};