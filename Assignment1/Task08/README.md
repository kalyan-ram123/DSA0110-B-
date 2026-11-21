# Task 8

cin extraction must be checked; on failure call clear() and ignore through newline before retrying. fixed and setprecision(2) format rupees. getline plus stoi also processes a line in O(L) time and O(L) buffer space, and try/catch can report malformed text; stream extraction is convenient for token-based input.

## Build and run

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

See `main.cpp` for the executable example. Capture terminal output after local execution for submission evidence.
