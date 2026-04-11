# 3894. Traffic Signal Color

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language Used:** C++  
**Time Complexity:** O(1)  
**Space Complexity:** O(1)

---

## Problem Summary

You are given an integer `timer` representing the remaining time (in seconds) on a traffic signal.

The signal follows these rules:

- If `timer == 0` → "Green"  
- If `timer == 30` → "Orange"  
- If `30 < timer <= 90` → "Red"  

Return the current state of the signal.  
If none of the conditions are satisfied, return `"Invalid"`.

---

## Approach

- Directly check conditions using `if-else`
- Return the corresponding signal color based on `timer`

---

## Logic

- If timer is exactly `0` → Green  
- If timer is exactly `30` → Orange  
- If timer lies between `31` and `90` → Red  
- Otherwise → Invalid  

---

## Complexity Analysis

- **Time Complexity:** O(1)  
  - Constant time checks  

- **Space Complexity:** O(1)  
  - No extra space used  

---

## C++ Implementation

```cpp
class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0)
            return "Green";

        if (timer == 30)
            return "Orange";

        if (30 < timer && timer <= 90)
            return "Red";

        return "Invalid";
    }
};
