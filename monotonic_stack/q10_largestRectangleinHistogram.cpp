Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

class Solution {
    public:
    vector<int> findnse(vector<int> arr)
        {
            int n=arr.size();
            vector<int>nse(n);
            stack<int>st;
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                 st.pop();
                if(st.empty())
                {
                    nse[i]=n;
                }
                else
                {
                    nse[i]=st.top();
                }
                st.push(i);
            }
            return nse;
        }
        vector<int> findpse(vector<int> arr)
        {
            int n=arr.size();
            vector<int>pse(n);
            stack<int>st;
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                 st.pop();
                if(st.empty())
                {
                    pse[i]=-1;
                }
                else
                {
                    pse[i]=st.top();
                }
                st.push(i);
            }
            return pse;
        }
        int largestRectangleArea(vector<int>& heights) {
            /* Apprach 1
            vector<int>nse=findnse(heights);
            vector<int>pse=findpse(heights);
            int maxarea=0;
            for(int i=0;i<heights.size();i++)
            {
                maxarea=max(maxarea,heights[i]*(nse[i]-pse[i]-1));
            }
            return maxarea;
            */
    
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
    };