#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Time {
    int seconds;
public:
    Time(int h = 0, int m = 0, int s = 0) : seconds(((h * 60 + m) * 60 + s) % 86400) {
        if (seconds < 0) seconds += 86400;
    }
    Time& operator++() { seconds = (seconds + 1) % 86400; return *this; }
    Time operator++(int) { Time old = *this; ++(*this); return old; }
    bool operator==(const Time& other) const { return seconds == other.seconds; }
    bool operator<(const Time& other) const { return seconds < other.seconds; }
    friend ostream& operator<<(ostream& out, const Time& t) {
        int h = t.seconds / 3600, m = (t.seconds / 60) % 60, s = t.seconds % 60;
        return out << h << ':' << (m < 10 ? "0" : "") << m << ':' << (s < 10 ? "0" : "") << s;
    }
};

class Playlist {
    vector<string> tracks;
public:
    Playlist(initializer_list<string> list) : tracks(list) {}
    string& operator[](int i) {
        if (i < 0 || i >= static_cast<int>(tracks.size())) throw out_of_range("Playlist index out of range");
        return tracks[static_cast<size_t>(i)];
    }
    const string& operator[](int i) const {
        if (i < 0 || i >= static_cast<int>(tracks.size())) throw out_of_range("Playlist index out of range");
        return tracks[static_cast<size_t>(i)];
    }
    int size() const { return static_cast<int>(tracks.size()); }
};

int main() {
    Time t(0, 0, 5);
    Time a = t++;
    Time b = ++t;
    cout << a << ' ' << b << ' ' << t << '\n';
    Time beforeNoon(11, 59, 59); ++beforeNoon;
    cout << "Rollover: " << beforeNoon << '\n';
    Playlist p{"Intro", "Main Theme", "Outro"};
    p[1] = "Updated Theme";
    const Playlist& cp = p;
    cout << p[0] << " | " << cp[1] << '\n';
    try { cout << p[-1] << '\n'; }
    catch (const out_of_range& e) { cout << e.what() << '\n'; }
    try { cout << p[p.size()] << '\n'; }
    catch (const out_of_range& e) { cout << e.what() << '\n'; }
}