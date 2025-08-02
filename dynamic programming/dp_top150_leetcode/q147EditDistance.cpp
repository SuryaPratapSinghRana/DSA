Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

// memoization

class Solution {
public:
   int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
   { 
     
      if(i<0)
      {
        return j+1;
      }
      if(j<0)
        return i+1;
      if(dp[i][j]!=-1)
        return dp[i][j];
      if(s1[i]==s2[j])
      { 
        return dp[i][j]=0+solve(i-1,j-1,s1,s2,dp);

      }
      int del=1e8;
      int insert=1e8;
      int replace=1e8;
      del=1+solve(i-1,j,s1,s2,dp);
      insert=1+solve(i,j-1,s1,s2,dp);
      replace=1+solve(i-1,j-1,s1,s2,dp);
      return dp[i][j]=min(del,min(insert,replace));
         
   }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        string ans="";
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,word1,word2,dp);

    }
};

// tabulation

int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        //  return solve(m-1,n-1,word1,word2,dp);
        // solving tabulation as on base of length
        // if i=0 length then to make word2 it takes j operation all insert
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        // if j=0 length then to make word2 is to delete all i
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = 0 + dp[i-1][j-1];

                } else {
                    int del = 1e8;
                    int insert = 1e8;
                    int replace = 1e8;
                    del = 1 + dp[i-1][j];
                    insert = 1 + dp[i][j-1];
                    replace = 1 + dp[i-1][j-1];
                    dp[i][j] = min(del, min(insert, replace));
                }
            }
        }
        return dp[m][n];
    }
};