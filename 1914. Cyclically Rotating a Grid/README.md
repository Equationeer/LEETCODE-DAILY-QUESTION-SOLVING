# 1914. Cyclically Rotating a Grid

## Problem Link
🔗 https://leetcode.com/problems/cyclically-rotating-a-grid/

## Difficulty
Medium

## Approach
Each matrix consists of multiple layers (rings). For every layer, extract all elements into a 1D array, rotate the array counter-clockwise by `k % layerSize`, and place the rotated values back into the matrix. Since rotating one full cycle gives the same configuration, only `k % layerLength` rotations are needed.

## Algorithm
1. Find total layers using `min(m, n) / 2`
2. For every layer:
   - Traverse boundaries and store elements in a vector
   - Rotate using STL rotate
   - Refill rotated values back into grid
3. Return final grid

## Complexity Analysis

### Time Complexity
```cpp
O(m * n)
```

### Space Complexity
```cpp
O(m + n)
```

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m, n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> vals;

            int top = l, left = l;
            int bottom = m - l - 1;
            int right = n - l - 1;

            for (int j = left; j < right; j++)
                vals.push_back(grid[top][j]);

            for (int i = top; i < bottom; i++)
                vals.push_back(grid[i][right]);

            for (int j = right; j > left; j--)
                vals.push_back(grid[bottom][j]);

            for (int i = bottom; i > top; i--)
                vals.push_back(grid[i][left]);

            int len = vals.size();
            int shift = k % len;

            rotate(vals.begin(), vals.begin() + shift, vals.end());

            int idx = 0;

            for (int j = left; j < right; j++)
                grid[top][j] = vals[idx++];

            for (int i = top; i < bottom; i++)
                grid[i][right] = vals[idx++];

            for (int j = right; j > left; j--)
                grid[bottom][j] = vals[idx++];

            for (int i = bottom; i > top; i--)
                grid[i][left] = vals[idx++];
        }

        return grid;
    }
};
```

## Example

### Input
```cpp
grid = [[1,2,3,4],
        [5,6,7,8],
        [9,10,11,12],
        [13,14,15,16]]

k = 2
```

### Output
```cpp
[[3,4,8,12],
 [2,11,10,16],
 [1,7,6,15],
 [5,9,13,14]]
```

## Key Observations
- Each layer behaves like a circular array.
- Rotating by layer length results in the same arrangement.
- Matrix dimensions are always even, guaranteeing valid layers.

## Tags
`Matrix` `Simulation` `Array` `Implementation`
