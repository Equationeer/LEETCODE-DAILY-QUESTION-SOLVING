# Check if There is a Valid Path in a Grid

## Problem Statement

You are given an `m x n` grid where each cell represents a **street type (1–6)**.

Each street connects in specific directions:

| Type | Connections |
|------|------------|
| 1 | Left ↔ Right |
| 2 | Up ↔ Down |
| 3 | Left ↔ Down |
| 4 | Right ↔ Down |
| 5 | Left ↔ Up |
| 6 | Right ↔ Up |

---

## 🎯 Goal

Start from **(0, 0)** and determine if you can reach **(m - 1, n - 1)**  
by following valid street connections.

---

## 💡 Key Idea

👉 Movement is only valid if:
- Current cell allows movement in a direction
- AND the next cell allows movement **back to the current cell**

✔ This is a **graph traversal problem**  
✔ Use **BFS (Breadth-First Search)**

---

## 🚀 Approach

### 🔹 Step 1: Define Directions

For each street type, define allowed directions:

```cpp
dir[1] = {{0,-1},{0,1}};   // left, right
dir[2] = {{-1,0},{1,0}};   // up, down
dir[3] = {{0,-1},{1,0}};   // left, down
dir[4] = {{0,1},{1,0}};    // right, down
dir[5] = {{0,-1},{-1,0}};  // left, up
dir[6] = {{0,1},{-1,0}};   // right, up
```

---

### 🔹 Step 2: BFS Traversal

- Start from `(0,0)`
- Use a queue
- Mark visited cells

---

### 🔹 Step 3: Validate Connection

From `(r, c)` → `(nr, nc)` is valid if:

```text
(nr, nc) has a direction that leads back to (r, c)
```

---

## 🧠 Algorithm

1. Initialize queue with `(0,0)`
2. Mark it visited
3. While queue is not empty:
   - Pop current cell
   - If destination reached → return true
   - Explore all valid directions
   - Check bidirectional connectivity
4. If BFS ends → return false

---

## ⏱️ Complexity Analysis

| Type | Complexity |
|------|----------|
| Time | `O(m × n)` |
| Space | `O(m × n)` |

---

## 🧾 Code

```cpp
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<int,int>>> dir(7);

        dir[1] = {{0,-1},{0,1}}; 
        dir[2] = {{-1,0},{1,0}};   
        dir[3] = {{0,-1},{1,0}};
        dir[4] = {{0,1},{1,0}};   
        dir[5] = {{0,-1},{-1,0}};  
        dir[6] = {{0,1},{-1,0}};   

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r==m-1 && c==n-1)
                return true;

            for(auto [dr,dc] : dir[grid[r][c]]){
                int nr = r + dr;
                int nc = c + dc;

                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc])
                    continue;

                for(auto [bdr,bdc] : dir[grid[nr][nc]]){
                    if(nr + bdr == r && nc + bdc == c){
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
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
[[2,4,3],
 [6,5,2]]

Output: true
```

---

### Example 2
```
Input:
[[1,2,1],
 [1,2,1]]

Output: false
```

---

### Example 3
```
Input:
[[1,1,2]]

Output: false
```

---

## ✅ Conclusion

- This problem is about **valid connectivity**
- Always check **both directions (forward + backward)**
- BFS ensures shortest valid traversal

---

## 🔥 Pro Tip

Whenever you see:
- Grid + Movement + Valid transitions  
👉 Think **Graph + BFS/DFS**

---

## ⭐ Keep Grinding

You're getting strong in **graph problems** 💪  
Consistency like this will pay off 🚀
