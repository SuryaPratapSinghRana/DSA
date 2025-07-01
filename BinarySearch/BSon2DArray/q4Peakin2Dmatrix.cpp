class Solution {
    public:
       int maxELemColm(vector<vector<int>>&mat,int n,int colm)
       {
        int maxi=INT_MIN;
        int RowIndex=-1;
        for(int row=0;row<n;row++)
        {
          if(maxi<mat[row][colm])
           { maxi=mat[row][colm];
            RowIndex=row;
           }
        }
        return RowIndex;
       }
        vector<int> findPeakGrid(vector<vector<int>>& mat) {
            int n= mat.size();
            int m=mat[0].size();
            int low=0,high=m-1;
            while(low<=high)
            {   
                int mid=(low+high)/2;
                int row=maxELemColm(mat,n,mid); // ye max element ke row nikalega in mid colm mein
                int elem=mat[row][mid];
                int left=mid-1>0?mat[row][mid-1]:-1;
                int right=mid+1<m?mat[row][mid+1]:-1;
                if(elem>left && elem>right)
                {
                    return {row,mid};
                }
                else if(elem<left)
                {
                     high=mid-1;
                }
                else
                {
                   low=mid+1;
                }
            }
            return {-1,-1};
        }
    };