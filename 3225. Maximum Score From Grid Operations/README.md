# 🚀 3225. Maximum Score From Grid Operations

## 🧩 Problem Overview
You are given an `n x n` grid where all cells are initially **white**. You can perform operations where you select a column `j` and a row `i`, and color all cells from the top to row `i` in that column as **black**. The score is calculated as the sum of all **white cells** that have at least one **horizontally adjacent black cell**. The goal is to **maximize the score**.

---

## 🧠 Key Idea
- Each column can be treated as choosing a **height** up to which cells are painted black.
- The score depends on interactions between **adjacent columns**.
- Use **Dynamic Programming + Prefix Sums + Optimization (Prefix/Suffix Max)**.

---

## ⚙️ Approach

### 1️⃣ Prefix Sum (Column-wise)
We compute prefix sums for each column:
```cpp
col[j][i] = sum of grid[0...i-1][j]
```

### 2️⃣ DP State
```cpp
dp[curr][prev]
```
- `curr` → height of current column  
- `prev` → height of previous column  

### 3️⃣ Transition
- If `curr <= prev`:
```cpp
gain = col[c][prev] - col[c][curr]
```

- If `curr > prev`:
```cpp
gain = col[c-1][curr] - col[c-1][prev]
```

### 4️⃣ Optimization
Use:
- Prefix max → `prefMax`
- Suffix max → `suffMax`

---

## ⏱️ Complexity
- Time: `O(n^3)` (optimized)  
- Space: `O(n^2)`

---

## 🧾 Code
```cpp
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        if (m == 1) return 0;

        vector<vector<long long>> col(m, vector<long long>(n + 1, 0));
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                col[j][i + 1] = col[j][i] + grid[i][j];
            }
        }

        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> prefMax(n + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> suffMax(n + 1, vector<long long>(n + 1, 0));

        for (int c = 1; c < m; c++) {

            vector<vector<long long>> newdp(n + 1, vector<long long>(n + 1, 0));

            for (int curr = 0; curr <= n; curr++) {
                for (int prev = 0; prev <= n; prev++) {

                    if (curr <= prev) {
                        long long gain = col[c][prev] - col[c][curr];

                        newdp[curr][prev] = max(
                            newdp[curr][prev],
                            suffMax[prev][0] + gain
                        );
                    }
                    else {
                        long long gain = col[c-1][curr] - col[c-1][prev];

                        newdp[curr][prev] = max({
                            newdp[curr][prev],
                            suffMax[prev][curr],
                            prefMax[prev][curr] + gain
                        });
                    }
                }
            }

            for (int curr = 0; curr <= n; curr++) {

                prefMax[curr][0] = newdp[curr][0];

                for (int prev = 1; prev <= n; prev++) {

                    long long penalty = 0;
                    if (prev > curr)
                        penalty = col[c][prev] - col[c][curr];

                    prefMax[curr][prev] = max(
                        prefMax[curr][prev-1],
                        newdp[curr][prev] - penalty
                    );
                }

                suffMax[curr][n] = newdp[curr][n];

                for (int prev = n-1; prev >= 0; prev--) {
                    suffMax[curr][prev] = max(
                        suffMax[curr][prev+1],
                        newdp[curr][prev]
                    );
                }
            }

            dp = move(newdp);
        }

        long long ans = 0;
        for (int k = 0; k <= n; k++) {
            ans = max({ans, dp[0][k], dp[n][k]});
        }

        return ans;
    }
};
```

---

## 🏁 Summary
- Convert problem into column-wise DP  
- Use prefix sums for fast calculations  
- Optimize transitions using prefix & suffix maximums  

---

## 🔥 Tags
Dynamic Programming, Prefix Sum, Optimization, Hard

---

## ✍️ Author
Anandkumar Gupta
