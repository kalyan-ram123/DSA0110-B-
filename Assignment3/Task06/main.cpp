#include <cstring>
#include <iostream>
using namespace std;

class Text {
    char* data;
public:
    Text(const char* s = "") {
        size_t n = strlen(s);
        data = new char[n + 1];
        memcpy(data, s, n + 1);
    }
    Text(const Text& other) {
        size_t n = strlen(other.data);
        data = new char[n + 1];
        memcpy(data, other.data, n + 1);
    }
    Text& operator=(const Text& other) {
        if (this != &other) {
            size_t n = strlen(other.data);
            char* fresh = new char[n + 1];
            memcpy(fresh, other.data, n + 1);
            delete[] data;
            data = fresh;
        }
        return *this;
    }
    ~Text() { delete[] data; }
    Text& operator+=(const Text& other) {
        size_t a = strlen(data), b = strlen(other.data);
        char* fresh = new char[a + b + 1];
        memcpy(fresh, data, a);
        memcpy(fresh + a, other.data, b + 1);
        delete[] data;
        data = fresh;
        return *this;
    }
    friend Text operator+(const Text& a, const Text& b) {
        Text result(a);
        result += b;
        return result;
    }
    friend bool operator==(const Text& a, const Text& b) { return strcmp(a.data, b.data) == 0; }
    friend bool operator!=(const Text& a, const Text& b) { return !(a == b); }
    friend ostream& operator<<(ostream& out, const Text& t) { return out << t.data; }
};

int main() {
    Text a("Hello"), b(" World"), c("!");
    Text message = a + b + c;
    cout << message << '\n';
    Text copy = message;
    copy = copy;
    cout << boolalpha << (copy == message) << ' ' << (copy != a) << '\n';
    Text empty;
    cout << "Empty: [" << empty << "]\n";
    Text longText("A long SMS message can be safely copied and concatenated.");
    Text combined = longText + message;
    cout << combined << '\n';
}