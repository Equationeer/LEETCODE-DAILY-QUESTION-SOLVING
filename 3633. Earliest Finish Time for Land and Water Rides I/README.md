# 3633. Earliest Finish Time for Land and Water Rides I

## 🚀 Problem Overview
A tourist must experience exactly **one land ride** and **one water ride**, in any order.

Each ride has:
- **Start Time** → Earliest time the ride can be boarded.
- **Duration** → Time required to complete the ride.

A ride can start at its opening time or any later time. After completing one ride, the tourist can immediately take the other ride if it is open, otherwise wait until it opens.

The goal is to find the **earliest possible finishing time** after completing one ride from each category.

---

## 💡 Approach

### Key Observation
Instead of checking every possible pair of rides, we first compute:

- `minLandEnd` = Earliest possible completion time among all land rides.
- `minWaterEnd` = Earliest possible completion time among all water rides.

Then evaluate:

### 1️⃣ Land Ride → Water Ride
For every water ride:
- If the water ride opens before the earliest land completion time, we must wait until land ride finishes.
- Finish Time = `minLandEnd + waterDuration[i]`
- Otherwise:
- Finish Time = `waterStartTime[i] + waterDuration[i]`

### 2️⃣ Water Ride → Land Ride
Similarly for every land ride:
- If the land ride opens before the earliest water completion time, we start after finishing the water ride.
- Finish Time = `minWaterEnd + landDuration[i]`
- Otherwise:
- Finish Time = `landStartTime[i] + landDuration[i]`

The minimum among all possible finish times is the answer.

---

## 🔍 Example

### Input
```cpp
landStartTime = [2,8]
landDuration  = [4,1]

waterStartTime = [6]
waterDuration  = [3]
```

### Calculation

#### Earliest Land Completion
- Ride 0 → 2 + 4 = 6
- Ride 1 → 8 + 1 = 9

`minLandEnd = 6`

#### Earliest Water Completion
- Ride 0 → 6 + 3 = 9

`minWaterEnd = 9`

#### Land → Water
- Water ride opens at 6
- Finish = 6 + 3 = 9

#### Water → Land
- Land ride 0 finishes at 13
- Land ride 1 finishes at 10

Minimum = **9**

### Output
```cpp
9
```

---

## ✅ Complexity Analysis

- Finding minimum land completion: **O(n)**
- Finding minimum water completion: **O(m)**
- Evaluating all rides: **O(n + m)**

### Time Complexity
```cpp
O(n + m)
```

### Space Complexity
```cpp
O(1)
```

---

## 💻 Solution

```cpp
class Solution {
public:
    static int earliestFinishTime(vector<int>& landStartTime,
                                  vector<int>& landDuration,
                                  vector<int>& waterStartTime,
                                  vector<int>& waterDuration) {
        const int n = landStartTime.size();
        const int m = waterStartTime.size();

        int minLandEnd = 1e6;
        int minWaterEnd = 1e6;

        for (int i = 0; i < n; i++) {
            minLandEnd = min(minLandEnd,
                             landStartTime[i] + landDuration[i]);
        }

        for (int i = 0; i < m; i++) {
            minWaterEnd = min(minWaterEnd,
                              waterStartTime[i] + waterDuration[i]);
        }

        int ans = 1e9;

        for (int i = 0; i < m; i++) {
            if (waterStartTime[i] < minLandEnd)
                ans = min(ans, minLandEnd + waterDuration[i]);
            else
                ans = min(ans,
                          waterStartTime[i] + waterDuration[i]);
        }

        for (int i = 0; i < n; i++) {
            if (landStartTime[i] < minWaterEnd)
                ans = min(ans, minWaterEnd + landDuration[i]);
            else
                ans = min(ans,
                          landStartTime[i] + landDuration[i]);
        }

        return ans;
    }
};
```

---
⭐ **LeetCode 3633 | Easy**
📅 Daily Challenge Completed
🔥 Optimized Solution using Greedy Observation (O(n + m))
