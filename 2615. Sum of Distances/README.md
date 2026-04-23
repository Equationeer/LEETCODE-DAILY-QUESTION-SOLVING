# 🚀 2615. Sum of Distances

## 🟡 Difficulty
Medium

---

## 🧠 Problem Statement

You are given an integer array `nums`.

For each index `i`, compute:

```
arr[i] = sum of |i - j| for all j such that nums[j] == nums[i] and j != i
```

If no such index exists, then `arr[i] = 0`.

---

## ✨ Examples

### Example 1:
```
Input: nums = [1,3,1,1,2]
Output: [5,0,3,4,0]
```

### Example 2:
```
Input: nums = [0,5,3]
Output: [0,0,0]
```

---

## 💡 Approach

### 🔑 Key Idea:
- Group indices having same value.
- For each group:
  - Use prefix sum to efficiently calculate distances.
  
### 🧠 Logic:
For a group of indices:
```
arr = [i1, i2, i3, i4 ...]
```

For each index:
- Left contribution:
```
i * arr[i] - sum(left indices)
```
- Right contribution:
```
sum(right indices) - (count_right * arr[i])
```

👉 Total = left + right

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<long long, vector<int>> mp;

        // Step 1: Group indices
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        // Step 2: Process each group
        for(auto &idx : mp){
            auto &arr = idx.second;
            int siz = arr.size();

            // Prefix sum of indices
            vector<long long> pref(siz, 0);
            pref[0] = arr[0];

            for(int i = 1; i < siz; i++){
                pref[i] = pref[i - 1] + arr[i];
            }

            // Step 3: Calculate result
            for(int i = 0; i < siz; i++){
                long long left = 0, right = 0;

                if(i > 0){
                    left = (long long)i * arr[i] - pref[i - 1];
                }

                if(i < siz - 1){
                    right = (pref[siz - 1] - pref[i]) - (long long)(siz - i - 1) * arr[i];
                }

                res[arr[i]] = left + right;
            }
        }

        return res;
    }
};
```

---

## 📊 Complexity Analysis

### ⏱ Time Complexity:
- O(n)
  - Each element processed constant times

### 🧠 Space Complexity:
- O(n)
  - For hashmap + prefix arrays

---

## 🎯 Key Insight

👉 Instead of calculating pairwise distances (O(n²)),  
we use **prefix sums + grouping** to reduce it to **O(n)**.

---

## ✅ Conclusion

- Efficient grouping is the core trick
- Prefix sum avoids recomputation
- Clean and optimal solution 💯

---

## 📌 Tags
- HashMap
- Prefix Sum
- Arrays
- Math

---

🔥 If this helped, consider giving a ⭐ to your repo!
