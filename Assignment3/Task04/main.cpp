#include <iomanip>
#include <iostream>
using namespace std;

class Money {
    long long paise;
public:
    Money(long long rupees = 0, int p = 0) : paise(rupees * 100 + p) {}
    explicit Money(long long totalPaise, bool) : paise(totalPaise) {}
    Money operator+(const Money& other) const { return Money(paise + other.paise, true); }
    Money operator-(const Money& other) const { return Money(paise - other.paise, true); }
    Money& operator+=(const Money& other) { paise += other.paise; return *this; }
    bool operator==(const Money& other) const { return paise == other.paise; }
    bool operator<(const Money& other) const { return paise < other.paise; }
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long magnitude = m.paise < 0 ? -m.paise : m.paise;
        if (m.paise < 0) out << "-";
        return out << "Rs " << magnitude / 100 << '.' << setw(2) << setfill('0')
                   << magnitude % 100 << setfill(' ');
    }
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees; int p;
        if (in >> rupees >> p) m.paise = rupees * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    cout << c << '\n' << boolalpha << (c == Money(200)) << '\n';
    cout << Money(0, 75) + Money(0, 50) << '\n';
    cout << Money(1, 0) - Money(2, 25) << '\n';
    Money bill(10, 0); bill += Money(5, 50);
    cout << "Bill: " << bill << '\n';
}