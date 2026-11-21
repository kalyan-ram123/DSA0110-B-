#include <iomanip>
#include <iostream>
#include <limits>
int main() {
    int hour = 0;
    std::cout << "Enter journey hour (0-23): ";
    while (!(std::cin >> hour) || hour < 0 || hour > 23) {
        if (std::cin.eof()) return 1;
        std::cout << "Invalid hour. Enter an integer from 0 to 23: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    std::cout << "Peak: " << std::boolalpha << peak << '\n';
    std::cout << "Sample fare: Rs " << std::fixed << std::setprecision(2) << 36.0 << '\n';
}