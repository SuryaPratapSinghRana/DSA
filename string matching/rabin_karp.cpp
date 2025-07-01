class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here
            int m=pattern.length();
            int n=text.length();
            int h=1;
            int p=0; // hash value of pattern string
            int t=0; // hash value of text string
            int d=256;
            int i,j;
            int q=11;// prime number
            //  value of h=pow(d,m-1)
            for(i=0;i<m-1;i++)
            {
                h=(h*d)%q;
            }
            vector<int> ans;
            // calculate hash value
            for(i=0;i<m;i++)
            {
                p=(p*d+pattern[i])%q;
                t=(t*d+text[i])%q;
            }
            
            for(i=0;i<=n-m;i++)
            {
                if(p==t){
                    for(j=0;j<m;j++)
                    {
                        if(pattern[j]!=text[i+j])
                          break;
                    }
                    if(j==m)
                    {
                        ans.push_back(i+1);
                    }
                }
                if(i<n-m)
                {
                    t=(d*(t-text[i]*h)+text[i+m])%q;
                    if(t<0){
                        t=t+q;
                    }
                }
            }
            
            return ans;
        }
     
};