class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>> answer;
        for(int row=1;row<=n;row++)
        {
            vector<int>temp;
             int ans=1;
             temp.push_back(ans);
             for(int col=1;col<row;col++)
             {
                ans=ans*(row-col);
                ans=ans/col;
                temp.push_back(ans);
             }
             answer.push_back(temp);
        }
        return answer;
    }
};