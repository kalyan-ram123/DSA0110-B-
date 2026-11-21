# Task 7

Procedural and class-based versions both run in O(1) time and use O(1) balance storage. Private balance plus canTravel/deduct prevents callers from bypassing the minimum-balance invariant. A public balance member uses the same memory and speed but allows accidental or malicious negative balances.

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

See `main.cpp` for the executable example. Capture terminal output after local execution for submission evidence.
