# Task 11 — Recommend and Defend the Final Design

Recommend `enum class` for zones, `constexpr` fare constants, integer paise, `long long` aggregates, a private SmartCard balance, and centralized peak/fare functions. Per-journey calculation is O(1), batch processing is O(n), and memory per card is O(1). A configuration file would add O(z) startup reads and O(z) storage but avoid recompilation for fare revisions. Compile-time constants are simpler and type-checked. Limitations include policy changes requiring a rebuild and concession percentages not specified in the assignment prompt.

## Build

`g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main && ./main`
