# 1. Two Sum (Optimal - Hash Map)

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language Used:** C++  
**Approach:** Hash Map (Unordered Map)  
**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

## Problem Summary

Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that:

nums[i] + nums[j] = target  

- Each input has exactly **one solution**
- You cannot use the same element twice
- Return the answer in any order

---

## Key Idea

Instead of checking all pairs, we use a **hash map** to store previously seen elements.

👉 For every element `x`, we check if:

target - x  

already exists in the map.

---

## Approach

1. Initialize an empty hash map `mp`
   - Key → number  
   - Value → index  

2. Traverse the array:
   - Compute `complement = target - nums[i]`
   - If complement exists in map:
     - Return `{index_of_complement, i}`
   - Else:
     - Store current element in map

---

## Algorithm

- Loop through array:
  - Check if `(target - nums[i])` exists in map
  - If yes → return indices
  - Else → insert nums[i] into map

---

## Complexity Analysis

- **Time Complexity:**  
  O(n)  
  (Single pass with O(1) average lookup)

- **Space Complexity:**  
  O(n)  
  (Hash map storage)

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            
            if(mp.find(complement) != mp.end()){
                return {mp[complement], i};
            }
            
            mp[nums[i]] = i;
        }
        
        return {};
    }
};
