# 3655. XOR After Range Multiplication Queries II

Platform: LeetCode  
Difficulty: Hard  
Language Used: C++  
Time Complexity: O(n * sqrt(n) + q * sqrt(n))  
Space Complexity: O(n)

---

## Problem Summary

You are given:
- An integer array `nums` of size `n`
- A list of queries `queries`, where each query is:

[li, ri, ki, vi]

For each query:
1. Start at index `li`
2. While `idx <= ri`:
   - Update:
     nums[idx] = (nums[idx] * vi) % (10^9 + 7)
   - Move:
     idx += ki

After processing all queries, return the **bitwise XOR** of all elements in the array.

---

## Key Observation

- Brute force approach (simulating each query) is too slow for large constraints (n, q ≤ 10^5)
- Optimization is required using:
  - **Square Root Decomposition**
  - Splitting queries based on step size `k`

---

## Approach

### 1. Split Queries into Two Categories

- **Heavy Queries (k ≥ sqrt(n))**
  - Process directly
  - Number of steps is small

- **Light Queries (k < sqrt(n))**
  - Use optimization with **difference arrays**

---

### 2. Handling Heavy Queries

For large `k`:
- Iterate directly:
  - idx = l, l+k, l+2k, ...
- Apply multiplication

---

### 3. Handling Light Queries

For small `k`:
- Group queries by `k`
- Use a **multiplicative difference array**

Steps:
1. Initialize `diff[i] = 1`
2. For each query:
   - Multiply at start index `l`
   - Apply inverse at position after last valid step
3. Build prefix multiplication:
   diff[i] = diff[i] * diff[i - k]
4. Apply accumulated multiplier to nums

---

## Mathematical Tools Used

### Modular Multiplication

nums[i] = (nums[i] * v) % MOD

### Modular Inverse (Fermat’s Theorem)

inv(v) = v^(MOD-2) % MOD

---

## Complexity Analysis

Time Complexity:  
- Heavy queries: O(n * sqrt(n))  
- Light queries: O(n * sqrt(n))  
- Total: O(n * sqrt(n) + q * sqrt(n))  

Space Complexity:  
- O(n) for difference arrays  

---

## C++ Implementation

```cpp
class Solution {
public:
    const int mod = 1e9 + 7;

    long long power(long long base, long long exp){
        long long res = 1;
        while(exp > 0){
            if(exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    long long modInv(long long n){
        return power(n, mod - 2);
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int limit = sqrt(n);

        unordered_map<int, vector<vector<int>>> lightK;

        for(auto& q : queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if(k >= limit){
                for(int i = l; i <= r; i += k)
                    nums[i] = (1LL * nums[i] * v) % mod;
            } else {
                lightK[k].push_back(q);
            }
        }

        for(auto& [k, query] : lightK){
            vector<long long> diff(n, 1);

            for(auto& q : query){
                int l = q[0], r = q[1], v = q[3];

                diff[l] = (diff[l] * v) % mod;

                int steps = (r - l) / k;
                int next = l + (steps + 1) * k;

                if(next < n){
                    diff[next] = (diff[next] * modInv(v)) % mod;
                }
            }

            for(int i = 0; i < n; i++){
                if(i >= k)
                    diff[i] = (diff[i] * diff[i - k]) % mod;

                nums[i] = (1LL * nums[i] * diff[i]) % mod;
            }
        }

        int ans = 0;
        for(auto& num : nums)
            ans ^= num;

        return ans;
    }
};
