# 1306. Jump Game III

## Problem Statement
Given an array of non-negative integers `arr`, you are initially positioned at the `start` index of the array.

When you are at index `i`, you can jump to:

- `i + arr[i]`
- `i - arr[i]`

Return `true` if you can reach any index with value `0`, otherwise return `false`.

You cannot jump outside the array.

---

## Example 1

### Input
```cpp
arr = [4,2,3,0,3,1,2], start = 5
```

### Output
```cpp
true
```

### Explanation
One possible path:

```cpp
5 -> 4 -> 1 -> 3
```

At index `3`, the value is `0`.

---

## Example 2

### Input
```cpp
arr = [4,2,3,0,3,1,2], start = 0
```

### Output
```cpp
true
```

---

## Example 3

### Input
```cpp
arr = [3,0,2,1,2], start = 2
```

### Output
```cpp
false
```

---

## Approach

We use **Breadth First Search (BFS)**:

- Start from the given index.
- From every index:
  - Jump forward → `i + arr[i]`
  - Jump backward → `i - arr[i]`
- Use a `visited` array to avoid infinite loops.
- If any visited index contains `0`, return `true`.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## C++ Solution

```cpp
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i < 0 || i >= n || visited[i])
                continue;

            if (arr[i] == 0)
                return true;

            visited[i] = true;

            q.push(i + arr[i]);
            q.push(i - arr[i]);
        }

        return false;
    }
};
```

---

## Dry Run

### Input
```cpp
arr = [4,2,3,0,3,1,2]
start = 5
```

### Steps

- Start at index `5`
- Jump to:
  - `5 + 1 = 6`
  - `5 - 1 = 4`

From index `4`:
- Jump to:
  - `4 + 3 = 7` (invalid)
  - `4 - 3 = 1`

From index `1`:
- Jump to:
  - `1 + 2 = 3`

At index `3`, value = `0`

Answer = `true`

---

## Key Learning

- BFS helps explore all reachable positions level by level.
- `visited` array prevents revisiting nodes and infinite loops.
- Always check bounds before accessing indices.

---

#️⃣ LeetCode Problem: 1306 - Jump Game III
