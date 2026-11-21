# Task 6 — Control Structures and Completed Code

## SIMATS-style pseudocode

```text
ALGORITHM CalculateMetroFare
INPUT zone, hour, balance
IF hour is outside 0..23 THEN
    OUTPUT invalid time
    STOP
END IF
peak ← (8 <= hour < 10) OR (17 <= hour < 20)
SWITCH zone
    CASE Inner: baseFare ← 1000
    CASE Middle: baseFare ← 2000
    CASE Outer: baseFare ← 3000
    DEFAULT: OUTPUT invalid zone; STOP
END SWITCH
fare ← baseFare
IF peak THEN
    fare ← baseFare + (baseFare * 20 / 100)
END IF
IF balance - fare >= 5000 THEN
    balance ← balance - fare
    OUTPUT fare and balance
ELSE
    OUTPUT journey denied; balance unchanged
END IF
END ALGORITHM
```

The C++ program completes both TODOs using a switch and integer paise. The expected three journeys produce ₹10.00, ₹36.00, and then a denial with ₹54 remaining. The added checks confirm 10:00 and 20:00 are not peak.

Use switch for the finite zone choices, if/else for range and eligibility conditions, range-for for a known collection of trips, while for retrying unknown-count input, and continue to skip invalid records. A missing switch case falls through to the statement after the switch unless a default handles it.

A constexpr array lookup is also O(1), with O(z) storage for z zones; extending a fourth zone requires adding an entry and enum value.
