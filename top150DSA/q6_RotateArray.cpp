class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int leng=nums.size();
        k=k%leng;
        vector<int>arr(leng);
        for(int i=0;i<k;i++){
            arr[i]=nums[leng-k+i];
        }
        for(int j=0;j<leng-k;j++){
            arr[k+j]=nums[j];
        }
        for(int i=0;i<leng;i++){
            nums[i]=arr[i];
        }
        
        
    }
};