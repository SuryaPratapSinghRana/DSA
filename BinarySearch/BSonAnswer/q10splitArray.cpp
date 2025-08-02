Given an integer array a of size n and an integer k. Split the array a into k non-empty subarrays such that the largest sum of any subarray is minimized. Return the minimized largest sum of the split.

Examples:
Input: a = [1, 2, 3, 4, 5], k = 3

Output:6

Explanation: There are many ways to split the array a[] into k consecutive subarrays. The best way to do this is to split the array a[] into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.

Input: a = [3,5,1], k = 3

Output: 5

Explanation: There is only one way to split the array a[] into 3 subarrays, i.e., [3], [5], and [1]. The largest sum among these subarrays is 5.

//code same as book allocation q9


🧠 First Principles Approach:
We want to minimize the largest sum among k parts.

This immediately suggests:

✅ Binary Search on Answer — because:

The minimum possible max sum is max(a)

The maximum possible max sum is sum(a)

The problem has a monotonic behavior:

If you can split using a max sum of X, you can also do it with X + 1

🧪 Step-by-Step
✅ Step 1: Define the binary search range
cpp
Copy
Edit
low = max(a)
high = sum(a)
✅ Step 2: Use binary search to find the minimum value of the largest subarray sum
We write a function isValid(mid) to check:

Can we split the array into at most k subarrays such that each subarray’s sum is ≤ mid?

✅ Step 3: Use greedy logic to implement isValid(mid)
Go through the array

Accumulate elements into a running sum

If sum exceeds mid, we cut here and start a new subarray

If total subarrays used ≤ k, then mid is valid

✅ Final C++ Code:
cpp
Copy
Edit
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(const vector<int>& a, int k, int mid) {
    int count = 1, currSum = 0;
    for (int num : a) {
        if (currSum + num <= mid) {
            currSum += num;
        } else {
            count++;
            currSum = num;
        }
    }
    return count <= k;
}

int minimizeLargestSum(vector<int>& a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = 0;
    for (int num : a) high += num;

    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isValid(a, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Driver code
int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    int k = 3;
    cout << minimizeLargestSum(a, k) << endl;  // Output: 6
}
🔁 Dry Run for [1,2,3,4,5], k = 3:
Try mid = 6:

Group 1: 1 + 2 + 3 = 6 ✅

Group 2: 4 ✅

Group 3: 5 ✅
→ ✅ 3 groups used → valid

Try mid = 5:

Group 1: 1 + 2 = 3

Group 2: 3 → ok

Group 3: 4 → ok

Group 4: 5 → ❌ too many groups

→ So final answer is 6

🧠 First Principles Recap:
What is fixed: Must split into k parts.

What must be minimized: The largest subarray sum.

What’s true always: Increasing the target makes it easier.

➤ That monotonicity → binary search

➤ Decision function → greedy check of how many groups you need