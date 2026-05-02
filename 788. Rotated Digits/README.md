# 788. Rotated Digits

## Problem

An integer `x` is considered **good** if after rotating each digit individually by 180 degrees, we get a **valid number that is different from x**.

### Rotation Rules

- `0, 1, 8` → remain the same  
- `2 ↔ 5`  
- `6 ↔ 9`  
- `3, 4, 7` → invalid (cannot rotate)

A number is valid only if **all digits are valid after rotation**.

---

## Task

Given an integer `n`, return the count of **good numbers** in the range `[1, n]`.

---

## Example

### Input
```cpp
n = 10
```

### Output
```cpp
4
```

### Explanation
Good numbers: `2, 5, 6, 9`

---

## Approach

We use **Dynamic Programming (Digit DP idea)**.

### State Meaning

- `dp[i] = 0` → invalid number  
- `dp[i] = 1` → valid but same after rotation  
- `dp[i] = 2` → valid and different (**good number**)  

---

## Logic

### Base Case (Single Digit)

- Same after rotation → `0, 1, 8` → `dp = 1`
- Good numbers → `2, 5, 6, 9` → `dp = 2`
- Invalid → `3, 4, 7` → `dp = 0`

---

### For Multi-Digit Numbers

Split number:

```
i = ab
```

- `a = dp[i / 10]`
- `b = dp[i % 10]`

Then:

- If both are `1` → result is `1`
- If both ≥ 1 and at least one is `2` → result is `2` (good)
- Else → `0`

---

## C++ Solution

```cpp
class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        int count = 0;

        for(int i = 0; i <= n; i++){
            if(i < 10){
                if(i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if(i == 2 || i == 5 || i == 6 || i == 9){
                    dp[i] = 2;
                    count++;
                }
                else dp[i] = 0;
            }
            else{
                int a = dp[i / 10];
                int b = dp[i % 10];

                if(a == 1 && b == 1) dp[i] = 1;
                else if(a >= 1 && b >= 1){
                    dp[i] = 2;
                    count++;
                }
                else dp[i] = 0;
            }
        }

        return count;
    }
};
```

---

## Complexity Analysis

### Time Complexity
**O(n)**

### Space Complexity
**O(n)**

---

## Key Insight

Instead of rotating each number explicitly, we classify digits and **build results using smaller numbers**.

This avoids repeated computation and makes it efficient.

---

## Tags

- Dynamic Programming
- Digit DP
- Math

---

## LeetCode

Problem Link: https://leetcode.com/problems/rotated-digits/

---

## Status

✅ Solved  
🚀 Efficient DP approach used
