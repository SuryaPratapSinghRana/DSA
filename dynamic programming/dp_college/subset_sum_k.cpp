#include <bits/stdc++.h> 

int checksum(int i,int k,vector<int> &arr,vector<vector<int>> &dp)
{
    if(k==0)
    {

        return 1;
    }
    if(i==0)
    {
        if(arr[i]==k)
        {
            return 1;
        }
        return 0;
    }
    if(dp[i][k]!=-1)
    {
        return dp[i][k];
    }
    bool not_take=checksum(i-1,k,arr,dp);
    bool take=false;
    if(k>=arr[i])
    {
        take=checksum(i-1,k-arr[i],arr,dp);
    }
    return dp[i][k]=(take||not_take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
   dp[0][arr[0]]=true;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool not_take=dp[i-1][j];
            bool take=false;
            if(j>=arr[i]){
                 take=dp[i-1][j-arr[i]];
            }
           dp[i][j]=(take || not_take);
        }
    }
    return dp[n-1][k];
}