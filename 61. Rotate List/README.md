# 61. Rotate List

## Problem

Given the head of a linked list, rotate the list to the right by `k` places.

---

## Example

### Input
```cpp
head = [1,2,3,4,5], k = 2
```

### Output
```cpp
[4,5,1,2,3]
```

---

### Input
```cpp
head = [0,1,2], k = 4
```

### Output
```cpp
[2,0,1]
```

---

## Approach

### Key Idea

Rotate the list by breaking it into two parts and reconnecting.

---

## Steps

1. **Handle Edge Cases**
   - If list is empty or has one node → return as it is

2. **Find Length of Linked List**
   - Traverse once to count nodes

3. **Optimize k**
   ```
   k = k % length
   ```
   - If `k == 0`, return head

4. **Find New Break Point**
   - Move to `(length - k)`-th node

5. **Break the List**
   - Cut after `(length - k)` node

6. **Reconnect**
   - Attach last part to front

---

## C++ Solution

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;

        if(head == nullptr || head->next == nullptr)
            return head;

        while(temp) {
            count++;
            temp = temp->next;
        }

        k = k % count;
        if(k == 0)
            return head;

        count -= k;

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(count--) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = nullptr;

        ListNode* tail = curr;
        while(tail->next) {
            tail = tail->next;
        }

        tail->next = head;
        head = curr;

        return head;
    }
};
```

---

## Complexity Analysis

### Time Complexity
**O(n)**  
- One pass to count  
- One pass to split  
- One pass to find tail  

---

### Space Complexity
**O(1)**

---

## Key Insight

Instead of rotating one by one:
- Find the **cut point directly**
- Reconnect efficiently

---

## Alternative Optimization

You can also:
- Make the list **circular**
- Break at the right position

(This reduces traversal slightly)

---

## Tags

- Linked List
- Two Pointer
- Simulation

---

## LeetCode

Problem Link: https://leetcode.com/problems/rotate-list/

---

## Status

✅ Solved  
⚡ Optimal O(n) solution used
