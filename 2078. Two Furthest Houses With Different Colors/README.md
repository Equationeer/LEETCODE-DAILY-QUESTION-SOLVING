# 🚀 2078. Two Furthest Houses With Different Colors

## 🧩 Problem Statement
You are given an integer array `colors` where `colors[i]` represents the color of the ith house. Return the maximum distance between two houses with different colors. The distance between houses i and j is `abs(i - j)`.

## 🎯 Goal
Find the maximum distance such that `colors[i] != colors[j]`.

## 🧪 Examples
Example 1: Input: colors = [1,1,1,6,1,1,1] → Output: 3  
Example 2: Input: colors = [1,8,3,8,3] → Output: 4  
Example 3: Input: colors = [0,1] → Output: 1  

## ⚙️ Approach
Use brute force: check all pairs and update maximum distance when colors differ.

## 🧠 Algorithm
1. Initialize ans = 0  
2. Loop i from 0 to n-1  
3. Loop j from 0 to n-1  
4. If colors[i] != colors[j], update ans = max(ans, abs(i - j))  
5. Return ans  

## 🧮 Complexity
Time: O(n²), Space: O(1)

## 💻 C++ Solution
```cpp
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans = 0;
        for(int i = 0; i < colors.size() - 1; i++){
            for(int j = 0; j < colors.size(); j++){
                if(colors[i] != colors[j])
                    ans = max(ans, abs(i - j));
            }
        }
        return ans;
    }
};
