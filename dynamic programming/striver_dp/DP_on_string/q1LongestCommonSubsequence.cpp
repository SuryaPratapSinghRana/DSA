// memoization

#include <bits/stdc++.h> 
int lcs(int m,int n,string &str1,string &str2,vector<vector<int>> &dp)
{
  if(m==0 || n==0)
  {
    return 0;
  }
  if(dp[m][n]!=-1){
    return dp[m][n];
  }
  if(str1[m-1]==str2[n-1])
  {
    return dp[m][n]=1+ lcs(m-1,n-1,str1,str2,dp);
  }
  else
    return dp[m][n]=max(lcs(m,n-1,str1,str2,dp),lcs(m-1,n,str1,str2,dp));
}
int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int m=str1.length();
  int n=str2.length();
  vector<vector<int>> dp(m,vector<int>(n,-1));
 return lcs(m,n,str1,str2,dp);
}

// tabulation 
#include <bits/stdc++.h> 
int lcs(int m,int n,string &str1,string &str2,vector<vector<int>> &dp)
{
  if(m==0 || n==0)
  {
    return 0;
  }
  if(dp[m][n]!=-1){
    return dp[m][n];
  }
  if(str1[m-1]==str2[n-1])
  {
    return dp[m][n]=1+ lcs(m-1,n-1,str1,str2,dp);
  }
  else
    return dp[m][n]=max(lcs(m,n-1,str1,str2,dp),lcs(m-1,n,str1,str2,dp));
}
int getLengthOfLCS(string & str1, string & str2) {
  // Write your code here.
  int m=str1.length();
  int n=str2.length();
  vector<vector<int>> dp(m,vector<int>(n,-1));
 return lcs(m,n,str1,str2,dp);
}