# 18. 4Sum

Platform: LeetCode  
Difficulty: Medium  
Language Used: C++  
Time Complexity: O(n^3)  
Space Complexity: O(1) (excluding output)

---

## Problem Summary

Given an integer array `nums` and an integer `target`, return all the **unique quadruplets**:

[nums[a], nums[b], nums[c], nums[d]]

such that:
- All indices are distinct
- nums[a] + nums[b] + nums[c] + nums[d] == target

The solution set must not contain duplicate quadruplets.

---

## Key Observation

- Sorting helps:
  - Avoid duplicates
  - Apply two-pointer technique efficiently

- Reduce problem:
  - Fix two elements → convert to **2Sum problem**

---

## Approach

1. Sort the array

2. Fix first element `i`:
   - Skip duplicates

3. Fix second element `j`:
   - Skip duplicates

4. Use two pointers:
   - `l = j + 1`
   - `r = n - 1`

5. Compute:
   remaining target = target - nums[i] - nums[j]

6. While `l < r`:
   - If nums[l] + nums[r] == remaining target:
     - Store quadruplet
     - Move both pointers
     - Skip duplicates
   - If sum < target:
     - Move `l++`
   - If sum > target:
     - Move `r--`

---

## Important Detail

Use `long long` to avoid overflow:

newTarget = target - nums[i] - nums[j]

---

## Complexity Analysis

Time Complexity: O(n^3)  
- Two nested loops + two-pointer traversal  

Space Complexity: O(1)  
- No extra space used (excluding result)

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        if (n < 4) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long newTarget = (long long)target - nums[i] - nums[j];
                int l = j + 1, r = n - 1;

                while (l < r) {
                    long long sum = nums[l] + nums[r];

                    if (sum == newTarget) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;

                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                    else if (sum < newTarget) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};
