# 🚀 3742. Maximum Path Score in a Grid

## 🧩 Problem Overview
You are given an `m x n` grid where each cell contains values `0`, `1`, or `2`, and an integer `k`.

You start from the top-left `(0,0)` and want to reach the bottom-right `(m-1,n-1)` by moving only **right** or **down**.

### 🧮 Cell Contribution:
- `0` → Score: `0`, Cost: `0`
- `1` → Score: `1`, Cost: `1`
- `2` → Score: `2`, Cost: `1`

👉 Goal: **Maximize score without exceeding total cost `k`**

If no valid path exists → return `-1`

---

## 🧠 Key Idea
- Classic **Grid DP with Cost Constraint (Knapsack-style)**
- At each cell, track:
  - Maximum score for every possible cost `0 → k`
- Use **space optimization** (only previous row needed)

---

## ⚙️ Approach

### 🔹 DP State
```
dp[j][c] = maximum score at column j using cost c
```

We maintain:
- `prev` → previous row
- `curr` → current row

---

### 🔹 Transition
From:
- **Top cell** → `prev[j]`
- **Left cell** → `curr[j-1]`

For each cost `c`:
```
dp[i][j][c] = max(
    from_top + gain,
    from_left + gain
)
```

---

### 🔹 Cost Handling
- If cell value > 0 → cost = 1
- Else → cost = 0

---

### 🔹 Optimization
- Use **rolling array** (`prev`, `curr`) → reduces space
- Limit cost range using:
```
limit = min(k, i + j)
```

---

## ⏱️ Complexity
- Time: `O(m * n * k)`
- Space: `O(n * k)`

---

## 🧾 Code
```cpp
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const int NEG = -1e9;

        vector<vector<int>> prev(n, vector<int>(k + 1, NEG));

        for (int i = 0; i < m; ++i) {
            vector<vector<int>> curr(n, vector<int>(k + 1, NEG));

            for (int j = 0; j < n; ++j) {
                int gain = grid[i][j];
                int need = (gain > 0 ? 1 : 0);

                int limit = min(k, i + j);

                if (i == 0 && j == 0) {
                    curr[0][0] = 0;
                    continue;
                }

                for (int c = need; c <= limit; ++c) {
                    int best = NEG;

                    if (i > 0 && prev[j][c - need] != NEG) {
                        best = max(best, prev[j][c - need] + gain);
                    }

                    if (j > 0 && curr[j - 1][c - need] != NEG) {
                        best = max(best, curr[j - 1][c - need] + gain);
                    }

                    curr[j][c] = best;
                }
            }

            prev.swap(curr);
        }

        int ans = NEG;
        for (int c = 0; c <= k; ++c) {
            ans = max(ans, prev[n - 1][c]);
        }

        return ans < 0 ? -1 : ans;
    }
};
```

---

## 🏁 Summary
- Use DP with cost tracking (like knapsack on grid)
- Transition from top and left
- Optimize space using rolling arrays
- Carefully handle cost constraint

---

## 🔥 Tags
Dynamic Programming, Grid, Knapsack, Optimization

---

## ✍️ Author
Anandkumar Gupta
