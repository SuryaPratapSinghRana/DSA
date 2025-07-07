// nikhil lohia approach

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int finalindex=nums.size()-1;
        // hum piche se chalenge aur check karenge ki kya us index se finalindex tak pahucha ja raha h ki nhi agar ha to use hi finalidnex bna denge phir uske liye check karenge kya ustak pahucha ja raha h
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>=finalindex-i)
            {
                finalindex=i;
            }
        }
        if(finalindex==0)
          return true;
        else
         return false;
    }
};

// striver appraoch
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindices = 0;        // The farthest index we can currently reach
        int n = nums.size();       

        for(int i = 0; i < n; i++) {
            // If current index is beyond the farthest reachable index, we cannot proceed
            if(i > maxindices) return false;

            // Update the farthest reachable index from the current position
            maxindices = max(maxindices, i + nums[i]);
        }

        // If we completed the loop, we can reach the last index
        return true;
    }
};