# 3635. Earliest Finish Time for Land and Water Rides II

## Problem Statement
You are given two categories of theme park attractions:

- **Land Rides**
  - `landStartTime[i]` → Earliest time the ride can be boarded.
  - `landDuration[i]` → Duration of the ride.

- **Water Rides**
  - `waterStartTime[j]` → Earliest time the ride can be boarded.
  - `waterDuration[j]` → Duration of the ride.

A tourist must experience **exactly one land ride and one water ride**, in any order.

A ride can be started at its opening time or any later moment. After completing one ride, the tourist may immediately board the other ride if it is already open, otherwise they must wait.

Return the earliest possible time at which both rides can be completed.

---

## Approach

The key observation is that for a chosen order (Land → Water):

- We only care about the **earliest finishing land ride**.
- Let:

```text
minFinish = min(landStartTime[i] + landDuration[i])
```

This represents the earliest time we can finish any land ride.

For every water ride:

- If it is already open when we finish the land ride, we start immediately.
- Otherwise, we wait until it opens.

So the finishing time becomes:

```text
max(waterStartTime[i], minFinish) + waterDuration[i]
```

We compute the minimum among all water rides.

Since rides can also be taken in reverse order (Water → Land), we perform the same process again after swapping the land and water arrays.

The smallest answer from both directions is the result.

---

## Algorithm

1. Find the earliest finishing ride in the first category.
2. For every ride in the second category:
   - Start at `max(openTime, earliestFinish)`.
   - Compute final finish time.
3. Update the minimum answer.
4. Swap land and water rides.
5. Repeat the same process.
6. Return the minimum finish time found.

---

## Complexity Analysis

- Finding minimum finish time: **O(N)**
- Checking all rides of the other category: **O(M)**
- Repeating for reverse order: **O(N + M)**

### Time Complexity
```text
O(N + M)
```

### Space Complexity
```text
O(1)
```

---

## C++ Solution

```cpp
class Solution {
public:

void getAns(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration ,int &ans)
{
        int minFinish = INT_MAX;
    
        for(int i = 0 ; i<landStartTime.size() ; i++)
            minFinish = min(minFinish , landStartTime[i] + landDuration[i]);

        for(int i = 0 ; i<waterStartTime.size() ; i++)
            ans = min(ans ,max( waterStartTime[i] , minFinish) + waterDuration[i]);
}

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        

        int ans = INT_MAX;

        getAns(landStartTime, landDuration, waterStartTime, waterDuration , ans);

        swap(landStartTime,waterStartTime);
        swap(landDuration, waterDuration);

        getAns(landStartTime, landDuration, waterStartTime, waterDuration , ans);

        return ans;
    }
};
```

---

## Example

### Input

```text
landStartTime = [2,8]
landDuration  = [4,1]

waterStartTime = [6]
waterDuration  = [3]
```

### Calculation

Earliest land ride finish:

```text
min(2+4, 8+1) = 6
```

Water ride:

```text
max(6,6) + 3 = 9
```

Reverse order gives a larger value.

### Output

```text
9
```

---

### Key Insight

Instead of checking every possible land-water pair, we only need the **earliest finishing ride from the first category**. This reduces the problem to a simple linear scan and gives an optimal **O(N + M)** solution.

⭐ LeetCode 3635 | Greedy | Linear Scan | O(N + M)
