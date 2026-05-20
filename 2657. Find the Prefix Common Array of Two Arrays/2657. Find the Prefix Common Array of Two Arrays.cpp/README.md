# 2657. Find the Prefix Common Array of Two Arrays

## Problem Statement
You are given two 0-indexed integer permutations `A` and `B` of length `n`.

A prefix common array of `A` and `B` is an array `C` such that:

```cpp
C[i] = count of numbers present in both A[0...i] and B[0...i]
```

Return the prefix common array of `A` and `B`.

---

## Example 1

### Input
```cpp
A = [1,3,2,4]
B = [3,1,2,4]
```

### Output
```cpp
[0,2,3,4]
```

### Explanation

- At `i = 0`:
  - A prefix = `[1]`
  - B prefix = `[3]`
  - No common numbers → `0`

- At `i = 1`:
  - Common numbers = `{1,3}` → `2`

- At `i = 2`:
  - Common numbers = `{1,2,3}` → `3`

- At `i = 3`:
  - Common numbers = `{1,2,3,4}` → `4`

---

## Example 2

### Input
```cpp
A = [2,3,1]
B = [3,1,2]
```

### Output
```cpp
[0,1,3]
```

---

## Approach

We use a frequency array to track occurrences of numbers in both arrays.

### Steps
1. Create a frequency array `freq`.
2. Traverse both arrays simultaneously.
3. Increase frequency for:
   - `A[i]`
   - `B[i]`
4. Whenever frequency becomes `2`, it means the number has appeared in both arrays.
5. Store the current common count in the answer array.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

---

## C++ Solution

```cpp
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> freq(n + 1, 0);
        vector<int> ans(n);

        int count = 0;

        for(int i = 0; i < n; i++) {

            freq[A[i]]++;
            if(freq[A[i]] == 2)
                count++;

            freq[B[i]]++;
            if(freq[B[i]] == 2)
                count++;

            ans[i] = count;
        }

        return ans;
    }
};
```

---

## Dry Run

### Input
```cpp
A = [1,3,2,4]
B = [3,1,2,4]
```

### Iteration 1 (`i = 0`)
```cpp
freq[1] = 1
freq[3] = 1
count = 0
ans[0] = 0
```

### Iteration 2 (`i = 1`)
```cpp
freq[3] = 2 -> count = 1
freq[1] = 2 -> count = 2
ans[1] = 2
```

### Iteration 3 (`i = 2`)
```cpp
freq[2] = 2 -> count = 3
ans[2] = 3
```

### Iteration 4 (`i = 3`)
```cpp
freq[4] = 2 -> count = 4
ans[3] = 4
```

Final Answer:
```cpp
[0,2,3,4]
```

---

## Key Learning

- Frequency counting is useful for tracking shared elements efficiently.
- When frequency becomes `2`, the element has appeared in both arrays.
- Since arrays are permutations, each element appears only once in each array.

---

#️⃣ LeetCode Problem: 2657 - Find the Prefix Common Array of Two Arrays
