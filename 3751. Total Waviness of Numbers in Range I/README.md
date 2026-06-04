# Total Waviness of Numbers

## Problem Statement

Given two integers `num1` and `num2`, calculate the **total waviness** of all numbers in the range `[num1, num2]`.

The **waviness** of a number is defined as the count of digits that are either:

- Strictly greater than both adjacent digits (local maximum), or
- Strictly smaller than both adjacent digits (local minimum).

Only digits with both a left and right neighbor are considered.

---

## Approach

For every number in the range:

1. Convert the number into a string.
2. Traverse all middle digits.
3. Check whether the current digit forms:
   - A local peak (`digit > left && digit > right`), or
   - A local valley (`digit < left && digit < right`).
4. Count such positions as the number's waviness.
5. Add the waviness of every number to the final answer.

---

## Algorithm

1. Create a helper function `waviness(x)`:
   - Convert `x` to a string.
   - Count all local maxima and minima.
   - Return the count.
2. Iterate from `num1` to `num2`.
3. Sum the waviness of every number.
4. Return the total.

---

## Complexity Analysis

Let:

- `N = num2 - num1 + 1`
- `D = number of digits`

### Time Complexity

```text
O(N × D)
```

### Space Complexity

```text
O(D)
```

---

## C++ Solution

```cpp
class Solution {
public:
    int waviness(int x) {
        string s = to_string(x);

        int cnt = 0;

        for (int i = 1; i < (int)s.size() - 1; i++) {
            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        long long ans = 0;

        for (int x = num1; x <= num2; x++) {
            ans += waviness(x);
        }

        return ans;
    }
};
```

---

## Example

### Input

```text
num1 = 120
num2 = 123
```

### Waviness

```text
120 -> 1
121 -> 1
122 -> 0
123 -> 0
```

### Output

```text
2
```

---

### Key Insight

A digit contributes to waviness only when it forms a **peak** or **valley** with its immediate neighbors. By checking every middle digit of every number in the range, we can directly compute the total waviness.
