# 1674. Minimum Moves to Make Array Complementary

## Problem Statement
You are given an integer array `nums` of even length `n` and an integer `limit`.

In one move, you can replace any element in `nums` with another integer between `1` and `limit`.

The array is called complementary if for every index `i`:

```cpp
nums[i] + nums[n - 1 - i]
```

is equal for all pairs.

Return the minimum number of moves required to make the array complementary.

---

## Example 1

Input:
```cpp
nums = [1,2,4,3], limit = 4
```

Output:
```cpp
1
```

Explanation:
Change array to:
```cpp
[1,2,2,3]
```

Now every mirrored pair sums to:
```cpp
4
```

---

## Approach

### Key Observation
For every mirrored pair:

```cpp
(nums[i], nums[n-1-i])
```

we calculate how many moves are needed for every possible target sum.

Each pair contributes:

- `0 moves` for one exact sum
- `1 move` for a range of sums
- `2 moves` otherwise

Instead of checking every target separately, we use a **difference array** to efficiently track move changes.

---

## Difference Array Logic

For a pair:

```cpp
a = min(nums[i], nums[j])
b = max(nums[i], nums[j])
```

### Move Ranges

- Initially every target needs `2 moves`
- From `a + 1` to `b + limit` → only `1 move`
- At exact sum `a + b` → `0 moves`

We update ranges using prefix sum technique.

---

## Time Complexity
```cpp
O(n + limit)
```

---

## Space Complexity
```cpp
O(limit)
```

---

## C++ Solution

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta((limit << 1) + 2, 0);

        for (int i = 0; i < n >> 1; i++) {
            int min = nums[i];
            int max = nums[n - 1 - i];

            if (min > max)
                swap(min, max);

            delta[2] += 2;

            delta[min + 1]--;

            delta[min + max]--;

            delta[min + max + 1]++;

            delta[max + limit + 1]++;
        }

        int res = n;
        int moves = 0;

        for (int targ = 2; targ <= limit * 2; targ++) {
            moves += delta[targ];
            res = min(res, moves);
        }

        return res;
    }
};
```

---

## Key Concepts Used
- Greedy
- Difference Array
- Prefix Sum
- Range Updates
- Array Optimization

---

## LeetCode Link
🔗 https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
