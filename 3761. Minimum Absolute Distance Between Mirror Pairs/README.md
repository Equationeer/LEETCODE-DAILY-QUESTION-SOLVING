# 🚀 3761. Minimum Absolute Distance Between Mirror Pairs

## 🧩 Problem Statement
You are given an integer array `nums`.

A **mirror pair** is defined as a pair of indices `(i, j)` such that:
- `0 <= i < j < nums.length`
- `reverse(nums[i]) == nums[j]`

Where `reverse(x)` means reversing the digits of `x` (leading zeros are removed).  
Example: `reverse(120) = 21`

## 🎯 Goal
Return the **minimum absolute distance** `|i - j|` among all mirror pairs.  
If no mirror pair exists, return `-1`.

## 🧪 Examples

Example 1:
Input: nums = [12,21,45,33,54]  
Output: 1  

Example 2:
Input: nums = [120,21]  
Output: 1  

Example 3:
Input: nums = [21,120]  
Output: -1  

## ⚙️ Approach

- Reverse each number.
- Use a **hash map** to store reversed values and their indices.
- Traverse the array:
  - For each element, check if it exists in the map.
  - If yes → calculate distance and update answer.
  - Store its reversed value in the map.

## 🧠 Algorithm

1. Initialize a hashmap `mp`.
2. Iterate through array:
   - Compute reverse of current number.
   - If current number exists in map → update minimum distance.
   - Store reversed number with index.
3. Return result or `-1`.

## 🧮 Complexity Analysis

- Time Complexity: **O(n × d)** (d = digits in number)
- Space Complexity: **O(n)**

## 💻 C++ Solution

```cpp
class Solution {
    int rev(int n){
        int rev = 0;
        while(n != 0){
            rev *= 10;
            rev += n % 10;
            n /= 10;
        }
        return rev;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            int check = rev(nums[i]);

            if(mp.find(nums[i]) != mp.end()){
                ans = min(ans, abs(i - mp[nums[i]]));
            }

            mp[check] = i;
        }

        return (ans == n) ? -1 : ans;
    }
};
