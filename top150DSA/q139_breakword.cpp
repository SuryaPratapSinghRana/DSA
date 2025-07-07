Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

class Solution {
public:
    unordered_set<string> st;
    bool wordfindfunc(int index,string &s,vector<string>& wordDict,vector<int>&dp)
    {
        if(index==s.size())
          return true;
        if(dp[index]!=-1)
           return dp[index];
           string word="";
        for(int j=index;j<s.size();j++)  // j ek trah se length todega j=index  --> len=1  ,j++ -->len =2 generaly ye len ka todraha h substring j-index+1 ka 
        {
            word+=s[j];
            if(st.find(word)!=st.end() && wordfindfunc(j+1,s,wordDict,dp))
            {
                return dp[index]=true;
            }

        }
           return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        for(auto i:wordDict)
        {
            st.insert(i);
        }
        return wordfindfunc(0,s,wordDict,dp);
    }
};

// tabulation

bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size()+1,0);
        for(auto i:wordDict)
        {
            st.insert(i);
        }
          int n=s.size();
           dp[n]=true;
        for(int index=n-1;index>=0;index--)
        {
            string word="";
            for(int j=index;j<n;j++)
            {
                 word+=s[j];
            if(st.find(word)!=st.end() && dp[j+1])
            {
                dp[index]=true;
            }
            }
        }
        return dp[0];

    }