# 🚀 Maximize the Distance Between Points on a Square

## 🧩 Problem Statement

You are given:

- An integer `side` representing the length of a square.
- A list of boundary points `points`, where each point lies on the square boundary.
- An integer `k`.

Your task is to select **k points** such that the **minimum Manhattan distance between any two selected points is maximized**.

---

## 📌 Key Observations

- All points lie on the **boundary of a square**.
- Boundary can be treated as a **1D circular perimeter**.
- Total perimeter = `4 × side`.

---

## 💡 Approach

### 🔹 Step 1: Convert 2D → 1D (Perimeter Mapping)

Map each point to a position on the square perimeter:

- Left edge → `y`
- Top edge → `side + x`
- Right edge → `3*side - y`
- Bottom edge → `4*side - x`

---

### 🔹 Step 2: Sort Positions

Store all mapped values in an array and sort them.

---

### 🔹 Step 3: Binary Search on Answer

We search for the **maximum minimum distance**:

- `low = 1`
- `high = 4 × side`

---

### 🔹 Step 4: Greedy Check

For a candidate distance `mid`:

- Try selecting `k` points such that distance between consecutive points ≥ `mid`
- Handle **circular nature** using array duplication

---

## 🧠 Algorithm

1. Convert points to perimeter values
2. Sort the array
3. Duplicate array to handle circular behavior
4. Binary search for answer
5. Use greedy check for validation

---

## ⏱️ Complexity Analysis

| Type | Complexity |
|------|----------|
| Time | `O(n log n + n * k * log(side))` |
| Space | `O(n)` |

---

## 🧾 Code

```cpp
class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> res;

        // Step 1: Convert to 1D perimeter
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) res.push_back(y);
            else if (y == side) res.push_back(side + x);
            else if (x == side) res.push_back(3LL * side - y);
            else res.push_back(4LL * side - x);
        }

        sort(res.begin(), res.end());
        int m = res.size();

        // Step 2: Duplicate for circular handling
        vector<long long> ext = res;
        for (auto x : res) ext.push_back(x + 4LL * side);

        // Step 3: Check function
        auto check = [&](long long dist) {
            for (int start = 0; start < m; start++) {
                int count = 1;
                long long last = ext[start];

                for (int i = start + 1; i < start + m && count < k; i++) {
                    if (ext[i] - last >= dist) {
                        count++;
                        last = ext[i];
                    }
                }

                if (count >= k) return true;
            }
            return false;
        };

        // Step 4: Binary Search
        long long left = 1, right = 4LL * side;

        while (left <= right) {
            long long mid = (left + right) / 2;
            if (check(mid)) left = mid + 1;
            else right = mid - 1;
        }

        return right;
    }
};
```

---

## 📊 Example

### Input:
```
side = 2
points = [[0,2],[2,0],[2,2],[0,0]]
k = 4
```

### Output:
```
2
```

---

## ✅ Conclusion

- Converting 2D boundary → 1D circular array is the **core trick**
- Binary search + greedy ensures optimal solution
- Handling circular nature correctly is **critical**

---

## ⭐ If you found this helpful

Give a ⭐ to your repo and keep grinding LeetCode 💪
