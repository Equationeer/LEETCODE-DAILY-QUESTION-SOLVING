# 3614. Process String with Special Operations II

## Problem Statement

You are given a string `s` consisting of:

- Lowercase English letters (`a-z`)
- Special characters:
  - `'*'` → Remove the last character from the current string.
  - `'#'` → Duplicate the current string.
  - `'%'` → Reverse the current string.

You process the string from left to right to build a final result string.

Instead of constructing the potentially huge final string (length up to `10^15`), return the character at index `k`.

If `k` is outside the final string, return `'.'`.

---

## Approach

Constructing the final string directly is impossible because its length can grow up to:

```text
10^15
```

So we use a **reverse simulation** approach.

### Key Idea

First compute only the length of the resulting string after each operation.

Let:

```cpp
len[i]
```

represent the length of the string after processing `s[0...i]`.

Then, starting from the end of the operations, trace where the required index `k` came from.

---

## Forward Pass (Length Tracking)

For each character:

### Letter

```cpp
cur++
```

Adds one character.

### '*'

```cpp
if(cur > 0) cur--;
```

Deletes the last character.

### '#'

```cpp
cur *= 2;
```

Duplicates the current string.

### '%'

```cpp
length remains unchanged
```

Only reverses the string.

Store every length in:

```cpp
len[i]
```

---

## Reverse Simulation

Starting from the last operation and moving backwards:

### Case 1: Letter

Suppose before adding the letter:

```text
length = before
```

After adding:

```text
length = before + 1
```

If:

```cpp
k == before
```

then this letter is exactly the answer.

---

### Case 2: '*'

Deletion only removes the last character.

When moving backwards, no index transformation is needed.

---

### Case 3: '#'

Before duplication:

```text
ABC
```

After duplication:

```text
ABCABC
```

Length becomes:

```text
2 × before
```

If:

```cpp
k >= before
```

then the character belongs to the second copy.

Map it back:

```cpp
k -= before;
```

---

### Case 4: '%'

Before:

```text
ABCDE
```

After:

```text
EDCBA
```

If current length is:

```cpp
after
```

then:

```cpp
k = after - 1 - k;
```

maps the index back to the original string.

---

## Algorithm

### Step 1

Compute resulting lengths after every operation.

### Step 2

If:

```cpp
k >= finalLength
```

return:

```cpp
'.'
```

### Step 3

Traverse operations backwards.

### Step 4

Undo each operation's effect on index `k`.

### Step 5

When a letter position matches `k`, return that letter.

---

## Complexity Analysis

### Time Complexity

```text
O(n)
```

- One forward pass
- One backward pass

### Space Complexity

```text
O(n)
```

For storing prefix lengths.

---

## C++ Solution

```cpp
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if ('a' <= c && c <= 'z') {
                cur++;
            }
            else if (c == '*') {
                if (cur > 0) cur--;
            }
            else if (c == '#') {
                cur *= 2;
            }
            else { // '%'
                // length unchanged
            }

            len[i] = cur;
        }

        if (k >= cur) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];

            long long before = (i == 0 ? 0 : len[i - 1]);
            long long after = len[i];

            if ('a' <= c && c <= 'z') {
                if (k == before) {
                    return c;
                }
            }
            else if (c == '*') {
                continue;
            }
            else if (c == '#') {
                if (k >= before) {
                    k -= before;
                }
            }
            else { // '%'
                k = after - 1 - k;
            }
        }

        return '.';
    }
};
```

---

## Example 1

### Input

```text
s = "a#b%*"
k = 1
```

### Processing

```text
"a"
"aa"
"aab"
"baa"
"ba"
```

Final string:

```text
"ba"
```

Index:

```text
0 -> b
1 -> a
```

### Output

```text
'a'
```

---

## Example 2

### Input

```text
s = "cd%#*#"
k = 3
```

### Processing

```text
"c"
"cd"
"dc"
"dcdc"
"dcd"
"dcddcd"
```

### Output

```text
'd'
```

---

## Key Insight

Instead of building a string of size up to:

```text
10^15
```

we only store lengths and work backwards to locate the origin of index `k`.

This transforms an impossible simulation into an efficient:

```text
Time  : O(n)
Space : O(n)
```

solution.

---

⭐ If you found this solution helpful, consider giving the repository a star!
