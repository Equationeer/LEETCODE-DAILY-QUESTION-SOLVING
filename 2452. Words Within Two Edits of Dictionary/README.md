# 2452. Words Within Two Edits of Dictionary

## 🟡 Difficulty
Medium

---

## 🧠 Problem Statement

You are given two string arrays `queries` and `dictionary`. All words have the same length.

In **one edit**, you can change any character of a word to another character.

👉 Your task is to return all words from `queries` such that they can be converted into any word in `dictionary` using **at most 2 edits**.

---

## ✨ Examples

### Example 1:
```
Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
Output: ["word","note","wood"]
```

### Example 2:
```
Input: queries = ["yes"], dictionary = ["not"]
Output: []
```

---

## 💡 Approach

- For each word in `queries`, compare it with every word in `dictionary`.
- Count the number of different characters (Hamming Distance).
- If difference ≤ 2 → valid word.
- Add it to result and break early (optimization).

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        const int qz = queries.size(), sz = queries[0].size();

        for(int j = 0; j < qz; j++){
            const string& q = queries[j];

            for(const string& d : dictionary){
                int diff = 0;

                for(int i = 0; i < sz; i++){
                    diff += (q[i] != d[i]);
                    if(diff > 2) break;
                }

                if(diff <= 2){
                    ans.push_back(q);
                    break;
                }
            }
        }

        return ans;
    }
};
```

---

## 📊 Complexity Analysis

### ⏱ Time Complexity:
- O(Q × D × N)
  - Q = number of queries
  - D = number of dictionary words
  - N = length of each word

### 🧠 Space Complexity:
- O(1) (excluding output)

---

## 🎯 Key Insight

👉 This problem is essentially checking **Hamming Distance ≤ 2** between words.

---

## ✅ Conclusion

- Simple brute-force works because constraints are small.
- Early breaking when `diff > 2` optimizes performance.
- Clean and readable solution 👍

---

## 📌 Tags
- Strings
- Brute Force
- Simulation
- Hamming Distance

---

🔥 If you found this helpful, give a ⭐ to the repo!
