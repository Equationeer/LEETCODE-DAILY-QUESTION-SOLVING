# 2784. Check if Array is Good

## Problem Statement
You are given an integer array `nums`.

An array is considered **good** if it is a permutation of:

```cpp
base[n] = [1, 2, 3, ..., n-1, n, n]
```

This means:
- Numbers from `1` to `n-1` appear exactly once.
- Number `n` appears exactly twice.

Return `true` if the given array is good, otherwise return `false`.

---

## Example 1

Input:
```cpp
nums = [2,1,3]
```

Output:
```cpp
false
```

Explanation:
For `n = 3`, expected array is:
```cpp
[1,2,3,3]
```

But input size is only 3, so it cannot be good.

---

## Example 2

Input:
```cpp
nums = [1,3,3,2]
```

Output:
```cpp
true
```

Explanation:
After sorting:
```cpp
[1,2,3,3]
```

Matches the required pattern.

---

## Approach

### Observation
If the array is good:
- After sorting:
```cpp
[1,2,3,...,n-1,n]
```

where:
- first `n-1` elements should be:
```cpp
1,2,3,...,n-1
```

- last element should also equal:
```cpp
n-1
```

because array size is `n`.

---

## Algorithm
1. Sort the array.
2. Check whether:
```cpp
nums[i] == i + 1
```

for all indices except the last one.

3. Verify:
```cpp
nums[n-1] == n-1
```

If all conditions satisfy → return `true`.

---

## Time Complexity
```cpp
O(n log n)
```

Sorting dominates the complexity.

---

## Space Complexity
```cpp
O(1)
```

Ignoring sorting space.

---

## C++ Solution

```cpp
class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] != i + 1)
                return false;
        }

        return nums[n - 1] == n - 1;
    }
};
```

---

## Key Concepts Used
- Sorting
- Array Validation
- Greedy Checking

---

## LeetCode Link
🔗 https://leetcode.com/problems/check-if-array-is-good/
