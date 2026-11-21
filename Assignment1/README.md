# Assignment 1 — Namma Metro Smart-Card Fare System

**Student:** Fardeen Khan F  
**Register Number:** 192421289  
**Repository:** https://github.com/KingKhan007-git/Cpp

This assignment implements and evaluates the fare logic described in the supplied 13-page assignment brief.

## Compiler and build command

Verified compiler: **g++ 14.2.0** (GNU C++), C++17 mode.

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

Run the command from the individual Task folder. Each task contains `main.cpp`, this task's `README.md`, and `output.txt` with the locally captured console output. Task 8's output was tested with invalid text followed by a valid hour.

## Task index

| Task | Topic | Folder |
|---|---|---|
| 1 | Problem analysis and OOP objects | [Task01](Task01/) |
| 2 | Tokens, identifiers and constants | [Task02](Task02/) |
| 3 | Data types and compatibility | [Task03](Task03/) |
| 4 | Implicit conversions and output prediction | [Task04](Task04/) |
| 5 | Operators, precedence and output prediction | [Task05](Task05/) |
| 6 | Control structures, pseudocode and completed TODOs | [Task06](Task06/) |
| 7 | Procedural vs OOP implementation | [Task07](Task07/) |
| 8 | Safe input and formatted output | [Task08](Task08/) |
| 9 | Fare implementation and test table | [Task09](Task09/) |
| 10 | Expected vs executed totals | [Task10](Task10/) |
| 11 | Final design recommendation | [Task11](Task11/) |
| 12 | Airport zone, weekend discount and monthly pass | [Task12](Task12/) |

## Important interpretation notes

- Peak periods are half-open intervals: 08:00–before 10:00 and 17:00–before 20:00. Thus 10:00 and 20:00 are off-peak.
- Fare and balance values use integer paise.
- The prompt says students and senior citizens receive concessions but does not state the concession rates or application order. No unsupported percentage is invented; those policy values must be supplied by the metro.
- For Task 12, the 10% weekend discount is applied to base fare and takes precedence over peak surcharge, as the brief says the two do not combine.
- Monthly-pass validity dates, renewal and transfer rules are not specified; these are identified as open requirements.

## Evidence status

All 12 task programs were compiled locally using the command above and executed. The output text files record the observed output. They are **text output logs, not screenshots**. Before final classroom submission, open each program in a terminal and save the required genuine terminal screenshot into the matching Task folder. The assignment's prediction tasks are documented as predictions separately from observed outputs.
