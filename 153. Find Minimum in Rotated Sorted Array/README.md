# 153. Find Minimum in Rotated Sorted Array

## Problem Statement
Suppose an array sorted in ascending order is rotated between `1` and `n` times.

Given the rotated sorted array `nums` containing unique elements, return the minimum element.

You must solve it in:
```cpp
O(log n)
```
time complexity.

---

## Example 1

Input:
```cpp
nums = [3,4,5,1,2]
```

Output:
```cpp
1
```

Explanation:
Original array:
```cpp
[1,2,3,4,5]
```

Rotated 3 times.

---

## Example 2

Input:
```cpp
nums = [4,5,6,7,0,1,2]
```

Output:
```cpp
0
```

---

## Example 3

Input:
```cpp
nums = [11,13,15,17]
```

Output:
```cpp
11
```

---

## Approach

### Binary Search
Since the array is sorted and rotated:
- One side will always remain sorted.
- The minimum element lies in the unsorted portion.

### Key Observation
If:
```cpp
arr[mid] >= arr[0]
```

then the left side is sorted, so minimum lies on the right side.

Otherwise:
- `arr[mid]` could be the minimum.
- Search in the left half.

---

## Algorithm
1. Initialize:
```cpp
start = 0
end = n - 1
ans = arr[0]
```

2. Perform binary search:
- If left side sorted → move right.
- Else update answer and move left.

3. Return minimum element.

---

## Time Complexity
```cpp
O(log n)
```

---

## Space Complexity
```cpp
O(1)
```

---

## C++ Solution

```cpp
class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;
        int ans = arr[0];

        while(start <= end) {

            int mid = start + (end - start) / 2;

            // Left side sorted
            if(arr[mid] >= arr[0]) {
                start = mid + 1;
            }

            // Minimum lies on left side
            else {
                ans = arr[mid];
                end = mid - 1;
            }
        }

        return ans;
    }
};
```

---

## Key Concepts Used
- Binary Search
- Rotated Sorted Array
- Divide and Conquer

---

## LeetCode Link
🔗 https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
