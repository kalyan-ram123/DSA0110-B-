#include <iostream>
#define LEGACY_PEAK_PERCENT 20
constexpr long long INNER_FARE_PAISE = 1000;
constexpr long long MIDDLE_FARE_PAISE = 2000;
constexpr long long OUTER_FARE_PAISE = 3000;
constexpr int MIN_REMAINING_PAISE = 5000;
enum class Zone { Inner, Middle, Outer };
int main() {
    const int peakPercent = LEGACY_PEAK_PERCENT;
    std::cout << INNER_FARE_PAISE << ' ' << MIDDLE_FARE_PAISE << ' ' << OUTER_FARE_PAISE
              << "\nPeak %: " << peakPercent << "\nMinimum paise: " << MIN_REMAINING_PAISE << '\n';
}