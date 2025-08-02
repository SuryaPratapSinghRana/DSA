Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
substrings
 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b

// 3d dp

class Solution {
public:
   int m,n,N;
   int solve(int i,int j,int k,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp)
   {
    if(i==m && j==n && k==N)
    {
        return  true;
    }
    if(k>=N || j>n || i>m)
      return false;
    if(dp[i][j][k]!=-1)
      return dp[i][j][k];
    int takei=0,takej=0;
    if(s1[i]==s3[k])
    {
        takei=solve(i+1,j,k+1,s1,s2,s3,dp);
    }
    if(s2[j]==s3[k])
      {
        takej=solve(i,j+1,k+1,s1,s2,s3,dp);
      }
      return dp[i][j][k] =takei || takej;
   }
    bool isInterleave(string s1, string s2, string s3) {
         m=s1.length();
         n=s2.length();
         N=s3.length();
       vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(N+1, -1)));
        return solve(0,0,0,s1,s2,s3,dp);

    }
};
      
// 2d dp     replace k with i+j
class Solution {
public:
   int m,n,N;
   int solve(int i,int j,string &s1,string &s2,string &s3,vector<vector<int>>&dp)
   {
    if(i==m && j==n && i+j==N)
    {
        return  true;
    }
    if(i+j>=N || j>n || i>m)
      return false;
    if(dp[i][j]!=-1)
      return dp[i][j];
    int takei=0,takej=0;
    if(s1[i]==s3[i+j])
    {
        takei=solve(i+1,j,s1,s2,s3,dp);
    }
    if(s2[j]==s3[i+j])
      {
        takej=solve(i,j+1,s1,s2,s3,dp);
      }
      return dp[i][j]=takei || takej;
   }
    bool isInterleave(string s1, string s2, string s3) {
         m=s1.length();
         n=s2.length();
         N=s3.length();
         vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,s1,s2,s3,dp);

    }
};

// tabulation


class Solution {
public:
   int m,n,N;
    bool isInterleave(string s1, string s2, string s3) {
         m=s1.length();
         n=s2.length();
         N=s3.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        

        if (m + n != N) return false;

       // base case if length =0
         dp[0][0]=1;

        // filling first row when s2 have 0 length

        for(int i=1;i<=m;i++)
        {
            if(s1[i-1]==s3[i-1])
              dp[i][0]=dp[i-1][0];
        }

        // filling first colm when s1 have 0 length
        for(int j=1;j<=n;j++)
        {
            if(s2[j-1]==s3[j-1])
              dp[0][j]=dp[0][j-1];
        }

        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {  
                int takei=0,takej=0;
                if(s1[i-1]==s3[i+j-1])
                  takei=dp[i-1][j];
                if(s2[j-1]==s3[i+j-1])
                  takej=dp[i][j-1];
                dp[i][j]=(takei ||takej);
            }
        }
        return dp[m][n];

    }
};
 