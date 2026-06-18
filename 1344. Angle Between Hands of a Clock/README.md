# 1344. Angle Between Hands of a Clock

## Problem Statement

Given the current `hour` and `minutes` on an analog clock, return the **smaller angle** (in degrees) formed between the hour hand and the minute hand.

The answer is accepted if it is within `10^-5` of the actual value.

---

## Approach

To find the angle between the clock hands:

### Minute Hand

The minute hand completes:

```text
360° in 60 minutes
```

Therefore, each minute corresponds to:

```text
360 / 60 = 6°
```

So:

```cpp
minuteAngle = 6 × minutes
```

---

### Hour Hand

The hour hand completes:

```text
360° in 12 hours
```

Therefore, each hour corresponds to:

```text
360 / 12 = 30°
```

However, the hour hand also moves continuously as minutes pass.

For every minute:

```text
30 / 60 = 0.5°
```

So:

```cpp
hourAngle = 30 × (hour % 12) + 0.5 × minutes
```

---

### Angle Between Hands

Calculate the absolute difference:

```cpp
diff = abs(hourAngle - minuteAngle)
```

Since there are always two angles between the hands:

```text
diff
360 - diff
```

we return the smaller one:

```cpp
min(diff, 360 - diff)
```

---

## Algorithm

1. Calculate the angle of the minute hand.
2. Calculate the angle of the hour hand.
3. Find the absolute difference.
4. Return the smaller angle between:
   - `diff`
   - `360 - diff`

---

## Complexity Analysis

### Time Complexity

```text
O(1)
```

Only a few arithmetic operations are performed.

### Space Complexity

```text
O(1)
```

No extra space is used.

---

## C++ Solution

```cpp
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = 6.0 * minutes;
        double hourAngle = 30.0 * (hour % 12) + 0.5 * minutes;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360.0 - diff);
    }
};
```

---

## Example 1

### Input

```text
hour = 12
minutes = 30
```

### Calculation

Minute hand:

```text
30 × 6 = 180°
```

Hour hand:

```text
0 × 30 + 30 × 0.5
= 15°
```

Difference:

```text
|180 - 15| = 165°
```

Smaller angle:

```text
min(165, 195) = 165°
```

### Output

```text
165
```

---

## Example 2

### Input

```text
hour = 3
minutes = 30
```

### Calculation

Minute hand:

```text
30 × 6 = 180°
```

Hour hand:

```text
3 × 30 + 30 × 0.5
= 105°
```

Difference:

```text
|180 - 105| = 75°
```

### Output

```text
75
```

---

## Example 3

### Input

```text
hour = 3
minutes = 15
```

### Calculation

Minute hand:

```text
15 × 6 = 90°
```

Hour hand:

```text
3 × 30 + 15 × 0.5
= 97.5°
```

Difference:

```text
|97.5 - 90| = 7.5°
```

### Output

```text
7.5
```

---

## Key Insight

The tricky part is that the **hour hand is continuously moving**, not fixed at each hour mark.

For every minute passed, the hour hand advances:

```text
0.5°
```

Using this observation allows us to compute the exact angle directly in constant time.

---

⭐ If you found this solution helpful, consider giving the repository a star!
