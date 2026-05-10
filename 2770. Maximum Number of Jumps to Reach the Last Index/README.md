# 2770. Maximum Number of Jumps to Reach the Last Index

## Problem Link
🔗 https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/

## Difficulty
Medium

## Approach
We use Dynamic Programming.

Let `dp[i]` represent the maximum number of jumps needed to reach index `i`.

- Initialize all values with `-1` because initially all indices are unreachable.
- Set `dp[0] = 0` since we start from index `0`.
- For every index `i`, try jumping to every index `j > i`.
- If:
```cpp
-target <= nums[j] - nums[i] <= target
```
then update:
```cpp
dp[j] = max(dp[j], dp[i] + 1)
```

Finally, return `dp[n-1]`.

---

## Algorithm
1. Initialize DP array with `-1`
2. Set `dp[0] = 0`
3. Traverse all pairs `(i, j)` where `j > i`
4. Check if jump condition is valid
5. Update maximum jumps for `j`
6. Return last index value

---

## Complexity Analysis

### Time Complexity
```cpp
O(n^2)
```

### Space Complexity
```cpp
O(n)
```

---

## C++ Solution

```cpp
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> dp(n, -1);
        dp[0] = 0;

        for(int i = 0; i < n; i++) {
            if(dp[i] == -1) continue;

            for(int j = i + 1; j < n; j++) {
                long long diff = 1LL * nums[j] - nums[i];

                if(-target <= diff && diff <= target) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n - 1];
    }
};
```

---

## Example

### Input
```cpp
nums = [1,3,6,4,1,2]
target = 2
```

### Output
```cpp
3
```

### Explanation
Possible jumps:
```cpp
0 -> 1 -> 3 -> 5
```

Maximum jumps = `3`

---

## Key Observations
- This is a classic DP reachability problem.
- Each state depends on all previous reachable states.
- Using `-1` helps identify unreachable indices.

---

## Tags
`Dynamic Programming` `Array`
