#include <iostream>
using namespace std;
struct Parcel { double weightKg; bool express; bool insured; };
double charge(double weightKg, bool express = false, bool insured = false) {
    double total = weightKg * 50.0;
    if (express) total += 40.0;
    if (insured) total += 25.0;
    return total;
}
double charge(int weightGrams) { return charge(weightGrams / 1000.0); }
double charge(const Parcel& p) { return charge(p.weightKg, p.express, p.insured); }
int main() {
    cout << "charge(2): " << charge(2) << '\n';
    cout << "charge(2.0): " << charge(2.0) << '\n';
    cout << "charge(2.0f): " << charge(2.0f) << '\n';
    cout << "charge(2000): " << charge(2000) << '\n';
    cout << "charge(2,true): " << charge(2.0, true) << '\n';
    Parcel p{2.0, true, true}; cout << "charge(Parcel): " << charge(p) << '\n';
}