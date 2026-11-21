#include <climits>
#include <iostream>
enum class Zone { Inner, Middle, Outer, Invalid };
long long calculateFare(Zone zone, int hour) {
    if (hour < 0 || hour > 23) return -1;
    long long base = 0;
    switch (zone) {
        case Zone::Inner: base = 1000; break;
        case Zone::Middle: base = 2000; break;
        case Zone::Outer: base = 3000; break;
        default: return -1;
    }
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? base * 120 / 100 : base;
}
bool recharge(long long& balance, long long amount) {
    if (amount < 0 || balance > LLONG_MAX - amount) return false;
    balance += amount;
    return true;
}
int main() {
    struct Test { const char* name; Zone zone; int hour; long long expected; };
    const Test tests[] = {
        {"Inner off-peak", Zone::Inner, 11, 1000}, {"Middle off-peak", Zone::Middle, 11, 2000},
        {"Outer off-peak", Zone::Outer, 11, 3000}, {"Inner 08:00", Zone::Inner, 8, 1200},
        {"Inner 10:00", Zone::Inner, 10, 1000}, {"Inner 17:00", Zone::Inner, 17, 1200},
        {"Inner 20:00", Zone::Inner, 20, 1000}, {"Unknown zone", Zone::Invalid, 12, -1},
        {"Invalid hour", Zone::Inner, 24, -1}
    };
    int passed = 0;
    for (const auto& t : tests) {
        const long long actual = calculateFare(t.zone, t.hour);
        const bool ok = actual == t.expected; passed += ok;
        std::cout << t.name << ": expected=" << t.expected << " actual=" << actual << " " << (ok ? "PASS" : "FAIL") << '\n';
    }
    std::cout << "Fare tests passed: " << passed << '/' << (sizeof(tests) / sizeof(tests[0])) << '\n';
    long long balance = 10000;
    const bool accepted = recharge(balance, -500);
    std::cout << "Negative recharge accepted? " << std::boolalpha << accepted
              << "; balance unchanged? " << (balance == 10000) << '\n';
    std::cout << "Five-trip hand total paise: " << 1000 + 2400 + 2000 + 3600 + 3000 << '\n';
}
