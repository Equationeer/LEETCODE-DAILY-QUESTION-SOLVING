# 14. Longest Common Prefix

Platform: LeetCode  
Difficulty: Easy  
Language Used: C++  
Time Complexity: O(n * m)  
Space Complexity: O(1)

---

## Problem Summary

Write a function to find the **longest common prefix** string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

---

## Key Observation

- The prefix must be common in **all strings**
- Compare characters **index by index**
- Stop when:
  - Characters mismatch, or
  - Any string becomes shorter

---

## Approach

1. Take the first string as reference
2. Iterate through each character index `i`
3. For every other string:
   - If `i` is out of bounds OR characters don’t match → return answer
4. Otherwise:
   - Append character to result
5. Continue until mismatch occurs

---

## Complexity Analysis

Time Complexity: O(n * m)  
- n = number of strings  
- m = length of shortest string  

Space Complexity: O(1)  
- No extra space used  

---

## C++ Implementation

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        string first = strs[0];

        for (int i = 0; i < first.size(); i++) {
            char ch = first[i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch) {
                    return ans;
                }
            }

            ans += ch;
        }

        return ans;
    }
};
