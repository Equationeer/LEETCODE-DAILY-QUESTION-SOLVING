# 11. Container With Most Water

Platform: LeetCode  
Difficulty: Medium  
Language Used: C++  
Time Complexity: O(n)  
Space Complexity: O(1)

---

## Problem Summary

You are given an integer array `height` where each element represents the height of a vertical line drawn at index `i`.

Two lines together with the x-axis form a container.

Return the maximum amount of water that the container can store.

Note: The container cannot be slanted.

---

## Key Observation

The area between two lines depends on:

- Height = min(height[left], height[right])  
- Width = (right - left)  

Formula:

Area = min(height[left], height[right]) * (right - left)

---

## Approach

1. Initialize two pointers:
   - left = 0
   - right = n - 1

2. While left < right:
   - Calculate current area using the formula
   - Update maximum area

3. Move pointer:
   - If height[left] < height[right], increment left
   - Otherwise, decrement right

Reason: The smaller height limits the area, so moving it may increase the result.

---

## Complexity Analysis

Time Complexity: O(n)  
(Single traversal of the array)

Space Complexity: O(1)  
(No extra space used)

---

## C++ Implementation

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int currentHeight = min(height[left], height[right]);
            int currentWidth = right - left;
            int currentArea = currentHeight * currentWidth; // Formula used here

            maxWater = max(maxWater, currentArea);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
};
