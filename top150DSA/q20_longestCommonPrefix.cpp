class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        sort(strs.begin(),strs.end());
        int l1=strs[0].length();
        int ln=strs[n-1].length();
        int i=0;
        while(i<l1 && i<ln)
        {
            if(strs[0][i]==strs[n-1][i])
            {
                ans=ans+(strs[0][i]);
                i++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};