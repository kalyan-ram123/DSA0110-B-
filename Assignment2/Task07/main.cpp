#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
class ShiftHistory {
    vector<int> data; size_t capacity;
public:
    explicit ShiftHistory(size_t k) : capacity(k) {}
    void add(int value) {
        if (data.size() == capacity) data.erase(data.begin());
        data.push_back(value);
    }
    size_t size() const { return data.size(); }
};
class CircularHistory {
    vector<int> data; size_t next = 0, count = 0;
public:
    explicit CircularHistory(size_t k) : data(k) {}
    void add(int value) {
        data[next] = value; next = (next + 1) % data.size();
        if (count < data.size()) ++count;
    }
    size_t size() const { return count; }
};
int main() {
    constexpr int operations = 200000; constexpr size_t capacity = 50;
    ShiftHistory shifted(capacity); CircularHistory circular(capacity);
    auto start1 = chrono::steady_clock::now();
    for (int i = 0; i < operations; ++i) shifted.add(i);
    auto end1 = chrono::steady_clock::now();
    auto start2 = chrono::steady_clock::now();
    for (int i = 0; i < operations; ++i) circular.add(i);
    auto end2 = chrono::steady_clock::now();
    cout << "Original shift size: " << shifted.size() << '\n';
    cout << "Redesigned circular size: " << circular.size() << '\n';
    cout << "Shift time (us): " << chrono::duration_cast<chrono::microseconds>(end1 - start1).count() << '\n';
    cout << "Circular time (us): " << chrono::duration_cast<chrono::microseconds>(end2 - start2).count() << '\n';
}