# 2540. Minimum Common Value

## Problem Statement
Given two integer arrays `nums1` and `nums2` sorted in non-decreasing order, return the minimum integer common to both arrays.

If there is no common integer between the arrays, return `-1`.

---

## Example 1

### Input
```cpp
nums1 = [1,2,3]
nums2 = [2,4]
```

### Output
```cpp
2
```

### Explanation
The smallest common element between both arrays is `2`.

---

## Example 2

### Input
```cpp
nums1 = [1,2,3,6]
nums2 = [2,3,4,5]
```

### Output
```cpp
2
```

### Explanation
The common elements are `2` and `3`.  
The minimum common value is `2`.

---

## Approach

We use a **Hash Set** approach:

1. Insert all elements of `nums1` into an unordered set.
2. Traverse `nums2`.
3. The first element found in the set is the minimum common value because both arrays are sorted.
4. If no common element exists, return `-1`.

---

## Complexity Analysis

- **Time Complexity:** `O(n + m)`
- **Space Complexity:** `O(n)`

Where:
- `n = nums1.size()`
- `m = nums2.size()`

---

## C++ Solution

```cpp
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for(int num : nums1)
            st.insert(num);

        for(int num : nums2) {
            if(st.find(num) != st.end())
                return num;
        }

        return -1;
    }
};
```

---

## Dry Run

### Input
```cpp
nums1 = [1,2,3,6]
nums2 = [2,3,4,5]
```

### Steps

- Insert elements of `nums1` into set:
```cpp
{1,2,3,6}
```

- Traverse `nums2`
  - `2` exists in set → return `2`

Answer = `2`

---

## Key Learning

- Hash sets provide fast lookup in `O(1)` average time.
- Since arrays are sorted, the first matching element in `nums2` is automatically the minimum common value.
- This problem can also be solved using the two-pointer technique with `O(1)` extra space.

---

#️⃣ LeetCode Problem: 2540 - Minimum Common Value
