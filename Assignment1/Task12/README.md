# Task 12 — Re-evaluate and Adapt the Design

**Decision: MODIFY the original design.** Add Airport to the scoped zone enum and fare table (₹60). Separate weekend discount from peak surcharge; weekend has precedence and the two do not combine. Add a `MonthlyPass` that stores two covered zones and returns zero fare for covered journeys.

The original switch can be extended with Airport, but a four-entry `constexpr std::array` is easier to maintain as zones grow. `SmartCard` can remain responsible for stored value; pass entitlement is a separate policy object. Example results: Airport weekday peak = 7,200 paise; Airport weekend = 5,400 paise; covered pass journey = 0; uncovered Outer off-peak = 3,000 paise.

Assumptions forced by missing specification: weekend discount is 10% of base fare; pass validity period, renewal, transferability, and interaction with concessions are not defined and require product decisions. Fare and coverage lookup are O(1); pass storage is O(z), fixed at four zones here.

## Build

`g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main && ./main`
