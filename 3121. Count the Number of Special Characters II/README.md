# 3121. Count the Number of Special Characters II

## Problem Statement
You are given a string `word`.

A letter `c` is called **special** if:

- It appears in both lowercase and uppercase forms in `word`
- Every lowercase occurrence appears before the first uppercase occurrence

Return the number of special characters in the string.

---

## Example

### Example 1
Input:
```txt
word = "aaAbcBC"
```

Output:
```txt
3
```

Explanation:
```txt
'a', 'b', and 'c' are special characters.
```

---

## Approach

We store:

- The last occurrence of every lowercase letter
- The first occurrence of every uppercase letter

A character is special if:

```txt
last lowercase index < first uppercase index
```

---

## Algorithm

1. Create two arrays:
   - `low[26]` → stores last lowercase index
   - `upper[26]` → stores first uppercase index

2. Traverse the string:
   - Update lowercase positions
   - Store only first uppercase occurrence

3. Check all 26 characters:
   - If both lowercase and uppercase exist
   - And lowercase occurs before uppercase
   - Count it

---

## Complexity Analysis

### Time Complexity
```txt
O(n)
```

### Space Complexity
```txt
O(1)
```

---

## C++ Solution

```cpp
class Solution {
public:
    int numberOfSpecialChars(string word) {

        vector<int> upper(26, -1);
        vector<int> low(26, -1);

        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            if(ch >= 'a' && ch <= 'z') {

                low[ch - 'a'] = i;
            }
            else {

                if(upper[ch - 'A'] == -1) {
                    upper[ch - 'A'] = i;
                }
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(low[i] != -1 && upper[i] != -1) {

                if(low[i] < upper[i]) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

---

## Topics
- Strings
- Arrays
- Hashing

---

## Learnings
- Tracking first and last occurrence
- Character indexing using ASCII
- Efficient string traversal
- Case handling in strings

---
