#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Prescription {
    int n;
    string* medicines;
public:
    explicit Prescription(int count) : n(max(0, count)), medicines(n ? new string[n] : nullptr) {}
    Prescription(const Prescription& other)
        : n(other.n), medicines(n ? new string[n] : nullptr) {
        for (int i = 0; i < n; ++i) medicines[i] = other.medicines[i];
    }
    Prescription& operator=(const Prescription& other) {
        if (this != &other) {
            string* fresh = other.n ? new string[other.n] : nullptr;
            for (int i = 0; i < other.n; ++i) fresh[i] = other.medicines[i];
            delete[] medicines;
            medicines = fresh;
            n = other.n;
        }
        return *this;
    }
    ~Prescription() { delete[] medicines; }
    void set(int i, const string& medicine) {
        if (i >= 0 && i < n) medicines[i] = medicine;
    }
    string get(int i) const { return (i >= 0 && i < n) ? medicines[i] : ""; }
};

int main() {
    Prescription p(2);
    p.set(0, "Paracetamol"); p.set(1, "ORS");
    Prescription q = p;
    q.set(1, "Cetirizine");
    Prescription r(1);
    r = p;
    p.set(0, "Ibuprofen");
    cout << p.get(0) << ' ' << p.get(1) << " | "
         << q.get(0) << ' ' << q.get(1) << " | "
         << r.get(0) << ' ' << r.get(1) << '\n';
    r = r;
    cout << "Self-assignment safe: " << r.get(0) << '\n';
}