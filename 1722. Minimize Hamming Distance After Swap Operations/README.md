# 🚀 1722. Minimize Hamming Distance After Swap Operations

## 🧩 Problem Statement
You are given two integer arrays `source` and `target` of equal length. You are also given `allowedSwaps`, where each pair `[a, b]` indicates that you can swap elements at indices `a` and `b` in `source`.

The **Hamming distance** is the number of indices `i` such that `source[i] != target[i]`.

## 🎯 Goal
Return the **minimum Hamming distance** after performing any number of allowed swaps.

## 🧪 Examples
Example 1: Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]] → Output: 1  
Example 2: Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = [] → Output: 2  
Example 3: Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]] → Output: 0  

## ⚙️ Approach (Union-Find / DSU)
- Use DSU to group indices that can be swapped.
- For each connected component:
  - Count frequencies of elements in `source`.
  - Match them with `target`.
  - Unmatched elements contribute to Hamming distance.

## 🧠 Algorithm
1. Initialize DSU  
2. Unite indices using allowedSwaps  
3. Group indices by parent  
4. For each group:
   - Count frequency of source values  
   - Match with target values  
   - Count mismatches  
5. Return total mismatches  

## 🧮 Complexity
Time: O(n log n) (almost O(n) with path compression)  
Space: O(n)

## 💻 C++ Solution
```cpp
class Solution {
public:
    vector<int> parent, rankv;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(rankv[a] < rankv[b]) swap(a,b);
        parent[b] = a;
        if(rankv[a] == rankv[b]) rankv[a]++;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++) parent[i] = i;

        for(auto &e : allowedSwaps){
            unite(e[0], e[1]);
        }

        unordered_map<int, vector<int>> groups;
        for(int i=0;i<n;i++){
            groups[find(i)].push_back(i);
        }

        int ans = 0;

        for(auto &[p, idxs] : groups){
            unordered_map<int,int> freq;

            for(int i : idxs) freq[source[i]]++;

            for(int i : idxs){
                if(freq[target[i]] > 0)
                    freq[target[i]]--;
                else
                    ans++;
            }
        }

        return ans;
    }
};
