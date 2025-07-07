class Solution {
public:
    int jump(vector<int>& nums) {
        int totaljumps=0;
        int finalindex=nums.size()-1;
        int lastjumpindex=0;
        int coverage=0;
        if(nums.size()==1)
          return 0;
        for(int i=0;i<nums.size();i++)
        {
            coverage=max(coverage,i+nums[i]);
            // ye window traverse karenge jitni jgah kood sakta h
            if(i==lastjumpindex)
            {
                lastjumpindex=coverage;
                totaljumps++;
            
              if(coverage>=finalindex)
              {
                return totaljumps;
              }
            }
        }
      return totaljumps;
    }
};