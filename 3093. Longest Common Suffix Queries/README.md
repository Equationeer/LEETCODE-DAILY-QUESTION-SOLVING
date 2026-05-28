# 3093. Longest Common Suffix Queries

## Problem Statement

You are given two string arrays:

- `wordsContainer`
- `wordsQuery`

For each query string, find the index of the string in `wordsContainer` that shares the **longest common suffix**.

If multiple strings have the same suffix length:

1. Choose the string with the **smallest length**
2. If still tied, choose the string with the **smallest index**

Return an array containing the answer for every query.

---

## Example

### Example 1

Input:
```txt
wordsContainer = ["abcd","bcd","xbcd"]
wordsQuery = ["cd","bcd","xyz"]
```

Output:
```txt
[1,1,1]
```

Explanation:

- `"cd"` matches suffix `"cd"` with all strings
- `"bcd"` has the smallest length among valid matches
- Index of `"bcd"` is `1`

---

## Approach

### Key Observation

Suffix problems can be converted into prefix problems by:

```txt
Reversing all strings
```

Example:

```txt
"abcd" -> "dcba"
```

Now longest common suffix becomes longest common prefix.

---

## Data Structure Used

### Trie

We build a Trie using reversed strings.

Each Trie node stores:

- Children links
- Best index according to:
  - Smaller string length
  - Smaller index if lengths are equal

---

## Algorithm

### Build Trie

For every word in `wordsContainer`:

1. Reverse the word
2. Insert into Trie
3. Update best index at every node

### Query Processing

For every query:

1. Reverse query
2. Traverse Trie while characters match
3. Return stored best index

---

## Complexity Analysis

### Time Complexity

```txt
O(total characters in wordsContainer + total characters in wordsQuery)
```

### Space Complexity

```txt
O(total characters in wordsContainer)
```

---

## C++ Solution

```cpp
class Solution {
public:

    struct Node {
        int child[26];
        int idx;

        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    void updateIndex(int &storedIdx, int newIdx,
                     vector<string>& wordsContainer) {

        if(storedIdx == -1) {
            storedIdx = newIdx;
            return;
        }

        int oldLen = wordsContainer[storedIdx].size();
        int newLen = wordsContainer[newIdx].size();

        if(newLen < oldLen) {
            storedIdx = newIdx;
        }
        else if(newLen == oldLen && newIdx < storedIdx) {
            storedIdx = newIdx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(Node());

        for(int i = 0; i < wordsContainer.size(); i++) {

            string word = wordsContainer[i];
            reverse(word.begin(), word.end());

            int node = 0;

            updateIndex(trie[node].idx, i, wordsContainer);

            for(char ch : word) {

                int c = ch - 'a';

                if(trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.push_back(Node());
                }

                node = trie[node].child[c];

                updateIndex(trie[node].idx, i, wordsContainer);
            }
        }

        vector<int> ans;

        for(string query : wordsQuery) {

            reverse(query.begin(), query.end());

            int node = 0;

            for(char ch : query) {

                int c = ch - 'a';

                if(trie[node].child[c] == -1) {
                    break;
                }

                node = trie[node].child[c];
            }

            ans.push_back(trie[node].idx);
        }

        return ans;
    }
};
```

---

## Topics

- Trie
- Strings
- Prefix Matching
- Suffix Matching
- Hashing

---

## Learnings

- Convert suffix problems into prefix problems using reversal
- Efficient Trie construction
- Maintaining optimal candidate at Trie nodes
- String searching optimization

---
