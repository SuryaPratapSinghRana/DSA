// 0 not given in array

#include <bits/stdc++.h>
using namespace std;

int find(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return 1;  // empty subset always possible
    if (ind == 0) {
        return arr[0] == target ? 1 : 0;
    }
    if (dp[ind][target] != -1) return dp[ind][target];

    int not_take = find(ind - 1, target, arr, dp);
    int take = 0;
    if (arr[ind] <= target) {
        take = find(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = not_take + take;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return find(n - 1, k, arr, dp);
}


// 0 given in array

#include <bits/stdc++.h>
using namespace std;

int find(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
     if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }
    if (dp[ind][target] != -1) return dp[ind][target];

    int not_take = find(ind - 1, target, arr, dp);
    int take = 0;
    if (arr[ind] <= target) {
        take = find(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = not_take + take;
}

int findWays(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
  return find(n - 1, k, arr, dp);

}
