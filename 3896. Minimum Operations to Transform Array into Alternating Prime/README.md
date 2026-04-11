# 3896. Minimum Operations to Transform Array into Alternating Prime

**Platform:** LeetCode  
**Difficulty:** Medium  
**Language Used:** C++  
**Time Complexity:** O(n * sqrt(max(nums[i])))  
**Space Complexity:** O(1)

---

## Problem Summary

You are given an integer array `nums`.

An array is called **alternating prime** if:
- Elements at **even indices (0-based)** are **prime**
- Elements at **odd indices** are **non-prime**

In one operation, you can **increment any element by 1**.

Return the **minimum number of operations** required to convert the array into an alternating prime array.

---

## Key Observation

- For **even indices** → number must be **prime**
- For **odd indices** → number must be **non-prime**

If a number does not satisfy the condition:
- Keep incrementing it until it becomes valid
- Count the number of increments

---

## Approach

1. Traverse the array:
2. For each index `i`:
   
   ### Case 1: Even Index (i % 2 == 0)
   - If number is already prime → continue
   - Else:
     - Increment until it becomes prime
     - Count operations

   ### Case 2: Odd Index (i % 2 == 1)
   - If number is already non-prime → continue
   - Else:
     - Increment until it becomes non-prime
     - Count operations

3. Return total operations

---

## Helper Function

Check if a number is prime:

- If `num <= 1` → not prime  
- Check divisibility from `2` to `sqrt(num)`

---

## Complexity Analysis

- **Time Complexity:** O(n * sqrt(max(nums[i])))  
  - Each prime check takes √n  
  - In worst case, multiple increments per element  

- **Space Complexity:** O(1)  
  - No extra space used  

---

## C++ Implementation

```cpp
class Solution {
public:
    bool isprime(int num){
        if(num <= 1) return false;

        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0){
                if(isprime(nums[i])) continue;

                int no = nums[i];
                while(!isprime(no)){
                    no++;
                    ops++;
                }
            }
            else{
                if(!isprime(nums[i])) continue;

                int no = nums[i];
                while(isprime(no)){
                    no++;
                    ops++;
                }
            }
        }

        return ops;
    }
};
