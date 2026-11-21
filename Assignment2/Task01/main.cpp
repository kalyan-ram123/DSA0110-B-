#include <iostream>
using namespace std;
void concessionByValue(long long fee, int percent) { fee -= fee * percent / 100; }
void concessionByReference(long long& fee, int percent) { fee -= fee * percent / 100; }
void concessionByPointer(long long* fee, int percent) { if (fee) *fee -= *fee * percent / 100; }
void change(int a, int& b, int* c) { a += 10; b += 10; *c += 10; }
int& bigger(int& p, int& q) { return p > q ? p : q; }
void show(int x, int y = 5, int z = 10) { cout << x + y + z << ' '; }
int main() {
    long long f1 = 45000, f2 = 45000, f3 = 45000;
    concessionByValue(f1, 10); concessionByReference(f2, 10); concessionByPointer(&f3, 15);
    cout << "Value: " << f1 << "\nReference: " << f2 << "\nPointer: " << f3 << '\n';
    int a = 1, b = 2, c = 3; change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';
    bigger(a, c) = 100; cout << a << ' ' << c << '\n';
    show(1); show(1, 2); show(1, 2, 3); cout << '\n';
}