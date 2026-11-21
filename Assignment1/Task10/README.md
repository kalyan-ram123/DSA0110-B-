# Task 10 — Compare Expectations with Execution

The program compares exact integer-paise totals with repeated double-rupee additions for 20,000, 500,000 and 3,000,000 journeys at ₹36 per journey. Observed difference is 0.000000 paise at the displayed precision for these selected values; ₹36.00 is exactly representable in binary floating point and these totals remain below double's exact-integer limit.

| Journeys | Exact total (paise) | Total (rupees) | Difference (paise) | Signed 32-bit int can hold paise? |
|---:|---:|---:|---:|---|
| 20,000 | 72,000,000 | ₹720,000.00 | 0 | Yes |
| 500,000 | 1,800,000,000 | ₹18,000,000.00 | 0 | Yes |
| 3,000,000 | 10,800,000,000 | ₹108,000,000.00 | 0 | No |

At 3,000,000 journeys the paise total exceeds INT_MAX=2,147,483,647. Do not perform signed int overflow; it is undefined behaviour. long long safely holds this total. Double is not a general exact-money representation: Task 3's repeated ₹0.10 experiment demonstrates a small accumulated error. Each addition is O(1); each accumulator uses O(1) space. The signed/unsigned comparison warning from Task 4 is recorded in that task's output log.
