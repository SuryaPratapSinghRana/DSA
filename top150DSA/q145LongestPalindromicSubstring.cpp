Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

class Solution {
public:
    int ispalindrom(int i,int j,string &s,vector<vector<int>>&dp)
    {
        int t1=i;
        int t2=j;
        while(t1<=t2)
        {
            if(s[t1]!=s[t2])
              return 0;
              t1++;
              t2--;
          
        }
        return 1;
    }
    int func(int i,int j,string &s,string &ans,int &maxi,vector<vector<int>>&dp)
    {
      if(i==j)
      {
        if(1>maxi)
        {
            ans=s.substr(i,j-i+1);
            maxi=1;
        }
        return dp[i][j]=1;
      }
      if(dp[i][j]!=-1)
        return dp[i][j];
     if(ispalindrom(i,j,s,dp))
     {
        if(j-i+1>maxi)
        {
            ans=s.substr(i,j-i+1);
            maxi=j-i+1;
        }
        return dp[i][j]=1;
     }
    

    int l1=func(i+1,j,s,ans,maxi,dp);
    int l2=func(i,j-1,s,ans,maxi,dp);
    return dp[i][j]=(l1||l2);

    }
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        int maxi=-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
       func(0,n-1,s,ans,maxi,dp);
       return ans;
    }
};