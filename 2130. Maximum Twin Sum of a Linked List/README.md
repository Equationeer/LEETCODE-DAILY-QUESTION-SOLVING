# 2130. Maximum Twin Sum of a Linked List

## Problem Statement

In a linked list of even length `n`, the `i-th` node and the `(n - 1 - i)-th` node are called **twins**.

The **twin sum** of a pair is:

```text
node[i] + node[n-1-i]
```

Return the maximum twin sum among all twin pairs in the linked list.

---

## Approach

To efficiently find the maximum twin sum in **O(n)** time and **O(1)** extra space:

1. Use the **slow and fast pointer** technique to reach the middle of the linked list.
2. While finding the middle, simultaneously **reverse the first half** of the list.
3. After reaching the middle:
   - `prev` points to the reversed first half.
   - `slow` points to the beginning of the second half.
4. Traverse both halves together and compute the twin sums.
5. Keep track of the maximum twin sum.

---

## Algorithm

1. Initialize:
   - `slow = head`
   - `fast = head`
   - `prev = nullptr`
2. While `fast` and `fast->next` exist:
   - Move `fast` two steps ahead.
   - Reverse the current node of the first half.
3. After the loop:
   - First half is reversed.
   - `slow` points to the second half.
4. Compare nodes from:
   - Reversed first half (`left`)
   - Second half (`right`)
5. Update the maximum twin sum.
6. Return the maximum value.

---

## Complexity Analysis

### Time Complexity

**O(n)**

- One traversal to find the middle and reverse.
- One traversal to calculate twin sums.

### Space Complexity

**O(1)**

- No extra data structures are used.

---

## C++ Solution

```cpp
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;

        while (fast && fast->next) {
            fast = fast->next->next;

            ListNode* nxt = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nxt;
        }

        int ans = 0;
        ListNode *left = prev, *right = slow;

        while (left) {
            ans = max(ans, left->val + right->val);
            left = left->next;
            right = right->next;
        }

        return ans;
    }
};
```

---

## Example 1

### Input

```text
head = [5,4,2,1]
```

### Twin Pairs

```text
5 + 1 = 6
4 + 2 = 6
```

### Output

```text
6
```

---

## Example 2

### Input

```text
head = [4,2,2,3]
```

### Twin Pairs

```text
4 + 3 = 7
2 + 2 = 4
```

### Output

```text
7
```

---

## Example 3

### Input

```text
head = [1,100000]
```

### Twin Pair

```text
1 + 100000 = 100001
```

### Output

```text
100001
```

---

## Dry Run

### Input

```text
head = [5,4,2,1]
```

### Step 1: Reverse First Half

```text
Original:
5 -> 4 -> 2 -> 1

After reversing first half:
4 -> 5

Second half:
2 -> 1
```

### Step 2: Calculate Twin Sums

```text
4 + 2 = 6
5 + 1 = 6
```

### Maximum Twin Sum

```text
6
```

---

## Key Insight

Instead of storing all node values in an array, we can:

- Reverse the first half while finding the middle.
- Compare corresponding nodes directly.

This achieves:

```text
Time  : O(n)
Space : O(1)
```

which is the optimal solution.

---

⭐ If you found this solution helpful, consider giving the repository a star!
