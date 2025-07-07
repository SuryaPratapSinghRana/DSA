#include <bits/stdc++.h> 

int mult(int i,int j,vector<int> &arr,vector<vector<int>> &dp)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int mini=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int step=(arr[i-1])*(arr[k])*(arr[j])+mult(i,k,arr,dp)+mult(k+1,j,arr,dp);
        mini=min(mini,step);
    }
    return dp[i][j]= mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return mult(1,N-1,arr,dp);
} 