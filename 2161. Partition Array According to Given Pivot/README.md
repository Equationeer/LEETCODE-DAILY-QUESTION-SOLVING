# 2161. Partition Array According to Given Pivot

## Problem Statement

You are given an integer array `nums` and an integer `pivot`.

Rearrange the array such that:

1. All elements smaller than `pivot` appear before elements greater than `pivot`.
2. All elements equal to `pivot` appear between them.
3. The relative order of elements smaller than `pivot` is preserved.
4. The relative order of elements greater than `pivot` is preserved.

Return the rearranged array.

---

## Approach

We create a new array `ans` of the same size.

- Traverse from the left and place all elements smaller than `pivot` at the beginning.
- Simultaneously traverse from the right and place all elements greater than `pivot` at the end.
- After placing smaller and greater elements, fill the remaining positions with `pivot`.

This maintains the relative order of both smaller and greater elements while satisfying all partition conditions.

---

## Algorithm

1. Create an answer array `ans` of size `n`.
2. Use two pointers:
   - `left` to place elements smaller than `pivot`.
   - `right` to place elements greater than `pivot`.
3. Traverse:
   - If `nums[i] < pivot`, place it at `ans[left]`.
   - If `nums[j] > pivot`, place it at `ans[right]`.
4. Fill all remaining positions with `pivot`.
5. Return `ans`.

---

## Complexity Analysis

### Time Complexity

**O(n)**

- Single traversal of the array.

### Space Complexity

**O(n)**

- Extra array used for storing the result.

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int i = 0, j = n - 1;

        while (i < n) {
            if (nums[i] < pivot) {
                ans[left++] = nums[i];
            }

            if (nums[j] > pivot) {
                ans[right--] = nums[j];
            }

            i++;
            j--;
        }

        while (left <= right) {
            ans[left++] = pivot;
        }

        return ans;
    }
};
```

---

## Example 1

### Input

```text
nums = [9,12,5,10,14,3,10]
pivot = 10
```

### Output

```text
[9,5,3,10,10,12,14]
```

### Explanation

- Elements smaller than 10: `[9,5,3]`
- Elements equal to 10: `[10,10]`
- Elements greater than 10: `[12,14]`

Final array:

```text
[9,5,3,10,10,12,14]
```

---

## Example 2

### Input

```text
nums = [-3,4,3,2]
pivot = 2
```

### Output

```text
[-3,2,4,3]
```

---

## Key Insight

Instead of performing in-place partitioning, build the answer array directly:

- Smaller elements from the front.
- Greater elements from the back.
- Fill the middle with pivots.

This guarantees stability (preserves relative order) and runs in linear time.

---

⭐ If you found this solution helpful, consider giving the repository a star!
