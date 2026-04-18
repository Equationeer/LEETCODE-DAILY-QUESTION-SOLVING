# 🚀 3783. Mirror Distance of an Integer

## 🧩 Problem Statement
You are given an integer `n`. The mirror distance is defined as `abs(n - reverse(n))`, where `reverse(n)` is formed by reversing the digits of `n`. Return the mirror distance.

## 🎯 Goal
Compute and return `|n - reverse(n)|`.

## 🧪 Examples
Example 1: Input: n = 25 → Output: 27 (reverse = 52 → |25 - 52| = 27)  
Example 2: Input: n = 10 → Output: 9 (reverse = 1 → |10 - 1| = 9)  
Example 3: Input: n = 7 → Output: 0 (reverse = 7 → |7 - 7| = 0)

## ⚙️ Approach
Reverse the number and compute absolute difference.

## 🧠 Algorithm
1. Extract digits using `% 10`  
2. Build reversed number  
3. Return `abs(n - reversed_number)`

## 🧮 Complexity
Time: O(d), Space: O(1)

## 💻 C++ Solution
```cpp
class Solution {
public:
    int mirrorDistance(int n) {
        return abs(n - find(n));
    }
private:
    int find(int n){
        int ans = 0;
        while(n){
            int rem = n % 10;
            ans = ans * 10 + rem;
            n /= 10;
        }
        return ans;
    }
};
