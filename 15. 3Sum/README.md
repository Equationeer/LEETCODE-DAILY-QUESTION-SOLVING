# 15. 3Sum

Platform: LeetCode  
Difficulty: Medium  
Language Used: C++  
Time Complexity: O(n^2)  
Space Complexity: O(1) (excluding output)

---

## Problem Summary

Given an integer array `nums`, return all the unique triplets `[nums[i], nums[j], nums[k]]` such that:

- i ≠ j, i ≠ k, j ≠ k  
- nums[i] + nums[j] + nums[k] == 0  

The solution must not contain duplicate triplets.

---

## Key Observation

- Sorting helps:
  - Avoid duplicates
  - Apply two-pointer technique

- Fix one element and find the other two using two pointers

---

## Approach

1. Sort the array
2. Iterate through each index `i`:
   - Skip duplicates
3. Use two pointers:
   - `left = i + 1`
   - `right = n - 1`

4. While `left < right`:
   - Compute sum:
     sum = nums[i] + nums[left] + nums[right]

   - If sum == 0:
     - Store triplet
     - Move both pointers
     - Skip duplicates

   - If sum < 0:
     - Move `left++`

   - If sum > 0:
     - Move `right--`

---

## Complexity Analysis

Time Complexity: O(n^2)  
- Outer loop runs n times  
- Two-pointer scan takes O(n)  

Space Complexity: O(1)  
- No extra space used (excluding result)

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum < 0) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        
        return result;
    }
};
