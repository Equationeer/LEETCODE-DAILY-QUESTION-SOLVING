# 🔁 Detect Cycles in 2D Grid

## 🧩 Problem Statement

Given a 2D grid of characters `grid` of size `m x n`, determine if there exists a **cycle** formed by cells with the **same character**.

### 🔹 Cycle Definition:
- A path of **length ≥ 4**
- Starts and ends at the **same cell**
- Moves allowed: **up, down, left, right**
- Cannot revisit the **immediate previous cell**

---

## 📌 Key Idea

We need to detect cycles in a grid where:
- Adjacent cells must have the **same value**
- Movement is restricted to **4 directions**
- We must avoid trivial backtracking

👉 This is a classic **DFS + Parent Tracking** problem.

---

## 💡 Approach

### 🔹 Step 1: Use DFS Traversal

- Traverse each cell
- If not visited → start DFS

---

### 🔹 Step 2: Track Parent Cell

While exploring neighbors:
- Ignore the **previous cell (parent)**
- If a visited cell is found again → **cycle detected**

---

### 🔹 Step 3: Cycle Detection Condition

```text
If neighbor is:
✔ same character
✔ already visited
✔ not the parent

👉 Cycle exists
```

---

## 🧠 Algorithm

1. Initialize a `visited` matrix
2. Traverse each cell:
   - If not visited → run DFS
3. In DFS:
   - Mark current cell as visited
   - Explore all 4 directions
   - Skip parent cell
   - If visited again → return true
4. If any DFS returns true → cycle exists

---

## ⏱️ Complexity Analysis

| Type | Complexity |
|------|----------|
| Time | `O(m × n)` |
| Space | `O(m × n)` (visited + recursion stack) |

---

## 🧾 Code

```cpp
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;

    bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc, char ch) {
        visited[r][c] = 1;

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for (auto& d: dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            // Boundary check
            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            // Different character
            if (grid[nr][nc] != ch)
                continue;

            // Skip parent
            if (nr == pr && nc == pc)
                continue;

            // Already visited → cycle found
            if (visited[nr][nc])
                return true;

            // DFS further
            if (dfs(grid, nr, nc, r, c, ch))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        visited.assign(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};
```

---

## 📊 Examples

### Example 1

```
Input:
[
 ["a","a","a","a"],
 ["a","b","b","a"],
 ["a","b","b","a"],
 ["a","a","a","a"]
]

Output: true
```

---

### Example 2

```
Input:
[
 ["c","c","c","a"],
 ["c","d","c","c"],
 ["c","c","e","c"],
 ["f","c","c","c"]
]

Output: true
```

---

### Example 3

```
Input:
[
 ["a","b","b"],
 ["b","z","b"],
 ["b","b","a"]
]

Output: false
```

---

## ✅ Conclusion

- Use **DFS with parent tracking** to avoid false cycles
- Mark visited nodes to prevent reprocessing
- Detect cycles by revisiting a non-parent node

---

## ⭐ Keep Going!

You're building strong graph intuition 🚀  
Keep solving and pushing your limits on LeetCode 💪
