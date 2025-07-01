class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n=matrix.size();
            int row=0,colm=matrix[0].size()-1;
            while(row<n && colm>=0)
            {
                if(target==matrix[row][colm])
                  return true;
                if(target<matrix[row][colm])
                {
                    colm--;
                }
                else
                {
                    row++;
                }
            }
            return false;
        }
    };