# Task 1

Objects: SmartCard owns the balance and validates deductions; Journey stores trip facts; FareTable owns pricing policy; Passenger represents concession eligibility; Zone is a finite domain. Encapsulation protects the invariant that a successful trip leaves at least 5,000 paise. A procedural design has equivalent O(1) time and O(1) state per card, but shared state can be modified from unrelated functions. OOP localizes rule changes.

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

See `main.cpp` for the executable example. Capture terminal output after local execution for submission evidence.
