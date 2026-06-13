# 3838. Weighted Word Mapping

## Problem Statement

You are given:

- An array of strings `words`.
- An integer array `weights` of size `26`, where `weights[i]` represents the weight of the `i-th` lowercase English letter.

The weight of a word is the sum of the weights of all its characters.

For each word:

1. Calculate its total weight.
2. Take the result modulo `26`.
3. Map the value to a lowercase letter using reverse alphabetical order:

```text
0  -> z
1  -> y
2  -> x
...
25 -> a
```

Return the string formed by concatenating the mapped characters for all words.

---

## Approach

For every word:

1. Compute the sum of weights of its characters.
2. Calculate:

```cpp
value = sumWeight % 26;
```

3. Convert the value into the corresponding character using reverse alphabetical mapping:

```cpp
'z' - value
```

4. Append the character to the answer string.

---

## Algorithm

1. Initialize an empty string `result`.
2. Traverse each word in `words`.
3. For every character:
   - Add its corresponding weight from the `weights` array.
4. Compute:

```cpp
value = sumWeight % 26;
```

5. Map it to:

```cpp
char('z' - value)
```

6. Append the character to `result`.
7. Return `result`.

---

## Complexity Analysis

### Time Complexity

**O(N × M)**

Where:

- `N` = number of words
- `M` = average length of a word

Each character is processed exactly once.

### Space Complexity

**O(1)**

Ignoring the output string.

---

## C++ Solution

```cpp
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;

        for (const string& word : words) {
            int sumWeight = 0;

            for (char ch : word) {
                sumWeight += weights[ch - 'a'];
            }

            int value = sumWeight % 26;

            result.push_back(char('z' - value));
        }

        return result;
    }
};
```

---

## Example 1

### Input

```text
words = ["abcd","def","xyz"]

weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]
```

### Calculation

```text
"abcd" = 5 + 3 + 12 + 14 = 34
34 % 26 = 8
'z' - 8 = 'r'

"def" = 14 + 1 + 2 = 17
17 % 26 = 17
'z' - 17 = 'i'

"xyz" = 7 + 7 + 2 = 16
16 % 26 = 16
'z' - 16 = 'j'
```

### Output

```text
"rij"
```

---

## Example 2

### Input

```text
words = ["a","b","c"]

weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
```

### Calculation

```text
Weight of each word = 1

1 % 26 = 1

'z' - 1 = 'y'
```

### Output

```text
"yyy"
```

---

## Key Insight

The reverse alphabetical mapping can be performed directly using:

```cpp
char('z' - (sumWeight % 26))
```

This eliminates the need for any extra lookup table and keeps the solution simple and efficient.

---

⭐ If you found this solution helpful, consider giving the repository a star!
