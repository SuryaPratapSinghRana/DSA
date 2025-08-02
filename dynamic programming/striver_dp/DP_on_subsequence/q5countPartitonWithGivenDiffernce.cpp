#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;

int func(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || arr[0] == target) return 1;
        return 0;
    }

    if (dp[ind][target] != -1) return dp[ind][target];

    int not_take = func(ind - 1, target, arr, dp);
    int take = 0;
    if (arr[ind] <= target) {
        take = func(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = (not_take + take)%mod;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int totalsum = accumulate(arr.begin(), arr.end(), 0);

    if (totalsum - d < 0 || (totalsum - d) % 2 != 0) return 0;

    int target = (totalsum - d) / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return func(n - 1, target, arr, dp);
}
