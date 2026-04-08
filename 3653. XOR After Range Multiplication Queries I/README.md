# 3653. XOR After Range Multiplication Queries I

Platform: LeetCode  
Difficulty: Medium  
Language Used: C++  
Time Complexity: O(q * n)  
Space Complexity: O(1)

---

## Problem Summary

You are given:
- An integer array `nums` of size `n`
- A list of queries `queries`, where each query is defined as:

[li, ri, ki, vi]

For each query:
1. Start from index `li`
2. While `idx <= ri`:
   - Update:  
     nums[idx] = (nums[idx] * vi) % (10^9 + 7)
   - Move to next index:  
     idx += ki

After processing all queries, return the **bitwise XOR** of all elements in the final array.

---

## Key Observation

- Each query updates elements at positions:
  li, li + ki, li + 2*ki, ..., ≤ ri

- We must:
  - Apply all updates sequentially
  - Take modulo (10^9 + 7) after each multiplication

- Finally, compute XOR of all elements

---

## Approach

1. Iterate through each query:
   - Extract `l, r, k, v`
   - Loop from `idx = l` to `r` with step `k`
   - Update:
     nums[idx] = (nums[idx] * v) % MOD

2. After processing all queries:
   - Compute XOR of all elements in `nums`

---

## Formula Used

nums[idx] = (nums[idx] * v) % (10^9 + 7)

---

## Complexity Analysis

Time Complexity: O(q * n)  
- Each query may iterate over up to n/k elements  
- Worst case: k = 1 → O(n) per query  

Space Complexity: O(1)  
- No extra space used  

---

## C++ Implementation

```cpp
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans ^= nums[i];
        }
        
        return ans;
    }
};
