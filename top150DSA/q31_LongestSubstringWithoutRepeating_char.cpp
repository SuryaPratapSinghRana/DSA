class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>um(256,-1);
        int left=0,right=0,maxlen=0;
      while(right<s.size())
        {
            if(um[s[right]]!=-1)
            {
               if(um[s[right]]>=left)
               {
                 left=um[s[right]]+1;
               }
            }
            int len=right-left+1;
            maxlen=max(maxlen,len);
            um[s[right]]=right;
            right++;
        }
        return maxlen;
    }
        
};