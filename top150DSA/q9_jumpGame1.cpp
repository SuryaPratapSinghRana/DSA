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