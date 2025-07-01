Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            stack<int>st;
            int maxarea=0;
            for(int i=0;i<heights.size();i++)
             {
                while(!st.empty() && heights[st.top()]>=heights[i])
                {
                    int element=heights[st.top()];
                    st.pop();
                    int nse=i;
                    int pse=st.empty()?-1:st.top();
                    maxarea=max(maxarea,(nse-pse-1)*element);
                }
                st.push(i);
             }
             while(!st.empty())
                {
                    int element=heights[st.top()];
                    st.pop();
                    int nse=heights.size();
                    int pse=st.empty()?-1:st.top();
                    maxarea=max(maxarea,(nse-pse-1)*element);
                }
    
             return maxarea;
        }
        int maximalRectangle(vector<vector<char>>& matrix) {
            int n=matrix.size();  //no. of row
            int m=matrix[0].size(); // no of colm
            int maxarea=0;
            vector<vector<int>>prefsum(n,vector<int>(m));
            for(int j=0;j<m;j++)
            {    int sum=0;
                for(int i=0;i<n;i++)
                {
                    sum+=matrix[i][j]-'0';
                    if((matrix[i][j]-'0')==0)
                      sum=0;
                    prefsum[i][j]=sum;
                }
            }
            // calling largestRectangleInHist funcion for every row
            for(int i=0;i<n;i++)
            {
                maxarea=max(maxarea,largestRectangleArea(prefsum[i]));
            }
            return maxarea;
        }
    };