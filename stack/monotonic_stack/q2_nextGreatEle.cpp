
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        stack<int>st;
        int n=nums.size();
        for(int i=2*n-1;i>=0;i--)
        {
            int ind=i%n;
            while(!st.empty() && st.top()<=nums[ind])
            {
                st.pop();
            }
            if(i<n)
            {
                if(st.empty())
                {
                    ans[i]=-1;

                }
                else
                {
                    ans[i]=st.top();
                }
            }
            st.push(nums[ind]);

        }
        return ans;
    }
};