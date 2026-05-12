# 1665. Minimum Initial Energy to Finish Tasks

## Problem Statement
You are given an array `tasks` where:

- `tasks[i][0] = actuali` → actual energy spent to finish the task.
- `tasks[i][1] = minimumi` → minimum energy required to start the task.

You can complete the tasks in any order.

Return the minimum initial energy required to finish all tasks.

---

## Example 1

Input:
```cpp
tasks = [[1,2],[2,4],[4,8]]
```

Output:
```cpp
8
```

Explanation:
Start with 8 energy.

- Do task [4,8] → energy becomes 4
- Do task [2,4] → energy becomes 2
- Do task [1,2] → energy becomes 1

Minimum initial energy required = 8.

---

## Approach

### Greedy Strategy
To minimize the required initial energy:
- Perform tasks with larger `(minimum - actual)` first.
- These tasks require a larger safety margin, so handling them early reduces future energy requirements.

### Steps
1. Sort tasks in descending order of:
```cpp
minimum - actual
```

2. Track:
- `bal` → current remaining energy
- `loan` → extra energy borrowed when current energy is insufficient

3. If current energy is less than required threshold:
- Increase energy by the deficit.

---

## Time Complexity
```cpp
O(n log n)
```

Sorting dominates the complexity.

---

## Space Complexity
```cpp
O(1)
```

Ignoring sorting space.

---

## C++ Solution

```cpp
class Solution {
public:
    int minimumEffort(vector<vector<int>>& shop) {
        sort(shop.begin(), shop.end(), [&](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        int start = shop[0][1];
        int bal = shop[0][1] - shop[0][0];
        int loan = 0;

        for (int i = 1; i < shop.size(); i++) {
            int cost = shop[i][0];
            int thresh = shop[i][1];

            if (bal < thresh) {
                loan += thresh - bal;
                bal = thresh;
            }

            bal -= cost;
        }

        return start + loan;
    }
};
```

---

## Key Concepts Used
- Greedy Algorithm
- Custom Sorting
- Energy Simulation
- Optimization

---

## LeetCode Link
🔗 https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
