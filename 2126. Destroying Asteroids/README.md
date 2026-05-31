# 2126. Destroying Asteroids

## Problem Statement

You are given:

- An integer `mass` representing the initial mass of a planet.
- An array `asteroids` where `asteroids[i]` represents the mass of the `i-th` asteroid.

The planet can collide with asteroids in **any order**.

### Collision Rules

- If `planet_mass >= asteroid_mass`
  - The asteroid is destroyed.
  - Planet mass increases by asteroid mass.
- Otherwise
  - The planet is destroyed.

Return `true` if all asteroids can be destroyed, otherwise return `false`.

---

## Example 1

### Input

```txt
mass = 10
asteroids = [3,9,19,5,21]
```

### Output

```txt
true
```

### Explanation

Sort asteroids:

```txt
[3,5,9,19,21]
```

Process:

```txt
Mass = 10

10 >= 3  → Mass = 13
13 >= 5  → Mass = 18
18 >= 9  → Mass = 27
27 >= 19 → Mass = 46
46 >= 21 → Mass = 67
```

All asteroids are destroyed.

---

## Example 2

### Input

```txt
mass = 5
asteroids = [4,9,23,4]
```

### Output

```txt
false
```

### Explanation

Sort asteroids:

```txt
[4,4,9,23]
```

Process:

```txt
Mass = 5

5 >= 4  → Mass = 9
9 >= 4  → Mass = 13
13 >= 9 → Mass = 22
22 < 23 → Cannot destroy asteroid
```

Answer = false.

---

## Intuition

To maximize the planet's growth, we should always destroy the **smallest asteroid first**.

Why?

```txt
Destroy small asteroids →
Gain mass →
Become stronger →
Destroy larger asteroids later
```

If we fail on the smallest possible remaining asteroid, then no other ordering can help.

Therefore:

```txt
Sort asteroids in ascending order
```

and process them greedily.

---

## Approach

### Step 1

Sort the asteroid masses.

### Step 2

Maintain current planet mass.

```cpp
currentMass = mass
```

### Step 3

Traverse asteroids from smallest to largest.

If:

```cpp
currentMass < asteroid
```

return `false`.

Otherwise:

```cpp
currentMass += asteroid
```

### Step 4

If all asteroids are processed successfully, return `true`.

---

## Correctness Proof

Suppose we have two asteroids:

```txt
a ≤ b
```

Destroying `a` first always gives at least as much mass before facing `b` compared to destroying `b` first.

Therefore processing asteroids in increasing order never makes the situation worse.

Since the greedy order maximizes the planet's growth at every step:

- If greedy fails → no ordering can succeed.
- If greedy succeeds → all asteroids can be destroyed.

Hence the algorithm is correct.

---

## Complexity Analysis

### Time Complexity

Sorting:

```txt
O(n log n)
```

Traversal:

```txt
O(n)
```

Overall:

```txt
O(n log n)
```

---

### Space Complexity

Ignoring sorting space:

```txt
O(1)
```

---

## C++ Solution

```cpp
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        long long currentMass = mass;

        for (int asteroid : asteroids) {

            if (currentMass < asteroid) {
                return false;
            }

            currentMass += asteroid;
        }

        return true;
    }
};
```

---

## Topics

- Greedy
- Sorting
- Simulation
- Arrays

---

## Key Learning

- When gaining resources after every successful action, processing smaller requirements first is often optimal.
- Sorting can transform a difficult ordering problem into a simple greedy solution.
- Use `long long` because the planet's mass can grow beyond `10^5`.

---


