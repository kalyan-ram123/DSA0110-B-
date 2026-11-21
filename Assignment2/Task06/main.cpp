#include <iostream>
#include <chrono>
using namespace std;
class Time {
    int h, m;
public:
    Time(int hh, int mm) : h(hh), m(mm) {}
    friend inline int minutesBetween(const Time& a, const Time& b);
    friend inline bool earlier(const Time& a, const Time& b);
};
inline int minutesBetween(const Time& a, const Time& b) {
    int x = a.h * 60 + a.m, y = b.h * 60 + b.m;
    return (x > y) ? x - y : y - x;
}
inline bool earlier(const Time& a, const Time& b) { return a.h * 60 + a.m < b.h * 60 + b.m; }
int main() {
    Time departure(9, 45), arrival(13, 10);
    cout << minutesBetween(departure, arrival) << ' ' << boolalpha << earlier(arrival, departure) << '\n';
    Time beforeNoon(11, 59), afterNoon(12, 1);
    cout << minutesBetween(beforeNoon, afterNoon) << ' ' << earlier(beforeNoon, afterNoon) << '\n';
    Time same(10, 30); cout << minutesBetween(same, same) << ' ' << earlier(same, same) << '\n';
    volatile int total = 0;
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < 10000000; ++i) total += minutesBetween(departure, arrival);
    auto end = chrono::steady_clock::now();
    cout << "Checksum: " << total << "\nTime (ns): "
         << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << '\n';
}