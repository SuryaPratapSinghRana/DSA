Given an array of N integers and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

Examples :
Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
Output:  [6, 1]


class Solution{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        vector<int> result;
        stack<int> monotonicStackDescending;
        stack<int> monotonicStackAscending;
        unordered_map<int, int> indexToGreaterMap;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!monotonicStackDescending.empty() && monotonicStackDescending.top() <= arr[i])
            {
                monotonicStackAscending.push(monotonicStackDescending.top());
                monotonicStackDescending.pop();
            }
            indexToGreaterMap[i] = monotonicStackDescending.size();
            monotonicStackDescending.push(arr[i]);
            while (!monotonicStackAscending.empty())
            {
                monotonicStackDescending.push(monotonicStackAscending.top());
                monotonicStackAscending.pop();
            }
        }
        for (int i = 0; i < indices.size(); i++)
        {
            int index = indices[i];
            result.push_back(indexToGreaterMap[index]);
        }
        return result; 
    }
};