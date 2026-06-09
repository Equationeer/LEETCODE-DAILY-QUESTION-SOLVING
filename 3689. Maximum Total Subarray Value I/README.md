# 3689. Maximum Total Subarray Value I

## Problem Statement

You are given an integer array `nums` and an integer `k`.

You must choose exactly `k` non-empty subarrays. A subarray can be chosen multiple times, and different chosen subarrays may overlap.

The value of a subarray is defined as:

```text
max(subarray) - min(subarray)
```

The total value is the sum of the values of all chosen subarrays.

Return the maximum possible total value.

---

## Key Observation

Since:

- Subarrays can overlap.
- The same subarray can be selected multiple times.

We only need to find the subarray with the **maximum possible value** and choose it exactly `k` times.

The maximum value of any subarray is achieved by a subarray containing:

```text
maximum element of nums
minimum element of nums
```

Therefore:

```text
Maximum Subarray Value = Global Maximum - Global Minimum
```

Since the same subarray can be selected repeatedly:

```text
Answer = (Global Maximum - Global Minimum) × k
```

---

## Approach

1. Find the maximum element in the array.
2. Find the minimum element in the array.
3. Compute:

```text
(maximum - minimum) * k
```

4. Return the result.

---

## Algorithm

1. Initialize:
   - `mx = 0`
   - `mn = INT_MAX`
2. Traverse the array:
   - Update maximum element.
   - Update minimum element.
3. Return:

```cpp
(mx - mn) * k
```

---

## Complexity Analysis

### Time Complexity

**O(n)**

- Single traversal of the array.

### Space Complexity

**O(1)**

- Only a few variables are used.

---

## C++ Solution

```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mx = 0;
        long long mn = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) mx = nums[i];
            if (nums[i] < mn) mn = nums[i];
        }

        return (mx - mn) * k;
    }
};
```

---

## Example 1

### Input

```text
nums = [1,3,2]
k = 2
```

### Calculation

```text
Maximum element = 3
Minimum element = 1

Maximum subarray value = 3 - 1 = 2

Answer = 2 × 2 = 4
```

### Output

```text
4
```

---

## Example 2

### Input

```text
nums = [4,2,5,1]
k = 3
```

### Calculation

```text
Maximum element = 5
Minimum element = 1

Maximum subarray value = 4

Answer = 4 × 3 = 12
```

### Output

```text
12
```

---

## Why This Works

Because the problem allows:

- Choosing the same subarray multiple times.
- Overlapping subarrays.

Once we find the highest possible subarray value, there is no benefit in choosing any smaller-valued subarray. We simply select the best subarray `k` times.

Thus:

```text
Maximum Total Value = k × (Maximum Element − Minimum Element)
```

---

⭐ If you found this solution helpful, consider giving the repository a star!
