#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
    double real, imag;
public:
    Complex() : real(0), imag(0) {}
    Complex(double r) : real(r), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}
    Complex operator+(const Complex& z) const { return {real + z.real, imag + z.imag}; }
    Complex operator-(const Complex& z) const { return {real - z.real, imag - z.imag}; }
    Complex operator*(const Complex& z) const {
        return {real * z.real - imag * z.imag, real * z.imag + imag * z.real};
    }
    Complex operator/(const Complex& z) const {
        double denominator = z.real * z.real + z.imag * z.imag;
        if (denominator == 0.0) throw domain_error("division by zero impedance");
        return {(real * z.real + imag * z.imag) / denominator,
                (imag * z.real - real * z.imag) / denominator};
    }
    bool operator==(const Complex& z) const { return real == z.real && imag == z.imag; }
    double magnitude() const { return hypot(real, imag); }
    friend ostream& operator<<(ostream& out, const Complex& z) {
        out << fixed << setprecision(3) << z.real;
        if (z.imag >= 0) out << '+';
        return out << z.imag << 'j';
    }
};

int main() {
    const double pi = acos(-1.0), frequency = 50.0, omega = 2.0 * pi * frequency;
    const double resistance = 100.0, inductance = 0.1, capacitance = 100e-6;
    Complex zr(resistance, 0.0);
    Complex zl(0.0, omega * inductance);
    Complex zc(0.0, -1.0 / (omega * capacitance));
    Complex series = zr + zl + zc;
    Complex parallel = (zr * zl) / (zr + zl);
    cout << "Series RLC: " << series << " |Z|=" << series.magnitude() << '\n';
    cout << "Parallel R-L: " << parallel << " |Z|=" << parallel.magnitude() << '\n';
    try {
        Complex invalid = zr / Complex();
        cout << invalid << '\n';
    } catch (const domain_error& e) {
        cout << "Error: " << e.what() << '\n';
    }
}