# 657. Robot Return to Origin

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language Used:** C++  
**Time Complexity:** O(n)  
**Space Complexity:** O(1)

---

## Problem Summary

A robot starts at position **(0, 0)** on a 2D plane.

You are given a string `moves` where each character represents a movement:
- 'U' → Up  
- 'D' → Down  
- 'L' → Left  
- 'R' → Right  

👉 The robot moves according to the sequence.

Return **true** if the robot returns to the origin **(0, 0)** after all moves, otherwise return **false**.

---

## Key Observation

To return to origin:

- Number of **Up (U)** moves must equal **Down (D)** moves  
- Number of **Left (L)** moves must equal **Right (R)** moves  

👉 Because they cancel each other out.

---

## Approach

1. Initialize counters:
   - `u`, `d`, `l`, `r`
2. Traverse the string:
   - Increment respective counter based on move
3. Final check:
   - If `u == d` AND `l == r` → return true  
   - Else → return false  

---

## Complexity Analysis

- **Time Complexity:**  
  O(n)  
  (Single pass through the string)

- **Space Complexity:**  
  O(1)  
  (Only counters used)

---

## C++ Implementation

```cpp
class Solution {
public:
    bool judgeCircle(string moves) {
        if (moves.length() & 1) return false;

        int u = 0, d = 0, l = 0, r = 0;

        for (char c : moves) {
            u += (c == 'U');
            d += (c == 'D');
            l += (c == 'L');
            r += (c == 'R');
        }

        return u == d && l == r;
    }
};
