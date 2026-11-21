#include <iostream>
constexpr long long MINIMUM = 5000;
bool proceduralCanTravel(long long balance, long long fare) { return fare >= 0 && balance - fare >= MINIMUM; }
bool proceduralDeduct(long long& balance, long long fare) { if (!proceduralCanTravel(balance, fare)) return false; balance -= fare; return true; }
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long balance) : balance_(balance < 0 ? 0 : balance) {}
    bool canTravel(long long fare) const { return fare >= 0 && balance_ - fare >= MINIMUM; }
    bool deduct(long long fare) { if (!canTravel(fare)) return false; balance_ -= fare; return true; }
    long long balance() const { return balance_; }
};
int main() {
    long long proceduralBalance = 10000;
    std::cout << "Procedural accepted: " << std::boolalpha << proceduralDeduct(proceduralBalance, 3000) << ", balance: " << proceduralBalance << '\n';
    SmartCard card(10000);
    std::cout << "OOP accepted: " << card.deduct(3000) << ", balance: " << card.balance() << '\n';
}
