#include <iostream>
using namespace std;
int& highestMark(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) if (marks[i] > marks[best]) best = i;
    return marks[best];
}
const int& highestMarkConst(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) if (marks[i] > marks[best]) best = i;
    return marks[best];
}
int highestMarkCopy(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) if (marks[i] > marks[best]) best = i;
    return marks[best];
}
int* highestMarkPointer(int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) if (marks[i] > marks[best]) best = i;
    return &marks[best];
}
int highestMarkIndex(const int marks[], int n) {
    int best = 0;
    for (int i = 1; i < n; ++i) if (marks[i] > marks[best]) best = i;
    return best;
}
// Intentionally unsafe demonstration; never call this function.
int& danglingReference() { int local = 10; return local; }
int main() {
    int marks[] = {78, 92, 85, 88, 91}; const int n = sizeof(marks) / sizeof(marks[0]);
    cout << "Highest: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "After moderation: " << highestMarkConst(marks, n) << '\n';
    cout << "Copy: " << highestMarkCopy(marks, n) << '\n';
    int* p = highestMarkPointer(marks, n); cout << "Pointer: " << *p << '\n';
    int index = highestMarkIndex(marks, n); cout << "Index: " << index << " value: " << marks[index] << '\n';
}