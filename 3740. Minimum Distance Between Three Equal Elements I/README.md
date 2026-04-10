# 3740. Minimum Distance Between Three Equal Elements I

Platform: LeetCode  
Difficulty: Easy  
Language Used: C++  
Time Complexity: O(n)  
Space Complexity: O(n)

---

## Problem Summary

You are given an integer array `nums`.

A tuple `(i, j, k)` is called **good** if:
- All indices are distinct
- nums[i] == nums[j] == nums[k]

The **distance** of a tuple is defined as:

abs(i - j) + abs(j - k) + abs(k - i)

Return the **minimum distance** among all good tuples.  
If no such tuple exists, return `-1`.

---

## Key Observation

For indices `i < j < k`, the distance simplifies to:

distance = (j - i) + (k - j) + (k - i)  
distance = 2 * (k - i)

So, we only need to minimize:

2 * (last_index - first_index)

---

## Approach

1. Store indices of each number using a map:
   - key → number
   - value → list of indices

2. For each number:
   - If it appears at least 3 times:
     - Check every group of 3 consecutive indices
     - Compute:
       distance = 2 * (indices[i+2] - indices[i])

3. Track the minimum distance

4. If no valid triplet exists:
   - Return -1

---

## Complexity Analysis

Time Complexity: O(n)  
- Single pass to store indices  
- Linear traversal of stored indices  

Space Complexity: O(n)  
- For storing indices in map  

---

## C++ Implementation

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        for (auto& entry : pos) {
            vector<int>& indices = entry.second;
            
            if (indices.size() < 3) 
                continue;
            
            for (int i = 0; i + 2 < indices.size(); i++) {
                int distance = 2 * (indices[i + 2] - indices[i]);
                ans = min(ans, distance);
            }
        }
        
        if (ans == INT_MAX) 
            return -1;

        return ans;
    }
};
