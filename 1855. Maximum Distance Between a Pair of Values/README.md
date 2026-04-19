# 🚀 1855. Maximum Distance Between a Pair of Values

## 🧩 Problem Statement
You are given two **non-increasing arrays** `nums1` and `nums2`.

A pair `(i, j)` is valid if:
- `0 <= i < nums1.length`
- `0 <= j < nums2.length`
- `i <= j`
- `nums1[i] <= nums2[j]`

The distance of the pair is `j - i`.

## 🎯 Goal
Return the **maximum distance** among all valid pairs.  
If no valid pair exists, return `0`.

---

## 🧪 Examples

Example 1:  
Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]  
Output: 2  

Example 2:  
Input: nums1 = [2,2,2], nums2 = [10,10,1]  
Output: 1  

Example 3:  
Input: nums1 = [30,29,19,5], nums2 = [25,25,25,25,25]  
Output: 2  

---

## ⚙️ Approach (Two Pointers)

- Since both arrays are **non-increasing**, we can use **two pointers**.
- Start with `i = 0`, `j = 0`.
- If `nums1[i] <= nums2[j]`, update answer and move `j` forward.
- Otherwise, move `i` forward.

---

## 🧠 Algorithm

1. Initialize `i = 0`, `j = 0`, `ans = 0`
2. While `i < n1` and `j < n2`:
   - If `nums1[i] <= nums2[j]`:
     - Update `ans = max(ans, j - i)`
     - Move `j++`
   - Else:
     - Move `i++`
3. Return `ans`

---

## 🧮 Complexity

- Time Complexity: **O(n + m)**
- Space Complexity: **O(1)**

---

## 💻 C++ Solution

```cpp
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int ans = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                ans = max(ans, j - i);
                j++;  
            } else {
                i++;  
            }
        }

        return ans;
    }
};
