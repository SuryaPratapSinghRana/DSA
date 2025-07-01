Example 1:

Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4


class Solution {
public:
    vector<int>findnge(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]<=arr[i])
               st.pop();
            if(st.empty())
            {
               nge[i]=n;
            }
            else
            {
                nge[i]=st.top();
            }
            st.push(i);
        }
        return nge;
    }
    vector<int>findpgee(vector<int>&arr)
    {
        int n=arr.size();
        vector<int>pgee(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
               st.pop();
            if(st.empty())
            {
               pgee[i]=-1;
            }
            else
            {
                pgee[i]=st.top();
            }
            st.push(i);
        }
        return pgee;
    }
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
    long long subArrayRanges(vector<int>& arr) {
        vector<int>nge=findnge(arr);
        vector<int>pgee=findpgee(arr);
         vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);
        long long sumformax=0;
        long long sumformin=0;
        // sum for min in subarray
        for(int i=0;i<arr.size();i++)
        {
            int rightcontrib=nse[i]-i;
            int leftcontrib=i-psee[i];
            sumformin=sumformin+(rightcontrib*leftcontrib*1LL*arr[i]);
        }
       // sum for max in subarray
       for(int i=0;i<arr.size();i++)
        {
            int rightcontrib=nge[i]-i;
            int leftcontrib=i-pgee[i];
            sumformax=sumformax+(rightcontrib*leftcontrib*1LL*arr[i]);
        }
       return sumformax-sumformin;
    }
};