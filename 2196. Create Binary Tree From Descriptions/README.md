# 2196. Create Binary Tree From Descriptions

## Problem Statement

You are given a 2D integer array `descriptions` where:

- `descriptions[i] = [parent, child, isLeft]`
- `parent` is the parent of `child`
- If `isLeft = 1`, then `child` is the left child of `parent`
- If `isLeft = 0`, then `child` is the right child of `parent`

Construct the binary tree described by the given relationships and return its root node.

---

## Approach

We use:

- An `unordered_map<int, TreeNode*>` to create and store all tree nodes.
- An `unordered_set<int>` to track every node that appears as a child.

### Key Idea

In a valid binary tree:

- Every node except the root appears as a child exactly once.
- The root never appears as a child.

So after building the tree, the node that is not present in the child set is the root.

---

## Algorithm

1. Traverse all descriptions.
2. Create parent and child nodes if they do not already exist.
3. Connect the child node to the parent node based on `isLeft`.
4. Insert every child value into a set.
5. Iterate through all nodes and find the one that never appeared as a child.
6. Return that node as the root.

---

## Complexity Analysis

### Time Complexity

**O(n)**

- Each description is processed exactly once.

### Space Complexity

**O(n)**

- Hash map stores all nodes.
- Hash set stores all child nodes.

---

## C++ Solution

```cpp
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childNodes;

        for (auto &d : descriptions) {
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            if (mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);

            if (mp.find(child) == mp.end())
                mp[child] = new TreeNode(child);

            if (isLeft)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            childNodes.insert(child);
        }

        for (auto &p : mp) {
            if (childNodes.find(p.first) == childNodes.end())
                return p.second;
        }

        return nullptr;
    }
};
```

---

## Example

### Input

```text
descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
```

### Constructed Tree

```text
        50
       /  \
      20   80
     / \   /
    15 17 19
```

### Output

```text
[50,20,80,15,17,19]
```

---

## Key Insight

Instead of trying to identify the root during tree construction, simply record every child node. After building the tree, the only node that never appears as a child is the root.

---
⭐ If you found this solution helpful, consider giving the repository a star!
