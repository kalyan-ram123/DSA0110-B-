# Task 2

Tokens include keywords (constexpr, enum), identifiers (INNER_FARE_PAISE), constants (1000), operators (+, =), and punctuators ({}, ;). Prefer constexpr for compile-time fare values and enum class for scoped, type-safe zones. #define has no type or scope and performs textual substitution; runtime complexity is unchanged.

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

See `main.cpp` for the executable example. Capture terminal output after local execution for submission evidence.
