# 2515. Shortest Distance to Target String in a Circular Array

## Problem Statement

You are given:
- A circular array `words[]`
- A string `target`
- A starting index `startIndex`

You can move:
- Left → `(i - 1 + n) % n`
- Right → `(i + 1) % n`

Each move costs **1 step**.

Return the **minimum steps** required to reach `target`.  
If `target` does not exist, return `-1`.

---

## Approach

### Key Idea

- Since the array is **circular**, we can move in both directions.
- We check both:
  - Forward (right)
  - Backward (left)

- Try distances from `0 → n/2`:
  - Because maximum shortest path in a circular array is `n/2`

---

## Algorithm

1. Loop from `i = 0` to `n/2`
2. Check:
   - `(start + i) % n`
   - `(start - i + n) % n`
3. If either equals `target`, return `i`
4. If not found, return `-1`

---

## Code (C++)

```cpp
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int start) {
        int n = words.size();
        
        for (int i = 0; i <= n / 2; i++) {
            if (words[(start + i) % n] == target ||
                words[(start - i + n) % n] == target)
                return i;
        }
        
        return -1;
    }
};
```

---

## Complexity Analysis

### Time Complexity
```
O(n)
```

### Space Complexity
```
O(1)
```

---

## Example

### Input
```
words = ["hello","i","am","leetcode","hello"]
target = "hello"
startIndex = 1
```

### Output
```
1
```

---

## Key Concepts

- Circular Array Traversal
- Modulo Arithmetic
- Two-direction search
- Optimization using `n/2` bound

---

## Summary

- Traverse both directions from start
- Use modulo for circular movement
- Stop at first match → minimum distance
- Return `-1` if target not found

---

## Author

Anandkumar Gupta
