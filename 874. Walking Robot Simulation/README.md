# 874. Walking Robot Simulation

Platform: LeetCode  
Difficulty: Medium  
Language Used: C++  
Time Complexity: O(n + m)  
Space Complexity: O(m)  

---

## Problem Summary

A robot starts at position `(0, 0)` on an infinite 2D plane facing **North**.

You are given:
- An array `commands`
- A list of `obstacles`

The robot follows these rules:

- `-2` → Turn left (90°)
- `-1` → Turn right (90°)
- `1 to 9` → Move forward step-by-step

If the robot encounters an obstacle, it stops before it and continues with the next command.

Return the **maximum squared Euclidean distance** from the origin reached at any point.

---

## Key Observation

- The robot moves **one step at a time**, so obstacle checking must be done per step
- Store obstacles in a **set** for fast lookup
- Maintain direction using an index:
  - North → (0, 1)
  - East → (1, 0)
  - South → (0, -1)
  - West → (-1, 0)

Distance formula:

maxDistance = x * x + y * y

---

## Approach

1. Store all obstacles in a set of `(x, y)` pairs
2. Maintain direction index `dir`:
   - 0 → North
   - 1 → East
   - 2 → South
   - 3 → West

3. Traverse each command:
   - If `-1`: turn right → `dir = (dir + 1) % 4`
   - If `-2`: turn left → `dir = (dir + 3) % 4`
   - Else:
     - Move step-by-step
     - Check obstacle before each move
     - Update position and max distance

---

## Complexity Analysis

Time Complexity: O(n + m)  
- n = number of commands  
- m = number of obstacles  

Space Complexity: O(m)  
- For storing obstacles  

---

## C++ Implementation

```cpp
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        set<pair<int,int>> blocked;
        for (auto &o : obstacles) {
            blocked.insert({o[0], o[1]});
        }

        vector<pair<int,int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int x = 0, y = 0;
        int dir = 0; 
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } 
            else {
                while (cmd--) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;

                    if (blocked.count({nx, ny}))
                        break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};
