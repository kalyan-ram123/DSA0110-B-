#include <iostream>
enum class Zone { Inner, Middle, Outer };
constexpr long long FARES[] = {1000, 2000, 3000};
constexpr long long MIN_REMAINING = 5000;
bool isPeak(int h) { return (h >= 8 && h < 10) || (h >= 17 && h < 20); }
long long fare(Zone z, int hour) {
    const auto index = static_cast<int>(z);
    if (index < 0 || index >= 3 || hour < 0 || hour > 23) return -1;
    long long value = FARES[index];
    if (isPeak(hour)) value += value * 20 / 100;
    return value;
}
int main() {
    const long long f = fare(Zone::Outer, 18);
    const long long startingBalance = 10000;
    std::cout << "Recommended integer-paise fare: " << f << '\n'
              << "Can travel: " << std::boolalpha << (f >= 0 && startingBalance - f >= MIN_REMAINING) << '\n'
              << "Time per fare: O(1); extra space: O(1)\n";
}
