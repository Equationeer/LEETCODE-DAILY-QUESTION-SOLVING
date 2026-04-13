# 1848. Minimum Distance to the Target Element

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language Used:** C++  
**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

## Problem Summary

You are given:
- An integer array `nums`
- An integer `target`
- An integer `start`

Your task is to find an index `i` such that:
- nums[i] == target  
- The value `abs(i - start)` is minimized  

Return the minimum possible distance.

---

## Key Observation

- There may be multiple occurrences of `target`
- We need the one **closest to index `start`**
- Simply compute distance for each occurrence and take the minimum

---

## Approach

1. Initialize a variable `ans` with a large value
2. Traverse the array:
   - If `nums[i] == target`:
     - Compute distance = abs(i - start)
     - Update `ans` with minimum value
3. Return `ans`

---

## Formula Used

distance = |i - start|

---

## Complexity Analysis

- **Time Complexity:** O(n)  
  - Single traversal of array  

- **Space Complexity:** O(1)  
  - No extra space used  

---

## C++ Implementation

```cpp
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                ans = min(ans, abs(i - start));
            }
        }

        return ans;
    }
};
