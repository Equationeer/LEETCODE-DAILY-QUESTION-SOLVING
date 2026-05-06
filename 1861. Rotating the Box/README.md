# 1861. Rotating the Box

## Problem

You are given an `m x n` matrix `boxGrid` representing a box with:

- `'#'` → stone  
- `'*'` → obstacle  
- `'.'` → empty  

The box is rotated **90° clockwise**, and stones fall down due to gravity.

### Rules

- Stones fall until they hit:
  - another stone `#`
  - obstacle `*`
  - bottom
- Obstacles do NOT move
- Stones do NOT move horizontally

---

## Example

### Input
```cpp
boxGrid = [["#",".","#"]]
```

### Output
```cpp
[
 [".","#","#"]
]
```

---

## Approach

### Key Idea

Instead of:
1. Rotating first
2. Then applying gravity  

We **simulate gravity row-wise first**, then directly place elements in rotated positions.

---

## Steps

1. Initialize result matrix `rotate[n][m]` filled with `'.'`
2. Traverse each row from **right to left**
3. Maintain a pointer `bottom`:
   - Represents where the next stone will fall
4. For each cell:
   - If `'#'` → place at `bottom` and decrement
   - If `'*'` → place obstacle and reset `bottom`

---

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int col = boxGrid[0].size();

        vector<vector<char>> rotate(col, vector<char>(row, '.'));

        for (int k = 0; k < row; k++) {
            int bottom = col - 1;

            for (int j = col - 1; j >= 0; j--) {

                if (boxGrid[k][j] == '#') {
                    rotate[bottom][row - 1 - k] = '#';
                    bottom--;
                } 
                else if (boxGrid[k][j] == '*') {
                    rotate[j][row - 1 - k] = '*';
                    bottom = j - 1;
                }
            }
        }

        return rotate;
    }
};
```

---

## Complexity Analysis

### Time Complexity
**O(m × n)**

### Space Complexity
**O(m × n)**

---

## Key Insight

- Gravity can be handled using a **pointer approach**
- Combine **rotation + gravity in one pass**
- Avoids extra processing

---

## Alternative Approach

1. Apply gravity row-wise
2. Then rotate matrix

But this requires **two passes**, so your solution is more optimal.

---

## Tags

- Matrix
- Simulation
- Two Pointer

---

## LeetCode

Problem Link: https://leetcode.com/problems/rotating-the-box/

---

## Status

✅ Solved  
🚀 Optimized single-pass simulation used
