# Assignment 1 Report — Namma Metro Smart-Card Fare System

**Student:** Fardeen Khan F  
**Register:** 192421289  
**Repository:** https://github.com/KingKhan007-git/Cpp/tree/main/Assignment1

## 1. Design summary

Use `enum class Zone`, `constexpr` fare constants, integer paise, `long long` for balances and network totals, and a `SmartCard` with a private balance. Peak windows are half-open: 08:00 ≤ time < 10:00 and 17:00 ≤ time < 20:00. A successful stored-value trip leaves at least 5,000 paise.

## 2. Object model (UML-style)

```text
+---------------------+       +--------------------+
| Passenger           |       | Journey            |
+---------------------+       +--------------------+
| passengerId         |       | originZone         |
| passengerType       |       | destinationZone    |
+---------------------+       | journeyHour        |
| concessionPolicy()  |       +--------------------+
+---------------------+                 |
                                        v
+---------------------+       +--------------------+
| SmartCard           |------>| FareTable          |
+---------------------+       +--------------------+
| - balancePaise      |       | + baseFare(zone)   |
+---------------------+       | + calculate(...)   |
| + canTravel(fare)   |       +--------------------+
| + deduct(fare)      |
| + recharge(amount)  |       Zone: Inner, Middle,
+---------------------+             Outer
```

The card owns and protects its balance invariant. The fare table owns policy. Journey groups trip inputs. Passenger identifies concession eligibility. The supplied brief does not specify concession rates, so they remain a policy input rather than an invented numeric rule.

## 3. Data types and constants

| Value | Recommended type | Reason |
|---|---|---|
| Fare and balance | `long long` paise | Exact whole-paise arithmetic; supports network aggregates |
| Zone | `enum class Zone` | Finite, scoped set of values |
| Hour | `int` | Simple range 0–23 |
| Peak/pass flags | `bool` | True/false state |
| Journey count | `long long` | Avoids 32-bit aggregate overflow |
| Approximate measurement | `double` | Used only for precision comparison |

On the verified g++ 14.2.0 x86-64 environment, bool/int/long long/double sizes are 1/4/8/8 bytes. Three million ₹36 fares total 10,800,000,000 paise, exceeding signed 32-bit INT_MAX. A repeated one-million-addition experiment with ₹0.10 demonstrates double accumulation error of approximately ₹0.0000013329.

## 4. Output predictions (written before execution)

Task 4 prediction:

```text
3 3.5
C 68
1 true
s >= u
```

Task 5 prediction:

```text
11 16
9 6 4
6 4
3 1 -3 -1
18
```

Both predictions match the observed output in their respective `output.txt` files.

## 5. SIMATS-style fare pseudocode

```text
ALGORITHM CalculateMetroFare
INPUT zone, hour, balance
IF hour is outside 0..23 THEN OUTPUT invalid time; STOP
peak ← (8 <= hour < 10) OR (17 <= hour < 20)
SWITCH zone
  Inner: baseFare ← 1000
  Middle: baseFare ← 2000
  Outer: baseFare ← 3000
  DEFAULT: OUTPUT invalid zone; STOP
END SWITCH
fare ← baseFare
IF peak THEN fare ← baseFare + baseFare * 20 / 100
IF balance - fare >= 5000 THEN
  balance ← balance - fare
  OUTPUT fare and balance
ELSE
  OUTPUT denied; leave balance unchanged
END IF
END ALGORITHM
```

## 6. Validation summary

- Task 6 reproduced the required three-journey output: ₹10.00, ₹36.00, then denied with ₹54 remaining.
- Task 6 boundary checks show 10:00 and 20:00 are off-peak.
- Task 8 invalid text input (`abc`) was rejected; after clearing the stream and discarding the bad line, valid hour 18 was accepted.
- Task 9 fare test table passed 9/9 cases, including all four peak boundaries, unknown zone and invalid hour.
- Task 9 negative recharge was rejected and the balance remained unchanged.
- Task 10 exact aggregate totals were compared with repeated double additions for 20,000, 500,000 and 3,000,000 journeys. At the selected ₹36 fare, the displayed difference is zero; Task 3 separately demonstrates double precision loss with repeated ₹0.10.
- Task 12 test output: Airport weekday peak 7,200 paise; Airport weekend 5,400 paise; covered monthly-pass trip zero; uncovered Outer off-peak trip 3,000 paise.

## 7. Complexity

Fare calculation, eligibility checks, card deduction and fixed-zone lookup are O(1) time and O(1) extra space. Processing n journeys is O(n). A table-driven test suite with t cases is O(t) time and O(t) test-data space. Configuration-based fare loading takes O(z) startup time and O(z) storage for z zones. The monthly pass stores O(z) coverage flags.

## 8. Important assumptions and specification gaps

The assignment says students and senior citizens receive a concession but gives no concession percentages or order of application. No percentage is invented. Task 12 does not define pass expiry, renewal, transferability or whether a pass is bound to a passenger/card; these require clarification. The weekend discount is interpreted as 10% of base fare and takes precedence over peak surcharge, so the two are not combined.

## 9. Submission evidence status

All 12 task programs were compiled locally with g++ 14.2.0 using `-std=c++17 -Wall -Wextra -pedantic` and executed. Each task folder contains its source, explanation and `output.txt` captured from execution. These are text logs, **not screenshots**. Before classroom submission, save genuine terminal screenshots for each task in the matching folder; do not mislabel the text logs as screenshots.
