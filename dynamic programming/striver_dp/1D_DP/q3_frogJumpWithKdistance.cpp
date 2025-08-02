#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int solve(int ind, int n, int k, vector<int> &height, vector<int> &dp) {
    if (ind == n - 1) return 0;  // Reached last stair

    if (dp[ind] != -1) return dp[ind];

    int minCost = INT_MAX;

    for (int j = 1; j <= k; j++) {
        if (ind + j < n) {
            int cost = abs(height[ind] - height[ind + j]) + solve(ind + j, n, k, height, dp);
            minCost = min(minCost, cost);
        }
    }

    return dp[ind] = minCost;
}

int frogJumpWithK(int n, int k, vector<int> &height) {
    vector<int> dp(n, -1);
    return solve(0, n, k, height, dp);
}
