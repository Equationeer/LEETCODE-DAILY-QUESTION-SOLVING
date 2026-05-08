# 3629. Minimum Jumps to Reach End via Prime Teleportation

## Problem

You are given an integer array `nums`.

You start at index `0` and want to reach index `n - 1`.

From index `i`, you can:

### 1. Adjacent Jump
Move to:
```cpp
i + 1
```
or
```cpp
i - 1
```

if within bounds.

---

### 2. Prime Teleportation

If:
```cpp
nums[i]
```
is a prime number `p`, then you may jump instantly to any index `j` such that:

```cpp
nums[j] % p == 0
```

Return the minimum number of jumps required.

---

# Example 1

## Input
```cpp
nums = [1,2,4,6]
```

## Output
```cpp
2
```

## Explanation

```cpp
0 -> 1 -> 3
```

- Move normally to index `1`
- `nums[1] = 2` is prime
- Teleport to index `3` since `6 % 2 == 0`

---

# Example 2

## Input
```cpp
nums = [2,3,4,7,9]
```

## Output
```cpp
2
```

---

# Example 3

## Input
```cpp
nums = [4,6,5,8]
```

## Output
```cpp
3
```

---

# Approach

We use:

- **Sieve of Eratosthenes** → to identify primes
- **BFS** → shortest path in graph
- **Hashing / Index Mapping** → fast teleportation

---

# Key Idea

Each index behaves like a graph node.

Possible edges:
- adjacent positions
- teleportation positions

Since all moves cost `1`, BFS guarantees minimum jumps.

---

# Steps

## 1. Find Prime Numbers

Use sieve up to:
```cpp
max(nums)
```

---

## 2. Store Positions

```cpp
pos[value] = list of indices
```

This helps quickly access indices divisible by a prime.

---

## 3. BFS Traversal

For every index:
- visit left
- visit right
- if current value is prime:
  - teleport to all multiples

---

## Important Optimization

After processing prime `p` once:

```cpp
prime[p] = false;
```

This prevents repeated teleportation work.

Also:

```cpp
pos[m].clear();
```

avoids revisiting same indices again.

---

# C++ Solution

```cpp
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        vector<bool> prime(mx + 1, true);

        prime[0] = false;
        prime[1] = false;

        for (long long i = 2; i <= mx; i++) {
            if (prime[i]) {
                for (long long j = i * i; j <= mx; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<vector<int>> pos(mx + 1);

        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        q.push({0, 0});

        vector<int> vis(n, 0);
        vis[0] = 1;

        while (!q.empty()) {

            auto [i, t] = q.front();
            q.pop();

            if (i == n - 1)
                return t;

            // left jump
            if (i > 0 && !vis[i - 1]) {
                q.push({i - 1, t + 1});
                vis[i - 1] = 1;
            }

            // right jump
            if (i < n - 1 && !vis[i + 1]) {
                q.push({i + 1, t + 1});
                vis[i + 1] = 1;
            }

            // teleportation
            if (prime[nums[i]]) {

                int p = nums[i];

                for (int m = p; m <= mx; m += p) {

                    for (int j : pos[m]) {

                        if (!vis[j]) {
                            q.push({j, t + 1});
                            vis[j] = 1;
                        }
                    }

                    pos[m].clear();
                }

                prime[p] = false;
            }
        }

        return n - 1;
    }
};
```

---

# Complexity Analysis

## Time Complexity

### Sieve
```cpp
O(mx log log mx)
```

### BFS + Teleportation
```cpp
O(n + mx/p)
```

Overall approximately:

```cpp
O(mx log log mx + n)
```

---

## Space Complexity

```cpp
O(mx + n)
```

---

# Key Insight

Prime teleportation creates graph shortcuts.

By:
- processing each prime once
- clearing visited multiples

we avoid TLE and achieve efficient BFS traversal.

---

# Tags

- Graph
- BFS
- Sieve of Eratosthenes
- Shortest Path
- Number Theory

---

# LeetCode

Problem Link: https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/

---

# Status

✅ Solved  
🚀 Optimized BFS + Prime Sieve approach used
