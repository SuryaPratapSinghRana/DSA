class Solution {
public:
    vector<int> findnse(vector<int> arr)
    {
        int n=arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
             st.pop();
            if(st.empty())
            {
                nse[i]=n;
            }
            else
            {
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> findpsee(vector<int> arr)
    {
        int n=arr.size();
        vector<int>psee(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])
             st.pop();
            if(st.empty())
            {
                psee[i]=-1;
            }
            else
            {
                psee[i]=st.top();
            }
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);
        long long totalsum=0;
        int mod=(int)(1e9+7);
        for(int i=0;i<arr.size();i++)
        {
            int rightcontrib=nse[i]-i;
            int leftcontrib=i-psee[i];
            totalsum=(totalsum+(rightcontrib*leftcontrib*1LL*arr[i])%mod)%mod;
        }
        return totalsum;
    }
};