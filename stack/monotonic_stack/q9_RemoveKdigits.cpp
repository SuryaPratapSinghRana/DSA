Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.length();
        if(k>=n)
          return "0";
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && k>0 && (st.top()-'0')>(num[i]-'0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }

        if(st.empty())
        {
            return "0";
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        while(ans.size()!=0 && ans.back()=='0')
           ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans.empty())
           return "0";
        else
           return ans;
    }
};