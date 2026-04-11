# 3741. Minimum Distance Between Three Equal Elements II

**Platform:** LeetCode  
**Difficulty:** Medium  
**Language Used:** C++  
**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

## Problem Summary

You are given an integer array `nums`.

A tuple `(i, j, k)` is called **good** if:
- All indices are distinct  
- nums[i] == nums[j] == nums[k]  

The **distance** of a good tuple is:

abs(i - j) + abs(j - k) + abs(k - i)

Return the **minimum possible distance** among all good tuples.  
If no such tuple exists, return `-1`.

---

## Key Observation

For indices `i < j < k`, the distance simplifies to:

distance = (j - i) + (k - j) + (k - i)  
distance = 2 * (k - i)

This means:
- Only the **first and third indices matter**
- We just need to minimize `(k - i)`

---

## Approach

1. Store indices of each number using a map:
   - key → number  
   - value → list of indices  

2. Traverse each group:
   - If a number appears at least 3 times:
     - Iterate through consecutive triplets
     - Compute distance:
       abs(i - j) + abs(j - k) + abs(k - i)

3. Keep track of the minimum distance

4. If no valid triplet exists:
   - Return -1

---

## Complexity Analysis

- **Time Complexity:** O(n)  
  - One pass to build the map  
  - One pass over grouped indices  

- **Space Complexity:** O(n)  
  - For storing indices  

---

## C++ Implementation

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 1e9;

        for (auto it : mp) {
            vector<int> v = it.second;

            if (v.size() >= 3) {
                for (int i = 0; i <= v.size() - 3; i++) {
                    int dist = abs(v[i] - v[i + 1]) 
                             + abs(v[i] - v[i + 2]) 
                             + abs(v[i + 1] - v[i + 2]);

                    ans = min(ans, dist);
                }
            }
        }

        if (ans == 1e9) return -1;

        return ans;
    }
};
