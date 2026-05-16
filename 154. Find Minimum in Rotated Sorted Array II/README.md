# 154. Find Minimum in Rotated Sorted Array II

## Problem Statement
Given a sorted rotated array `nums` that may contain duplicates, return the minimum element in the array.

Unlike the previous version of this problem, duplicates are allowed, which can affect the efficiency of binary search.

---

## Example 1
### Input
```cpp
nums = [1,3,5]
```

### Output
```cpp
1
```

---

## Example 2
### Input
```cpp
nums = [2,2,2,0,1]
```

### Output
```cpp
0
```

---

## Approach
- Initialize the minimum element as the first element.
- Traverse the entire array.
- Update the answer whenever a smaller value is found.
- Return the minimum value.

---

## Complexity Analysis
- **Time Complexity:** O(n)
- **Space Complexity:** O(1)

---

## C++ Solution

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
       int ans = nums[0];

       for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < ans)
                ans = nums[i];
       }

       return ans;
    }
};
```

---

## Explanation
Since duplicates are present, the rotated array may not always allow a clean binary search split.  
This solution simply scans the array and keeps track of the minimum element.

For example:

```cpp
nums = [2,2,2,0,1]
```

- Start with `ans = 2`
- Traverse elements
- When `0` is found, update `ans = 0`
- Return `0`

---

## Key Learning
- Duplicates can break the strict ordering property used in binary search.
- A linear scan guarantees the correct answer.
- Simple solutions are sometimes the safest approach for duplicate cases.

---

#️⃣ LeetCode Problem: 154 - Find Minimum in Rotated Sorted Array II
