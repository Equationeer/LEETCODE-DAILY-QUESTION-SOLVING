# 3898. Find the Degree of Each Vertex

**Platform:** LeetCode  
**Difficulty:** Easy  
**Language Used:** C++  
**Time Complexity:** O(n²)  
**Space Complexity:** O(n)

---

## Problem Summary

You are given an `n x n` adjacency matrix representing an undirected graph with `n` vertices.

- `matrix[i][j] = 1` → edge exists between vertex `i` and `j`
- `matrix[i][j] = 0` → no edge

The **degree of a vertex** is the number of edges connected to it.

Return an array `ans` where `ans[i]` is the degree of vertex `i`.

---

## Key Observation

- Since the graph is undirected and represented using an adjacency matrix:
  - The degree of a node is simply the **sum of its row (or column)**

Because:
- Each `1` in row `i` indicates a connection from vertex `i`

---

## Approach

1. Initialize an array `ans` of size `n` with zeros
2. Traverse the matrix:
   - For each vertex `i`
   - Sum all values in row `i`
3. Store the sum in `ans[i]`

---

## Alternative View

Degree of node `i` =  
Sum of all `matrix[i][j]` for all `j`

---

## Complexity Analysis

- **Time Complexity:** O(n²)  
  - We traverse the entire matrix  

- **Space Complexity:** O(n)  
  - For storing result array  

---

## C++ Implementation

```cpp
class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans[i] += matrix[i][j];
            }
        }

        return ans;
    }
};
