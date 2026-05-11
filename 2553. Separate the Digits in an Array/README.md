# 2553. Separate the Digits in an Array

## Problem Statement
Given an array of positive integers `nums`, return an array `answer` that consists of the digits of each integer in `nums` after separating them in the same order they appear.

---

## Example

### Example 1
Input:
```cpp
nums = [13,25,83,77]
```

Output:
```cpp
[1,3,2,5,8,3,7,7]
```

Explanation:
- 13 → [1,3]
- 25 → [2,5]
- 83 → [8,3]
- 77 → [7,7]

Final array:
```cpp
[1,3,2,5,8,3,7,7]
```

---

### Example 2
Input:
```cpp
nums = [7,1,3,9]
```

Output:
```cpp
[7,1,3,9]
```

---

## Approach
- Traverse every number in the array.
- Extract digits using modulo `% 10`.
- Store digits temporarily in reverse order.
- Reverse the temporary array to maintain original digit order.
- Append digits into the final answer array.

---

## Time Complexity
```cpp
O(total digits)
```

## Space Complexity
```cpp
O(total digits)
```

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int num : nums) {

            vector<int> temp;

            while(num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }

            reverse(temp.begin(), temp.end());

            for(int digit : temp) {
                ans.push_back(digit);
            }
        }

        return ans;
    }
};
```

---

## Key Concepts Used
- Arrays / Vectors
- Digit Extraction
- Modulo Operator
- Reverse Traversal

---

## LeetCode Link
🔗 https://leetcode.com/problems/separate-the-digits-in-an-array/
