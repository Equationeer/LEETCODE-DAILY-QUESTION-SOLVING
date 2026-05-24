# 1340. Jump Game V

## Problem Statement
Given an integer array `arr` and an integer `d`.

From index `i`, you can jump:

- `i + x` where:
  - `i + x < arr.length`
  - `0 < x <= d`
- `i - x` where:
  - `i - x >= 0`
  - `0 < x <= d`

You can jump from index `i` to index `j` only if:

- `arr[i] > arr[j]`
- and `arr[i] > arr[k]` for all indices `k` between `i` and `j`.

Return the maximum number of indices you can visit.

---

## Example

### Example 1
Input:
```txt
arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
```

Output:
```txt
4
```

Explanation:
```txt
One optimal path:
10 -> 8 -> 6 -> 7
```

---

## Approach

We use **DFS + Memoization (DP)**.

### Key Idea
For every index:

- Try jumping left up to distance `d`
- Try jumping right up to distance `d`
- Stop when we encounter an element greater than or equal to current element
- Store already computed results in `dp`

---

## Algorithm

1. Create a DFS function:
   - Returns maximum jumps starting from index `i`
2. Use memoization:
   - If already computed, return stored value
3. Explore:
   - Right side
   - Left side
4. Update maximum possible jumps
5. Return the best answer among all starting indices

---

## Complexity Analysis

### Time Complexity
```txt
O(n * d)
```

### Space Complexity
```txt
O(n)
```

---

## C++ Solution

```cpp
class Solution {
public:
    int dfs(vector<int>& a, vector<int>& dp, int i, int d) {

        if(dp[i] != 0)
            return dp[i];

        int mx = 1;
        int n = a.size();

        // Right side
        for(int j = 1; j <= d && i + j < n; j++) {

            if(a[i] > a[i + j]) {
                mx = max(mx, 1 + dfs(a, dp, i + j, d));
            }
            else {
                break;
            }
        }

        // Left side
        for(int j = 1; j <= d && i - j >= 0; j++) {

            if(a[i] > a[i - j]) {
                mx = max(mx, 1 + dfs(a, dp, i - j, d));
            }
            else {
                break;
            }
        }

        return dp[i] = mx;
    }

    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, 0);

        int ans = 0;

        for(int i = 0; i < n; i++) {
            ans = max(ans, dfs(arr, dp, i, d));
        }

        return ans;
    }
};
```

---

## Topics
- Dynamic Programming
- DFS
- Memoization
- Arrays

---

## Learnings
- How to optimize DFS using memoization
- Breaking traversal when condition fails
- DP on graphs/arrays
- Recursive state caching

---
