#include <iostream>
enum class Zone { Inner, Middle, Outer };
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long p) : balance_(p < 0 ? 0 : p) {}
    bool canTravel(long long fare) const { return fare >= 0 && balance_ - fare >= 5000; }
    bool deduct(long long fare) { if (!canTravel(fare)) return false; balance_ -= fare; return true; }
    long long balance() const { return balance_; }
};
long long baseFare(Zone z) {
    switch (z) { case Zone::Inner: return 1000; case Zone::Middle: return 2000; case Zone::Outer: return 3000; }
    return 0;
}
int main() {
    SmartCard card(10000);
    const long long fare = baseFare(Zone::Outer);
    std::cout << "Fare paise: " << fare << "\nAccepted: " << std::boolalpha << card.deduct(fare)
              << "\nBalance paise: " << card.balance() << '\n';
}