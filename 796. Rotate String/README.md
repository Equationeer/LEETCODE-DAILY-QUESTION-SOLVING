# 796. Rotate String

## Problem

Given two strings `s` and `goal`, return **true** if and only if `s` can become `goal` after some number of shifts.

A **shift** means moving the leftmost character of `s` to the rightmost position.

---

## Example

### Input
```cpp
s = "abcde"
goal = "cdeab"
```

### Output
```cpp
true
```

### Explanation
```
abcde → bcdea → cdeab
```

---

### Input
```cpp
s = "abcde"
goal = "abced"
```

### Output
```cpp
false
```

---

## Approach 1 (Simulation)

We simulate all possible rotations.

### Steps
1. If `s == goal`, return true
2. Rotate string one by one
3. After each rotation, check equality
4. If match found → return true
5. Otherwise → return false

---

## C++ Solution (Your Approach)

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal){
            return true;
        }
        for(int i=0;i<s.length();i++){
            char t = s[0];
            s.erase(0,1);
            s += t;
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};
```

---

## Complexity Analysis

### Time Complexity
**O(n²)**  
- Each rotation takes O(n)
- Up to n rotations

### Space Complexity
**O(1)**

---

## Optimized Approach (Better)

Key Idea:

If `goal` is a rotation of `s`, then it must be a substring of `s + s`.

### Code

```cpp
class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};
```

---

## Optimized Complexity

- **Time:** O(n)
- **Space:** O(n)

---

## Key Insight

All rotations of a string are contained inside `s + s`.

Example:
```
s = abcde
s+s = abcdeabcde
```

All rotations appear as substrings.

---

## Tags

- String
- Simulation
- Pattern Matching

---

## LeetCode

Problem Link: https://leetcode.com/problems/rotate-string/

---

## Status

✅ Solved  
⚡ Optimized approach available
