#include <climits>
#include <iomanip>
#include <iostream>
int main() {
    std::cout << "sizeof(bool/int/long long/double): " << sizeof(bool) << '/' << sizeof(int)
              << '/' << sizeof(long long) << '/' << sizeof(double) << '\n';
    std::cout << "INT_MIN..INT_MAX: " << INT_MIN << ".." << INT_MAX << "\nLLONG_MAX: " << LLONG_MAX << '\n';
    const long long farePaise = 3600, journeys = 3000000, totalPaise = farePaise * journeys;
    std::cout << "Network total paise: " << totalPaise << " (int-safe? " << (totalPaise <= INT_MAX ? "yes" : "no") << ")\n";
    double sum = 0.0;
    for (int i = 0; i < 1000000; ++i) sum += 0.10;
    const long long exactPaise = 1000000LL * 10;
    std::cout << std::fixed << std::setprecision(10) << "Double sum of 1,000,000 x Rs 0.10: " << sum << '\n';
    std::cout << "Exact integer-paise sum in rupees: " << static_cast<double>(exactPaise) / 100.0 << '\n';
    std::cout << "Difference in rupees: " << sum - static_cast<double>(exactPaise) / 100.0 << '\n';
}
