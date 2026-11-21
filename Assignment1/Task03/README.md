# Task 3 — Choose Data Types and Check Compatibility

The implementation prints platform sizes and limits. On the verified g++ 14.2.0 x86-64 environment, `sizeof(bool/int/long long/double)` is 1/4/8/8 bytes. The signed 32-bit int range is -2,147,483,648 to 2,147,483,647; long long has a much larger range.

Money is represented as integer paise. Three million ₹36 fares total 10,800,000,000 paise, which exceeds INT_MAX, so a 32-bit int is insufficient for the network total. long long is appropriate.

The precision experiment adds ₹0.10 one million times using double. The measured result is ₹100000.0000013329 rather than exactly ₹100000.0000000000, an error of approximately ₹0.0000013329. Integer accumulation gives exactly 10,000,000 paise. Addition is O(1) for both types; each value uses O(1) storage. Floating point is useful for approximate scientific values, not exact currency.
