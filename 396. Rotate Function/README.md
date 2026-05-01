# 396. Rotate Function

## Problem
You are given an integer array `nums` of length `n`.

Assume `arr_k` is obtained by rotating `nums` clockwise by `k` positions.

Define the rotation function:

F(k) = 0 × arr_k[0] + 1 × arr_k[1] + ... + (n-1) × arr_k[n-1]

Return the maximum value among all possible rotations.

---

## Example

### Input
```cpp
nums = [4,3,2,6]
```

### Output
```cpp
26
```

### Explanation
```
F(0) = 25
F(1) = 16
F(2) = 23
F(3) = 26
```

Maximum = **26**

---

## Approach

### Brute Force
Compute every rotation separately.

- Time Complexity: **O(n²)**
- Space Complexity: **O(1)**

This is inefficient for large constraints.

---

## Optimized Mathematical Relation

Instead of recalculating each rotation:

F(k) = F(k-1) + sum(nums) - n × nums[n-k]

This allows computing each next rotation in constant time.

### Steps
1. Compute total sum of array
2. Compute initial rotation value F(0)
3. Use recurrence relation for all rotations
4. Track maximum

---

## C++ Solution

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        
        long sum = 0;
        long F = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += (long)i * nums[i];
        }
        
        long result = F;
        
        for(int k = 1; k < n; k++) {
            F = F + sum - (long)n * nums[n - k];
            result = max(result, F);
        }
        
        return (int)result;
    }
};
```

---

## Complexity Analysis

### Time Complexity
**O(n)**

### Space Complexity
**O(1)**

---

## Key Insight
The recurrence relation avoids recomputing the weighted sum for every rotation.

This converts an **O(n²)** problem into **O(n)**.

---

## Tags
- Array
- Math
- Dynamic Programming
- Prefix Sum

---

## LeetCode
Problem Link: https://leetcode.com/problems/rotate-function/

---

## Status
Solved

---
⭐ Optimized using mathematical recurrence relation
