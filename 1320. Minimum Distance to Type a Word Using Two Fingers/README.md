# 1320. Minimum Distance to Type a Word Using Two Fingers

**Platform:** LeetCode  
**Difficulty:** Hard  
**Language Used:** C++  
**Time Complexity:** O(n × 26 × 26)  
**Space Complexity:** O(n × 26 × 26)

---

## Problem Summary

You are given a string `word` consisting of uppercase English letters.

You type the word using **two fingers** on a keyboard where each letter is mapped to a coordinate on a grid.

The goal is to return the **minimum total distance** required to type the word using both fingers optimally.

Distance between two positions:
|x1 - x2| + |y1 - y2|

---

## Key Idea

- Each finger can independently move to type characters
- At each step, we decide:
  - Which finger types the current character
- We use **Dynamic Programming (DP)** to track optimal states

---

## State Definition

Let:

dp[i][j][k] = minimum cost to type first i characters  
where:
- left finger is at character j
- right finger is at character k

---

## Transition

For each new character `t`:

We have two choices:

### 1. Move left finger
dp[i+1][t][k] = min(dp[i+1][t][k], dp[i][j][k] + dist(j, t))

### 2. Move right finger
dp[i+1][j][t] = min(dp[i+1][j][t], dp[i][j][k] + dist(k, t))

---

## Distance Function

Each letter is mapped as:
index → (row = x, col = y)

Position mapping:
- x = index / 6
- y = index % 6

Distance:
|x1 - x2| + |y1 - y2|

---

## Approach

1. Convert characters to indices (0–25)
2. Initialize DP array with large values
3. Start with both fingers free
4. For each character:
   - Try assigning it to left finger
   - Try assigning it to right finger
5. Take minimum over all final states

---

## Complexity Analysis

- **Time Complexity:** O(n × 26 × 26)  
  - For each character, we check all finger positions  

- **Space Complexity:** O(n × 26 × 26)  
  - DP table storage  

---

## C++ Implementation

```cpp
class Solution {
public:
    int cal(int a, int b) {
        return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
    }

    int minimumDistance(string s) {
        int n = s.size();
        int dp[300][26][26];

        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 26; j++)
                for (int k = 0; k < 26; k++)
                    dp[i][j][k] = 1e6;

        // initial state: no fingers used
        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++) {
            int t = s[i] - 'A';

            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (dp[i][j][k] == 1e6) continue;

                    // move left finger
                    dp[i + 1][t][k] = min(
                        dp[i + 1][t][k],
                        dp[i][j][k] + cal(j, t)
                    );

                    // move right finger
                    dp[i + 1][j][t] = min(
                        dp[i + 1][j][k],
                        dp[i][j][k] + cal(k, t)
                    );
                }
            }
        }

        int ans = 1e6;

        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                ans = min(ans, dp[n][j][k]);
            }
        }

        return ans;
    }
};
