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
    int longestPalindromeSubseq(string s) {
      // s2 string reverse h string s ki bas dono ko paas kardenge longest common subsequence method mein
       string s2=s;
       reverse(s2.begin(),s2.end());
       int n=s.length();
       vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return lcs(n,n,s,s2,dp);


    }
};