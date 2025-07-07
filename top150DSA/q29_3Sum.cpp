
// approach:1 by set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    int n=nums.size();
    set<vector<int>> st;
    for(int i = 0; i < n; i++) {
        set<int> hashset;
        for(int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);
            
            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            
            hashset.insert(nums[j]);
        }
    }
    
    vector<vector<int>> result(st.begin(), st.end());
    return result;
    }
};

// approach:2 by two pointer by sorting
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
    int n=nums.size();
    for(int k=0;k<n;k++)
    {
      if(k>0 && nums[k]==nums[k-1])continue;    // triplet duplicacy
        int i=k+1;
        int j=n-1;
        while(i<j)
        {
            if(nums[k]+nums[i]+nums[j]<0)
            {
                i++;
            }
            else if(nums[k]+nums[i]+nums[j]>0)
            {
                j--;
            }
            else
            {
               vector<int>temp={nums[k],nums[i],nums[j]};
               ans.push_back(temp);
               i++;
               j--;
               while(i<j && nums[i]==nums[i-1])   // to avoid duplicate triplet
               {
                i++;
               }
                while(i<j && nums[j]==nums[j+1])
               {
                j--;
               }
            }
        }
    }
    return ans;
    }
};