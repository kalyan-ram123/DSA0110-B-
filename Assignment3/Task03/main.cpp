#include <iostream>
#include <string>
using namespace std;

class Auditorium {
    int rows, seatsPerRow, bookedCount;
    bool** seats;
    string name;
public:
    Auditorium(const string& eventName, int r, int s)
        : rows(r > 0 ? r : 0), seatsPerRow(s > 0 ? s : 0), bookedCount(0), seats(nullptr), name(eventName) {
        if (rows > 0 && seatsPerRow > 0) {
            seats = new bool*[rows];
            int made = 0;
            try {
                for (; made < rows; ++made) seats[made] = new bool[seatsPerRow]{};
            } catch (...) {
                while (made > 0) delete[] seats[--made];
                delete[] seats; seats = nullptr; throw;
            }
        }
        cout << "Opened " << name << " (" << rows << 'x' << seatsPerRow << ")\n";
    }
    ~Auditorium() {
        for (int r = 0; r < rows; ++r) delete[] seats[r];
        delete[] seats;
        cout << "Closed " << name << ": " << bookedCount << " seat(s) booked\n";
    }
    bool book(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seatsPerRow || seats[r][s]) return false;
        seats[r][s] = true; ++bookedCount; return true;
    }
    bool cancel(int r, int s) {
        if (r < 0 || r >= rows || s < 0 || s >= seatsPerRow || !seats[r][s]) return false;
        seats[r][s] = false; --bookedCount; return true;
    }
    void summary() const { cout << name << " booked: " << bookedCount << '\n'; }
};

int main() {
    Auditorium stackEvent("Stack Event", 2, 3);
    stackEvent.book(0, 0); stackEvent.book(1, 2); stackEvent.cancel(0, 0);
    stackEvent.summary();
    {
        Auditorium blockEvent("Block Event", 1, 2);
        blockEvent.book(0, 1);
    }
    Auditorium* heapEvent = new Auditorium("Heap Event", 2, 2);
    heapEvent->book(1, 1); heapEvent->summary();
    delete heapEvent;
    Auditorium zeroEvent("Zero Event", 0, 5);
    zeroEvent.summary();
}