Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    /*// Approach 1 
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for(int i=0;i<n1;i++){
            bool found = false;
            int index = -1;
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j]){
                    index = j;
                    break;
                }
            }
            if( index<n2-1){
                for(int k=index+1;k<n2;k++){
                    if(nums2[k]>nums1[i]) {
                        ans.push_back(nums2[k]);
                        found = true;
                        break;
                    }
                }
                if(!found) ans.push_back(-1);
                
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
        */
        //Approach 2
        stack<int>st;
        map<int,int>mpp;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty()&& nums2[i]>st.top()) st.pop();
            if(st.empty()) mpp[nums2[i]] = -1;
            else{
                mpp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }vector<int>ans;
        for(int i =0;i<nums1.size();i++){
            if(mpp.find(nums1[i])!=mpp.end()) 
                ans.push_back(mpp[nums1[i]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};