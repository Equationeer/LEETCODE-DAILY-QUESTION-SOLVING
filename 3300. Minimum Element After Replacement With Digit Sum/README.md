# 3300. Minimum Element After Replacement With Digit Sum

## Problem Statement

You are given an integer array `nums`.

Replace every element with the **sum of its digits** and return the **minimum element** after all replacements.

---

## Example

### Example 1

Input:
```txt
nums = [10,12,13,14]
```

Output:
```txt
1
```

Explanation:

```txt
10 → 1
12 → 3
13 → 4
14 → 5

New array = [1,3,4,5]
Minimum = 1
```

---

### Example 2

Input:
```txt
nums = [1,2,3,4]
```

Output:
```txt
1
```

Explanation:

```txt
Digit sums remain the same.

[1,2,3,4]
Minimum = 1
```

---

### Example 3

Input:
```txt
nums = [999,19,199]
```

Output:
```txt
10
```

Explanation:

```txt
999 → 27
19  → 10
199 → 19

New array = [27,10,19]
Minimum = 10
```

---

## Approach

For every number:

1. Compute its digit sum.
2. Keep track of the minimum digit sum encountered.
3. Return the minimum value.

Since each number is processed once, the solution is straightforward and efficient.

---

## Algorithm

1. Initialize `ans = INT_MAX`.
2. Traverse every number in `nums`.
3. Calculate the sum of its digits using modulo and division.
4. Update the minimum answer.
5. Return `ans`.

---

## Complexity Analysis

### Time Complexity

```txt
O(n × d)
```

Where:

- `n` = number of elements
- `d` = number of digits in each number

Since `nums[i] ≤ 10^4`, `d ≤ 5`.

Effectively:

```txt
O(n)
```

---

### Space Complexity

```txt
O(1)
```

Only a few variables are used.

---

## C++ Solution

```cpp
class Solution {
public:
    int minElement(vector<int>& nums) {

        int ans = INT_MAX;

        for(int num : nums) {

            int sum = 0;

            while(num) {
                sum += num % 10;
                num /= 10;
            }

            ans = min(ans, sum);
        }

        return ans;
    }
};
```

---

## Topics

- Array
- Math
- Digit Manipulation
- Simulation

---

## Learnings

- Extracting digits using `% 10`
- Removing digits using `/ 10`
- Computing digit sums efficiently
- Maintaining a running minimum during traversal

---
