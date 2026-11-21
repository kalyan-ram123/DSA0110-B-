# Task 4 — Control Implicit Conversions

**Predicted output, written before execution**

```text
3 3.5
C 68
1 true
s >= u
```

**Observed output:** matches the prediction exactly; see `output.txt`.

- `a / b` is integer division, so 7 / 2 becomes 3 before assignment to double.
- `static_cast<double>(a) / b` converts the left operand before division and produces 3.5.
- `'A' + 2` is evaluated as an integer expression, then converted to char for initialization. In `ch + 1`, char undergoes integral promotion, giving 68.
- Integer 5 converts to bool true. `boolalpha` changes its printed representation from 1 to true.
- In `s < u`, the signed int is converted to unsigned int under the usual arithmetic conversions. -1 becomes a large unsigned value, so the comparison is false. g++ warns about comparing signed and unsigned values.

Brace initialization such as `int count{3.7};` is rejected because it narrows. Explicit casts make intended conversions visible. These conversions do not change the O(1) time or O(1) storage of this short program.
