# 1345. Jump Game IV

## Problem Statement
Given an array of integers `arr`, you are initially positioned at the first index of the array.

In one step, you can jump from index `i` to:

- `i + 1` if `i + 1 < arr.length`
- `i - 1` if `i - 1 >= 0`
- Any index `j` where `arr[i] == arr[j]` and `i != j`

Return the minimum number of steps required to reach the last index.

---

## Example 1

### Input
```cpp
arr = [100,-23,-23,404,100,23,23,23,3,404]
```

### Output
```cpp
3
```

### Explanation
One shortest path is:

```cpp
0 -> 4 -> 3 -> 9
```

---

## Example 2

### Input
```cpp
arr = [7]
```

### Output
```cpp
0
```

---

## Example 3

### Input
```cpp
arr = [7,6,9,6,9,6,9,7]
```

### Output
```cpp
1
```

### Explanation
Jump directly from index `0` to index `7`.

---

## Approach

We use **Breadth First Search (BFS)** because we need the minimum number of jumps.

### Steps:
1. Store all indices of each value using a hashmap.
2. Start BFS from index `0`.
3. From each index:
   - Move to `i - 1`
   - Move to `i + 1`
   - Move to all indices having the same value
4. Use a visited array to avoid revisiting nodes.
5. Clear processed hashmap entries to prevent repeated work and TLE.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## C++ Solution

```cpp
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        vector<bool> vis(n,false);
        map<int,vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vis[0] = true;

        int cnt = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                int idx = q.front();
                q.pop();

                if(idx == n - 1) 
                    return cnt;

                if(idx - 1 >= 0 && !vis[idx - 1]){
                    q.push(idx - 1);
                    vis[idx - 1] = true;
                }

                if(idx + 1 < n && !vis[idx + 1]){
                    q.push(idx + 1);
                    vis[idx + 1] = true;
                }

                for(auto x : mp[arr[idx]]){
                    if(!vis[x]){
                        q.push(x);
                        vis[x] = true;
                    }
                }

                mp[arr[idx]].clear();
            }

            cnt++;
        }

        return -1;
    }
};
```

---

## Dry Run

### Input
```cpp
arr = [100,-23,-23,404,100,23,23,23,3,404]
```

### Steps

- Start at index `0`
- Same value jump:
  - `0 -> 4`
- From index `4`
  - Jump to `3`
- From index `3`
  - Same value jump to `9`

Reached last index in `3` steps.

---

## Key Learning

- BFS is ideal for shortest path problems in unweighted graphs.
- Hashmaps help optimize same-value jumps.
- Clearing processed vectors avoids redundant traversals and improves performance.

---

#️⃣ LeetCode Problem: 1345 - Jump Game IV
