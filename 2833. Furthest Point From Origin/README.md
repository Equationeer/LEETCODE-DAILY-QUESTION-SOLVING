# 🚀 2833. Furthest Point From Origin

## 🟢 Difficulty
Easy

---

## 🧠 Problem Statement

You are given a string `moves` consisting of:
- `'L'` → move left
- `'R'` → move right
- `'_'` → can move either left or right

Starting from position `0`, return the **maximum distance from origin** you can achieve after all moves.

---

## ✨ Examples

### Example 1:
```
Input: moves = "L_RL__R"
Output: 3
```

### Example 2:
```
Input: moves = "_R__LL_"
Output: 5
```

### Example 3:
```
Input: moves = "_______"
Output: 7
```

---

## 💡 Approach

### 🔑 Key Idea:
- Count:
  - `left` → number of 'L'
  - `right` → number of 'R'
  - `blank` → number of '_'

### 🧠 Logic:
- Current displacement = `|left - right|`
- Use all `'_'` moves to **maximize distance in one direction**

👉 Final Answer:
```
abs(left - right) + blank
```

---

## 🧾 Code (C++)

```cpp
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;

        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L') left++;
            else if(moves[i] == 'R') right++;
            else blank++;
        }

        return abs(left - right) + blank;
    }
};
```

---

## 📊 Complexity Analysis

### ⏱ Time Complexity:
- O(n)

### 🧠 Space Complexity:
- O(1)

---

## 🎯 Key Insight

👉 Always use `'_'` moves to push further in the dominant direction (left or right).

---

## ✅ Conclusion

- Simple counting problem
- Greedy approach works perfectly
- Clean and optimal solution 🚀

---

## 📌 Tags
- Greedy
- String
- Simulation

---

🔥 If this helped, give a ⭐ to your repo!
