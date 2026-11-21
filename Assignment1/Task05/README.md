# Task 5 — Operators and Precedence

**Predicted output, written before execution**

```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

**Observed output:** matches the prediction exactly; see `output.txt`.

- Multiplication has higher precedence than addition: 5 + 3*2 = 11. Parentheses force (5+3)*2 = 16.
- `x++` yields the old x (5) and then increments it; `++y` increments y to 4 before yielding it. Their sum is 9; x=6 and y=4. The operands modify different objects, so this expression is well-defined.
- The conditional operator selects max(6,4)=6. Multiplication and remainder have equal precedence and associate left-to-right: (6%4)*2=4.
- Integer division truncates toward zero: -10/3=-3. The remainder has the dividend's sign: -10%3=-1.
- The loop adds 0+3+6+9=18.

Do not write `i = i++`: it attempts to assign back a value while relying on a modification of the same scalar object in an unhelpful, error-prone way; use `i++` or `++i` as a standalone increment instead. The peak expression is `(hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)`. A 24-entry bool lookup table also gives O(1) checks but uses 24 bool elements.
