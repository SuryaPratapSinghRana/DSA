int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int m=str1.length();
  int n=str2.length();
  vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
  for(int i=0;i<=n;i++)
  {
        dp[0][i]=0;
  }
   for(int i=0;i<=m;i++)
  {
        dp[i][0]=0;
  }
for(int i=1;i<=m;i++)
{
  for(int j=1;j<=n;j++)
  {
    if(str1[i-1]==str2[j-1])
    {
      dp[i][j]=1+dp[i-1][j-1];
    }
    else{
      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
}
 return dp[m][n];
}