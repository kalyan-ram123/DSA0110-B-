#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title, author;
    int copies;
public:
    Book() : Book("Untitled", "Unknown", 0) {}
    explicit Book(const string& t) : Book(t, "Unknown", 1) {}
    Book(const string& t, const string& a) : Book(t, a, 1) {}
    Book(const string& t, const string& a, int c)
        : title(t), author(a), copies(c) {
        if (c < 0) throw invalid_argument("Number of copies cannot be negative");
    }
    void print() const {
        cout << title << " | " << author << " | copies: " << copies << '\n';
    }
};

int main() {
    Book empty;
    Book donated("The Alchemist");
    Book complete("Clean Code", "Robert C. Martin", 4);
    empty.print();
    donated.print();
    complete.print();
    try {
        Book invalid("Invalid Record", "Library", -5);
        invalid.print();
    } catch (const invalid_argument& e) {
        cout << "Invalid book rejected: " << e.what() << '\n';
    }
}