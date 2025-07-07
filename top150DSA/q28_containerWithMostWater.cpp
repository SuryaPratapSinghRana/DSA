class Solution {
public:
    int maxArea(vector<int>& height) {
      int i=0,j=height.size()-1;
      int maxwater=0;
      while(i<j)
      {
        int minheight=min(height[i],height[j]);
        int water=minheight*(j-i);
        maxwater=max(water,maxwater);
        if(height[j]<height[i])
         {
            j--;
         }
        else
        {
            i++;
        }
      }
      return maxwater;
    }
};