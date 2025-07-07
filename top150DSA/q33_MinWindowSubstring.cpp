class Solution {
    public:
        string minWindow(string s, string t) {
            int minlen=INT_MAX,l=0,r=0,sindex=-1,count=0;
            vector<int>mp(256,0);
            for(int i=0;i<t.length();i++)
            {
                mp[t[i]]++;
            }
            while(r<s.length())
            {
                if(mp[s[r]]>0)
                count++;
                mp[s[r]]--;
                while(count==t.length())
                {
                    if(r-l+1<minlen)
                    {
                        minlen=r-l+1;
                        sindex=l;
                    }
                    mp[s[l]]++;
                    if(mp[s[l]]>0)count--;
                    l++;
                }
                r++;
            }
    
            return sindex==-1?"":s.substr(sindex,minlen);
        }
    };