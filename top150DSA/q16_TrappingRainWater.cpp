//Approach 1 space O(n) t.c O(n)
class Solution {
public:
    int trap(vector<int>& height) {
      int n=height.size();
      vector<int>left(n),right(n);
      int maxleft=-1;
      for(int i=0;i<n;i++){
         if(maxleft<height[i]){
             maxleft=height[i];
             left[i]=height[i];
         }
         else
         {
             left[i]=maxleft;
         }
      }
      int maxright=-1;
      for(int i=n-1;i>=0;i--){
         if(maxright<height[i]){
             maxright=height[i];
             right[i]=height[i];
         }
         else
         {
             right[i]=maxright;
         }
      }
      int sum=0;
      for(int i=0;i<n;i++){
          sum=sum+min(left[i],right[i])-height[i];
      }
      return sum;
    }
};

//Approach 2 space O(1) t.c O(n)

