# 1732. Find the Highest Altitude

## Problem Statement

There is a biker going on a road trip consisting of `n + 1` points.

- The biker starts at point `0` with an altitude of `0`.
- You are given an integer array `gain` where:
  
```text
gain[i] = altitude change between point i and point i + 1
```

Return the **highest altitude** reached during the trip.

---

## Approach

We can simulate the biker's journey while maintaining:

- `alt` → current altitude
- `mx` → highest altitude seen so far

Initially:

```cpp
alt = 0
mx = 0
```

For each altitude gain/loss:

```cpp
alt += gain[i]
```

Update the maximum altitude:

```cpp
mx = max(mx, alt)
```

At the end, `mx` contains the highest altitude reached.

---

## Algorithm

1. Initialize:
   - `alt = 0`
   - `mx = 0`
2. Traverse the `gain` array.
3. Update current altitude:
   
   ```cpp
   alt += gain[i];
   ```

4. Update maximum altitude:
   
   ```cpp
   mx = max(mx, alt);
   ```

5. Return `mx`.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

We traverse the array once.

### Space Complexity

```text
O(1)
```

Only two variables are used.

---

## C++ Solution

```cpp
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0, mx = 0;

        for (int i = 0; i < gain.size(); i++) {
            alt += gain[i];
            mx = max(mx, alt);
        }

        return mx;
    }
};
```

---

## Example 1

### Input

```text
gain = [-5,1,5,0,-7]
```

### Altitudes

Starting altitude:

```text
0
```

After each step:

```text
0
-5
-4
1
1
-6
```

Highest altitude:

```text
1
```

### Output

```text
1
```

---

## Example 2

### Input

```text
gain = [-4,-3,-2,-1,4,3,2]
```

### Altitudes

```text
0
-4
-7
-9
-10
-6
-3
-1
```

Highest altitude:

```text
0
```

### Output

```text
0
```

---

## Dry Run

### Input

```text
gain = [-5,1,5,0,-7]
```

| Step | Gain | Current Altitude | Maximum Altitude |
|--------|--------|--------|--------|
| Start | - | 0 | 0 |
| 1 | -5 | -5 | 0 |
| 2 | +1 | -4 | 0 |
| 3 | +5 | 1 | 1 |
| 4 | 0 | 1 | 1 |
| 5 | -7 | -6 | 1 |

Final Answer:

```text
1
```

---

## Key Insight

The altitude at any point is simply the **prefix sum** of the `gain` array.

So the problem reduces to finding the **maximum prefix sum**, starting from an initial altitude of `0`.

```text
Altitude = Running Sum of gains
Highest Altitude = Maximum Running Sum
```

---

⭐ If you found this solution helpful, consider giving the repository a star!
