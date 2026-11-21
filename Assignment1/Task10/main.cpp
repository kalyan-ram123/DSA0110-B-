#include <climits>
#include <iomanip>
#include <iostream>
int main() {
    const long long farePaise = 3600;
    const long long counts[] = {20000, 500000, 3000000};
    for (long long n : counts) {
        const long long exactPaise = farePaise * n;
        double rupees = 0.0;
        for (long long i = 0; i < n; ++i) rupees += 36.0;
        const double differencePaise = rupees * 100.0 - static_cast<double>(exactPaise);
        std::cout << n << " journeys: integer paise=" << exactPaise
                  << ", double rupees=" << std::fixed << std::setprecision(2) << rupees
                  << ", difference in paise=" << std::setprecision(6) << differencePaise
                  << ", int-safe? " << (exactPaise <= INT_MAX ? "yes" : "no") << '\n';
    }
    std::cout << "INT_MAX=" << INT_MAX << ", LLONG_MAX=" << LLONG_MAX << '\n';
}
