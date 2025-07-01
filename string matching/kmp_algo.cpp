#include<vector>
class Solution
{
    public:
      void lpsarr(vector<int> &lps,string pat)
       {
           int i=1,j=0;
           int m=pat.length();
           while(i<m){
               if(pat[i]==pat[j])
               {
                   j++;
                   lps[i]=j;
                   i++;
               }
               else
               {
                
                   if(j!=0){
                      j=lps[j-1];
                   }
                   else
                   {
                       lps[i]=0;
                       i++;
                   }
               }
           }
       }
        vector <int> search(string pat, string txt)
        {
            //code here
            int m=pat.length();
            vector<int> lps(m);
            lpsarr(lps,pat);
            int n=txt.length();
            int i=0,j=0;
            vector<int> ans;
            while((n-i)>=(m-j)){
                if(pat[j]==txt[i])
                {
                    i++;
                    j++;
                } 
                if(j==m){
                    ans.push_back(i-j+1);
                    j=lps[j-1];
                }
                else if(i<n && pat[j]!=txt[i])
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
            return ans;
        }
};