# 3488. Closest Equal Element Queries

## Problem Statement

You are given:
- A circular array `nums[]`
- An array `queries[]`

For each query index `q`, find:

- The **minimum circular distance** between index `q` and any other index `j` such that:
```
nums[j] == nums[q]
```

If no such index exists, return `-1`.

---

## Circular Distance Formula

For two indices `i` and `j`:

```
distance = min(|i - j|, n - |i - j|)
```

---

## Approach

### Key Idea

1. Store indices of each value using a hashmap:
```
value → list of indices
```

2. For each query:
   - Get all indices where `nums[q]` appears
   - If only one occurrence → answer is `-1`
   - Otherwise:
     - Find nearest left and right occurrences using binary search
     - Compute circular distance

---

## Algorithm Steps

1. Build map:
```
mp[value] = sorted indices
```

2. For each query `q`:
   - Get vector `v = mp[nums[q]]`
   - Find position using `lower_bound`
   - Check:
     - Left neighbor
     - Right neighbor
   - Compute circular distance
   - Take minimum

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int q : queries) {
            vector<int>& v = mp[nums[q]];

            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
            int res = INT_MAX;

            int left = v[(pos - 1 + v.size()) % v.size()];
            int d1 = abs(q - left);
            res = min(res, min(d1, n - d1));

            int right = v[(pos + 1) % v.size()];
            int d2 = abs(q - right);
            res = min(res, min(d2, n - d2));

            ans.push_back(res);
        }

        return ans;
    }
};
```

---

## Complexity Analysis

### Time Complexity
```
O(n + q log n)
```

- Building map: `O(n)`
- Each query: `O(log n)` (binary search)

---

### Space Complexity
```
O(n)
```

- Hashmap stores indices

---

## Example

### Input
```
nums = [1,3,1,4,1,3,2]
queries = [0,3,5]
```

### Output
```
[2, -1, 3]
```

---

## Key Concepts

- Circular Array
- HashMap (value → indices)
- Binary Search (lower_bound)
- Modular arithmetic
- Nearest neighbor search

---

## Summary

- Group indices of same values
- Use binary search to find nearest occurrences
- Compute circular distance
- Efficient for large constraints

---

## Author

Anandkumar Gupta
