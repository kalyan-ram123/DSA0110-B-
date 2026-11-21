# Task 9 — Implement and Test Fare Logic

The test-driven implementation validates hour range and zone before calculating fare. It covers Inner, Middle and Outer off-peak fares, all four boundary times, an unknown zone, and an invalid hour. See `output.txt`: **9/9 fare cases pass**.

The five-journey hand calculation is 1,000 + 2,400 + 2,000 + 3,600 + 3,000 = 12,000 paise (₹120.00). A negative recharge of -500 paise is rejected and the balance remains unchanged. Invalid text input is demonstrated in Task 8 by entering `abc` followed by `18`; the stream error is cleared and the bad line discarded before retry.

A table-driven test loop takes O(t) time and O(t) test-data space for t cases.
