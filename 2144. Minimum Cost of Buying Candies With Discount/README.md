# 2144. Minimum Cost of Buying Candies With Discount

## Problem Statement

A candy shop offers the following discount:

> For every **two candies you buy**, you can get **one additional candy for free**.

The free candy must have a cost less than or equal to the cheaper of the two purchased candies.

Given an array `cost`, where `cost[i]` represents the price of the `i-th` candy, return the **minimum total cost** required to buy all candies.

---

## Example 1

### Input

```text
cost = [1,2,3]
```

### Output

```text
5
```

### Explanation

Sort in descending order:

```text
[3,2,1]
```

Buy:

```text
3 and 2
```

Get:

```text
1 for free
```

Total:

```text
3 + 2 = 5
```

---

## Example 2

### Input

```text
cost = [6,5,7,9,2,2]
```

### Output

```text
23
```

### Explanation

Sort descending:

```text
[9,7,6,5,2,2]
```

Group into triples:

```text
(9,7,6)
(5,2,2)
```

For each group:

```text
Pay: 9 + 7
Free: 6

Pay: 5 + 2
Free: 2
```

Total:

```text
9 + 7 + 5 + 2 = 23
```

---

## Example 3

### Input

```text
cost = [5,5]
```

### Output

```text
10
```

### Explanation

Only two candies exist.

```text
Pay 5 + 5
```

No free candy available.

Total:

```text
10
```

---

## Intuition

To maximize the discount:

- The most expensive candies should be purchased.
- The third most expensive candy should be taken for free.

Therefore:

```text
Sort candies in descending order.
```

For every group of 3 candies:

```text
Pay for first candy
Pay for second candy
Get third candy free
```

This maximizes the value of the free candy.

---

## Greedy Observation

Suppose we have:

```text
9 7 6
```

Best choice:

```text
Buy 9 and 7
Get 6 free
```

Instead of:

```text
Buy 9 and 6
Get 7 free ❌
```

which is not allowed because:

```text
7 > min(9,6)
```

Hence sorting and taking every third candy free is optimal.

---

## Approach

### Step 1

Sort the array in ascending order.

```cpp
sort(cost.begin(), cost.end());
```

---

### Step 2

Traverse from the end (largest candies).

Every 3 candies:

```text
Pay largest
Pay second largest
Skip third largest (free)
```

---

### Step 3

Accumulate the paid candies.

---

## Dry Run

### Input

```text
cost = [6,5,7,9,2,2]
```

After sorting:

```text
[2,2,5,6,7,9]
```

Traverse from end:

```text
i = 5 → add 9 + 7
skip 6

i = 2 → add 5 + 2
skip 2
```

Total:

```text
9 + 7 + 5 + 2 = 23
```

---

## Correctness Proof

After sorting:

```text
c1 ≥ c2 ≥ c3 ≥ c4 ≥ ...
```

For every three candies:

```text
c1, c2, c3
```

The maximum valid free candy is:

```text
c3
```

because:

```text
c3 ≤ c2
```

Thus paying for:

```text
c1 + c2
```

and taking:

```text
c3
```

gives the maximum possible discount.

Applying this greedily to every triple yields the minimum total cost.

Therefore the algorithm is correct.

---

## Complexity Analysis

### Time Complexity

Sorting:

```text
O(n log n)
```

Traversal:

```text
O(n)
```

Overall:

```text
O(n log n)
```

---

### Space Complexity

```text
O(1)
```

Ignoring sorting space.

---

## C++ Solution

```cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int total = 0;

        for (int i = cost.size() - 1; i >= 0; i -= 3) {
            total += cost[i];

            if (i - 1 >= 0)
                total += cost[i - 1];
        }

        return total;
    }
};
```

---

## Topics

- Greedy
- Sorting
- Arrays

---

## Key Learning

- When every third item can be free, maximize the free item's value.
- Sorting often reveals the optimal greedy strategy.
- Grouping elements in triples is enough to achieve the best discount.
- Always try to make the most expensive eligible candy the free one.

---

## Similar Problems

- 455. Assign Cookies
- 881. Boats to Save People
- 948. Bag of Tokens
- 2126. Destroying Asteroids
- 1833. Maximum Ice Cream Bars

These problems also rely on greedy decisions after sorting.

---
