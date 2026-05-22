# 33. Search in Rotated Sorted Array

## Problem Statement
There is an integer array `nums` sorted in ascending order with distinct values. Before being passed to the function, the array may be rotated at some pivot index.

Given the rotated sorted array and an integer `target`, return the index of `target` if it exists in the array, otherwise return `-1`.

You must write an algorithm with **O(log n)** runtime complexity.

---

## Example

### Example 1
Input:
```cpp
nums = [4,5,6,7,0,1,2], target = 0
```

Output:
```cpp
4
```

---

### Example 2
Input:
```cpp
nums = [4,5,6,7,0,1,2], target = 3
```

Output:
```cpp
-1
```

---

## Approach

We use **Binary Search** to achieve `O(log n)` complexity.

At every step:

- Find the middle element.
- Check which half is sorted.
- Decide whether the target lies in the sorted half.
- Move search space accordingly.

### Key Observation
In a rotated sorted array:
- Either the left half is sorted
- Or the right half is sorted

Using this property, we can eliminate half of the array every iteration.

---

## Algorithm

1. Initialize `start` and `end`
2. Perform binary search:
   - Calculate `mid`
   - If `arr[mid] == target`, return `mid`
3. Check if left half is sorted:
   - If target lies there, move `end`
   - Else move `start`
4. Otherwise right half is sorted:
   - If target lies there, move `start`
   - Else move `end`
5. If target not found, return `-1`

---

## Code (C++)

```cpp
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1, mid;

        while(start <= end)
        {
            mid = start + (end - start) / 2;

            if(arr[mid] == target)
                return mid;

            else if(arr[mid] >= arr[0])
            {
                if(arr[start] <= target && arr[mid] > target)
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else
            {
                if(arr[mid] < target && arr[end] >= target)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};
```

---

## Dry Run

Input:
```cpp
nums = [4,5,6,7,0,1,2], target = 0
```

### Iteration 1
```cpp
mid = 3 -> nums[mid] = 7
```

Left half `[4,5,6,7]` is sorted.

Target `0` is not in left half.

Move right:
```cpp
start = mid + 1
```

---

### Iteration 2
```cpp
mid = 5 -> nums[mid] = 1
```

Right half `[1,2]` is sorted.

Target `0` lies in left part.

Move left:
```cpp
end = mid - 1
```

---

### Iteration 3
```cpp
mid = 4 -> nums[mid] = 0
```

Target found.

Return:
```cpp
4
```

---

## Complexity Analysis

### Time Complexity
```cpp
O(log n)
```

### Space Complexity
```cpp
O(1)
```

---

## Concepts Used
- Binary Search
- Rotated Sorted Array
- Searching Algorithms
- Divide and Conquer

---

# LeetCode
Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
