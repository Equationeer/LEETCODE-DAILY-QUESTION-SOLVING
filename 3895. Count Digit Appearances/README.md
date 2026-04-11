# 3895. Count Digit Appearances

**Platform:** LeetCode  
**Difficulty:** Medium  
**Language Used:** C++  
**Time Complexity:** O(n * d)  
**Space Complexity:** O(1)

---

## Problem Summary

You are given:
- An integer array `nums`
- An integer `digit` (0–9)

Your task is to count how many times the given `digit` appears in the **decimal representation** of all numbers in `nums`.

---

## Approach

1. Initialize a counter `count = 0`
2. Traverse each number in the array:
   - Extract digits using modulo `% 10`
   - Compare with given `digit`
   - Increment count if matched
3. Continue until the number becomes 0
4. Return total count

---

## Key Observation

- Each number can be broken down digit by digit using:
  - `num % 10` → last digit  
  - `num / 10` → remove last digit  

---

## Important Note

- This approach **modifies the input array**
- If original array must be preserved, use a temporary variable

---

## Complexity Analysis

- **Time Complexity:** O(n * d)  
  - `n` = number of elements  
  - `d` = number of digits per number  

- **Space Complexity:** O(1)  
  - No extra space used  

---

## C++ Implementation

```cpp
class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (nums[i]) {
                int rem = nums[i] % 10;
                nums[i] /= 10;

                if (rem == digit)
                    count++;
            }
        }

        return count;
    }
};
