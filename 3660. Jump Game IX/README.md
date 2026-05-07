# 3660. Jump Game IX

## Problem

You are given an integer array `nums`.

From any index `i`, you can jump according to the following rules:

- Jump to index `j > i` only if:
```cpp
nums[j] < nums[i]
```

- Jump to index `j < i` only if:
```cpp
nums[j] > nums[i]
```

For every index `i`, return the maximum value reachable after performing any sequence of valid jumps.

---

## Example 1

### Input
```cpp
nums = [2,1,3]
```

### Output
```cpp
[2,2,3]
```

### Explanation

- From index `0` → cannot reach larger value
- From index `1` → jump to `0`
- From index `2` → already maximum

Result:
```cpp
[2,2,3]
```

---

## Example 2

### Input
```cpp
nums = [2,3,1]
```

### Output
```cpp
[3,3,3]
```

### Explanation

- `0 → 2 → 1`
- `1` already maximum
- `2 → 1`

All indices can reach `3`.

---

# Approach

## Key Observation

If there exists:

```cpp
pre[i] > suf[i + 1]
```

then:
- there exists a smaller element on the right
- which allows forward jump
- and eventually reaching the larger prefix maximum

Thus all reachable values merge together.

---

# Prefix & Suffix Arrays

## Prefix Maximum

```cpp
pre[i] = maximum value from [0...i]
```

## Suffix Minimum

```cpp
suf[i] = minimum value from [i...n-1]
```

---

# Logic

For each index:

- If:
```cpp
pre[i] > suf[i + 1]
```

then index `i` can connect with future indices.

So:
```cpp
res[i] = res[i + 1]
```

Otherwise:
```cpp
res[i] = pre[i]
```

---

# C++ Solution

```cpp
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n), suf(n), res(n);

        pre[0] = nums[0];

        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], nums[i]);
        }

        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = min(suf[i + 1], nums[i]);
        }

        res[n - 1] = pre[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            if (pre[i] > suf[i + 1]) {
                res[i] = res[i + 1];
            }
            else {
                res[i] = pre[i];
            }
        }

        return res;
    }
};
```

---

# Complexity Analysis

## Time Complexity
```cpp
O(n)
```

## Space Complexity
```cpp
O(n)
```

---

# Key Insight

If a smaller element exists on the right:
- we can jump forward
- then possibly jump backward to larger values
- creating a connected reachable region

Prefix maximum + suffix minimum efficiently captures this behavior.

---

# Tags

- Array
- Greedy
- Prefix Maximum
- Suffix Minimum
- Dynamic Reachability

---

# LeetCode

Problem Link: https://leetcode.com/problems/jump-game-ix/

---

# Status

✅ Solved  
⚡ Optimal O(n) solution used
