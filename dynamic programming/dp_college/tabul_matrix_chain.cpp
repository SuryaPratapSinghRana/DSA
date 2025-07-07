
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=N-1;i>0;i--)
    {
        for(int j=i+1;j<N;j++)
        {
            int mini=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int step=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                mini=min(step,mini);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][N-1];
}