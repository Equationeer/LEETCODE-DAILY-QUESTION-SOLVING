# 3043. Find the Length of the Longest Common Prefix

## Problem Statement
You are given two arrays of positive integers `arr1` and `arr2`.

A prefix of an integer is formed by taking one or more digits from the left side of the number.

You need to find the maximum length of a common prefix between any pair `(x, y)` such that:

- `x` belongs to `arr1`
- `y` belongs to `arr2`

Return the length of the longest common prefix.  
If no common prefix exists, return `0`.

---

## Example 1

### Input
```cpp
arr1 = [1,10,100]
arr2 = [1000]
```

### Output
```cpp
3
```

### Explanation

Common prefixes:
- `(1,1000)` → `1`
- `(10,1000)` → `10`
- `(100,1000)` → `100`

Longest common prefix = `100`  
Length = `3`

---

## Example 2

### Input
```cpp
arr1 = [1,2,3]
arr2 = [4,4,4]
```

### Output
```cpp
0
```

### Explanation
No common prefix exists.

---

## Approach

### Idea
Store all prefixes of numbers from `arr1` in a hash set.

Then for every number in `arr2`:
- Keep removing digits from the end
- Check whether the current prefix exists in the set
- Track the maximum prefix length

---

## Complexity Analysis

- **Time Complexity:** `O(total digits)`
- **Space Complexity:** `O(total prefixes)`

---

## C++ Solution

```cpp
class Solution {
public:
    int digits(int x) {
        int cnt = 0;

        while(x > 0) {
            cnt++;
            x /= 10;
        }

        return cnt;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> prefixes;

        for(int num : arr1) {

            int x = num;

            while(x > 0) {
                prefixes.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        for(int num : arr2) {

            int x = num;
            int len = digits(num);

            while(x > 0) {

                if(prefixes.count(x)) {
                    ans = max(ans, len);
                    break;
                }

                x /= 10;
                len--;
            }
        }

        return ans;
    }
};
```

---

## Dry Run

### Input
```cpp
arr1 = [1,10,100]
arr2 = [1000]
```

### Step 1: Store Prefixes of arr1

For `1`:
```cpp
1
```

For `10`:
```cpp
10, 1
```

For `100`:
```cpp
100, 10, 1
```

Set:
```cpp
{1,10,100}
```

---

### Step 2: Check arr2

For `1000`:
```cpp
1000 -> not found
100  -> found
```

Length of `100` = `3`

Answer = `3`

---

## Key Learning

- Prefix problems can often be solved using hashing.
- Removing digits from the right helps generate prefixes efficiently.
- Hash sets provide fast lookup in `O(1)` average time.

---

#️⃣ LeetCode Problem: 3043 - Find the Length of the Longest Common Prefix
