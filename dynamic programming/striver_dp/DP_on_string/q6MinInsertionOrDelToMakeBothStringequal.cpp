class Solution {
public:
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
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return m+n-2*lcs(m,n,word1,word2,dp);
    }
};