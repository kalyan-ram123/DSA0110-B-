#include <iostream>
#include <string>
using namespace std;
class SavingsAccount {
    long long accountNumber;
    double balance;
    double transactions[10]{};
    int count = 0, next = 0;
    void record(double amount) {
        transactions[next] = amount; next = (next + 1) % 10;
        if (count < 10) ++count;
    }
public:
    explicit SavingsAccount(long long number, double openingBalance = 0.0)
        : accountNumber(number), balance(openingBalance) {}
    void deposit(double amount) { if (amount > 0) { balance += amount; record(amount); } }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) { balance -= amount; record(-amount); }
    }
    void miniStatement() const;
};
void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << "\nBalance: " << balance << "\nRecent transactions:\n";
    int start = (count == 10) ? next : 0;
    for (int i = 0; i < count; ++i) cout << transactions[(start + i) % 10] << '\n';
}
int main() {
    SavingsAccount account(192421289, 1000);
    for (int i = 1; i <= 11; ++i) account.deposit(i * 10);
    account.withdraw(25); account.miniStatement();
}