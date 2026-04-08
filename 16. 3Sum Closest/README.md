# 16. 3Sum Closest

Platform: LeetCode  
Difficulty: Medium  
Language Used: C++  
Time Complexity: O(n^2)  
Space Complexity: O(1)

---

## Problem Summary

Given an integer array `nums` and an integer `target`, find three integers in `nums` such that the sum is **closest to the target**.

Return the sum of the three integers.

It is guaranteed that exactly one solution exists.

---

## Key Observation

- Sorting allows use of the **two-pointer technique**
- Instead of finding exact sum = target, we minimize:

|current_sum - target|

---

## Approach

1. Sort the array
2. Initialize:
   - `closestSum = nums[0] + nums[1] + nums[2]`

3. Iterate through each index `i`:
   - Use two pointers:
     - `l = i + 1`
     - `r = n - 1`

4. While `l < r`:
   - Compute:
     currSum = nums[i] + nums[l] + nums[r]

   - Update closest sum if:
     |currSum - target| < |closestSum - target|

   - If currSum < target:
     - Move left pointer (`l++`)
   - If currSum > target:
     - Move right pointer (`r--`)
   - If currSum == target:
     - Return target immediately

---

## Formula Used

closest difference = |current_sum - target|

---

## Complexity Analysis

Time Complexity: O(n^2)  
- Outer loop runs n times  
- Two-pointer traversal is O(n)  

Space Complexity: O(1)  
- No extra space used  

---

## C++ Implementation

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int currSum = nums[i] + nums[l] + nums[r];

                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }

                if (currSum < target) {
                    l++;
                } 
                else if (currSum > target) {
                    r--;
                } 
                else {
                    return target;
                }
            }
        }

        return closestSum;
    }
};
