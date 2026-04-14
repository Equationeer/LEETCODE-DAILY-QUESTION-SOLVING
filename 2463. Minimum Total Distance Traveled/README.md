# 2463. Minimum Total Distance Traveled

## Problem Statement

You are given:
- An array `robot[]` representing positions of robots on the X-axis.
- A 2D array `factory[][]` where each factory has:
  - `position`
  - `limit` (maximum robots it can repair)

Each robot must be assigned to a factory such that:
- Each factory repairs at most `limit` robots
- The **total distance traveled** by all robots is minimized

---

## Distance Formula

Distance traveled by a robot:
```
|robot_position - factory_position|
```

---

## Approach

### Key Observations

1. Sort both `robot` and `factory`
   - Helps assign closest robots to factories

2. Use Dynamic Programming
   - `dp[i][j]` = minimum distance to repair first `i` robots using first `j` factories

---

## DP Transition

We have two choices:

1. Skip current factory  
2. Assign `k` robots (where `k ≤ limit`)

```
dp[i][j] = dp[i][j-1]

For k = 1 to limit:
    dp[i][j] = min(
        dp[i][j],
        dp[i-k][j-1] + cost of assigning k robots
    )
```

---

## Algorithm Steps

1. Sort `robot`
2. Sort `factory`
3. Initialize DP table
4. Iterate over factories
5. Try assigning robots within limit
6. Compute minimum distance

---

## Code (C++)

```cpp
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, INF));

        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int j = 1; j <= m; j++) {
            int pos = factory[j-1][0];
            int limit = factory[j-1][1];

            for (int i = 0; i <= n; i++) {
                dp[i][j] = dp[i][j-1];

                long long dist = 0;
                for (int k = 1; k <= limit && i - k >= 0; k++) {
                    dist += abs(robot[i-k] - pos);
                    dp[i][j] = min(dp[i][j], dp[i-k][j-1] + dist);
                }
            }
        }

        return dp[n][m];
    }
};
```

---

## Complexity Analysis

### Time Complexity
```
O(n * m * limit)
```

### Space Complexity
```
O(n * m)
```

---

## Example

### Input
```
robot = [0,4,6]
factory = [[2,2],[6,2]]
```

### Output
```
4
```

---

## Key Concepts

- Sorting
- Dynamic Programming
- Greedy intuition
- Prefix accumulation

---

## Summary

- Assign robots to factories optimally
- Use DP to try all valid assignments
- Minimize total movement cost

---

