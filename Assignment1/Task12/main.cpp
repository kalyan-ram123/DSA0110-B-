#include <array>
#include <cstddef>
#include <iostream>
enum class Zone { Inner, Middle, Outer, Airport };
constexpr std::array<long long, 4> BASE_FARE = {1000, 2000, 3000, 6000};
class MonthlyPass {
    std::array<bool, 4> covered_{};
public:
    MonthlyPass(Zone first, Zone second) {
        covered_[static_cast<std::size_t>(first)] = true;
        covered_[static_cast<std::size_t>(second)] = true;
    }
    bool covers(Zone z) const { return covered_[static_cast<std::size_t>(z)]; }
};
long long calculateFare(Zone z, int hour, bool weekend, const MonthlyPass* pass) {
    const auto index = static_cast<std::size_t>(z);
    if (index >= BASE_FARE.size() || hour < 0 || hour > 23) return -1;
    if (pass && pass->covers(z)) return 0;
    long long amount = BASE_FARE[index];
    if (weekend) amount = amount * 90 / 100;
    else if ((hour >= 8 && hour < 10) || (hour >= 17 && hour < 20)) amount = amount * 120 / 100;
    return amount;
}
int main() {
    MonthlyPass pass(Zone::Inner, Zone::Middle);
    std::cout << "Airport weekday peak: " << calculateFare(Zone::Airport, 18, false, nullptr) << " paise\n";
    std::cout << "Airport weekend: " << calculateFare(Zone::Airport, 18, true, nullptr) << " paise\n";
    std::cout << "Covered-zone pass trip: " << calculateFare(Zone::Inner, 9, false, &pass) << " paise\n";
    std::cout << "Uncovered-zone trip: " << calculateFare(Zone::Outer, 12, false, &pass) << " paise\n";
}
