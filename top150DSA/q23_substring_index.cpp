// by kmp alogrithm

class Solution {
public:
    vector<int> lpsarr(string s)
    {
        int n=s.length();
        int i=1,j=0;
        vector<int>lps(n,0);
        while(i<n)
        {
            if(s[i]==s[j])
            {
                j++;
                lps[i]=j;
                i++;
            }
            else
            {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        return lps;
        
    }
    int strStr(string haystack, string needle) {
     int n=haystack.length();
     int m=needle.length();
     vector<int>lps=lpsarr(needle);
     int i=0;
     int  j=0;
     while((n-i)>=(m-j))
     {
        if(haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        if(j==m)
          return i-m;
        else if(i<n && needle[j]!=haystack[i])
        {
           if(j!=0)
           {
             j=lps[j-1];
           }
           else
           {
            i++;
           }
        }
     }
     return -1;
    }
};