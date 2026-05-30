# 3161. Block Placement Queries

## Problem Statement

There is an infinite number line starting from `0` and extending towards positive infinity.

You are given queries of two types:

### Type 1

```txt
[1, x]
```

Place an obstacle at position `x`.

---

### Type 2

```txt
[2, x, sz]
```

Determine whether a block of length `sz` can be placed completely inside the range:

```txt
[0, x]
```

such that:

- The block does not intersect any obstacle.
- The block may touch an obstacle.
- Queries are independent (the block is not actually placed).

Return a boolean array containing answers for all Type-2 queries.

---

## Example

### Example 1

Input:

```txt
queries =
[[1,2],
 [2,3,3],
 [2,3,1],
 [2,2,2]]
```

Output:

```txt
[false,true,true]
```

Explanation:

After placing an obstacle at position `2`:

```txt
0 ----- 2 ----- 3
```

- Length 3 block cannot fit inside `[0,3]`
- Length 1 block can fit
- Length 2 block can fit

---

## Key Observation

Directly processing every query is difficult because:

- Up to `150000` queries.
- Obstacles are inserted dynamically.
- Need to answer interval-length existence queries efficiently.

---

## Reverse Processing Trick

Instead of processing obstacle insertions forward:

### Forward

```txt
Insert obstacle
Insert obstacle
Insert obstacle
...
```

### Reverse

Start with all obstacles already present.

Then while traversing backwards:

```txt
Remove obstacle
Remove obstacle
Remove obstacle
...
```

Removing obstacles is much easier because adjacent free segments merge into one larger segment.

This converts a dynamic splitting problem into a dynamic merging problem.

---

## Data Structures Used

### 1. Ordered Set

```cpp
set<pair<int,int>>
```

Stores:

```txt
(length_of_gap, left_boundary)
```

This helps quickly find gaps large enough for a block.

---

### 2. Neighbor Map

```cpp
map<int,pair<int,int>>
```

Stores:

```txt
obstacle -> {left_neighbor,right_neighbor}
```

Used while removing an obstacle and merging intervals.

---

## Algorithm

### Initialization

Collect:

```txt
0
50001
all obstacle positions
```

Sort them.

These positions divide the number line into free segments.

---

### Build Initial Segments

For every adjacent pair:

```txt
[a,b]
```

Store gap:

```txt
(b-a, a)
```

inside the set.

---

### Process Queries Backwards

---

### Type 1 Query

Remove obstacle.

Suppose:

```txt
xL ---- x ---- xR
```

Before removal:

```txt
[xL,x]
[x,xR]
```

After removal:

```txt
[xL,xR]
```

Remove old gaps and insert merged gap.

---

### Type 2 Query

Need a segment of length at least:

```txt
sz
```

whose start position satisfies:

```txt
start + sz <= x
```

Search all candidate gaps with:

```txt
gap_length >= sz
```

If one satisfies the boundary condition:

```txt
can = true
```

otherwise:

```txt
false
```

---

## Complexity Analysis

Let:

```txt
Q = number of queries
```

### Time Complexity

Building:

```txt
O(Q log Q)
```

Each insertion/removal:

```txt
O(log Q)
```

Overall:

```txt
O(Q log Q)
```

---

### Space Complexity

```txt
O(Q)
```

for obstacles and interval storage.

---

## C++ Solution

```cpp
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& q) {

        vector<bool> ans;
        int n = q.size();

        vector<int> bar;
        map<int,pair<int,int>> mpp;
        set<pair<int,int>> s;

        bar.push_back(0);
        bar.push_back(50001);

        for(int i = 0; i < n; ++i) {
            if(q[i][0] == 1)
                bar.push_back(q[i][1]);
        }

        sort(bar.begin(), bar.end());

        int sz = bar.size();

        mpp[bar[0]] = {bar[0], bar[1]};

        for(int i = 1; i < sz - 1; ++i)
            mpp[bar[i]] = {bar[i - 1], bar[i + 1]};

        mpp[bar[sz - 1]] = {bar[sz - 2], 0};

        for(int i = 0; i < sz - 1; ++i)
            s.insert({bar[i + 1] - bar[i], bar[i]});

        s.insert({0, bar[sz - 1]});

        for(int i = n - 1; i >= 0; --i) {

            if(q[i][0] == 1) {

                int x = q[i][1];

                int xL = mpp[x].first;
                int xR = mpp[x].second;

                s.erase({x - xL, xL});
                s.erase({xR - x, x});

                mpp[xL].second = xR;
                mpp[xR].first = xL;

                s.insert({xR - xL, xL});
            }
            else {

                int x = q[i][1];
                int dist = q[i][2];

                if(dist > x) {
                    ans.push_back(false);
                    continue;
                }

                auto it = s.lower_bound({dist, 0});

                bool can = false;

                for(; it != s.end(); ++it) {

                    if(dist + it->second <= x) {
                        can = true;
                        break;
                    }
                }

                ans.push_back(can);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
```

---

## Topics

- Ordered Set
- Reverse Queries
- Sweep Line
- Interval Merging
- Data Structures
- Hard Implementation

---

## Learnings

- Processing queries in reverse can simplify dynamic problems.
- Removing obstacles is often easier than inserting them.
- Ordered sets help maintain interval information efficiently.
- Dynamic interval merging is a common technique in hard query problems.
- Offline processing can convert difficult online operations into manageable updates.

---
