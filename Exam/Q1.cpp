#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    int publishedYear;
};

int main() {
    Book books[3];   

    books[0] = {"A", "B", 2015};
    books[1] = {"C", "D", 2016};
    books[2] = {"E", "F", 2017};

    for(int i = 0; i < 3; i++) {
        cout << "\nBook " << i+1 << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Year: " << books[i].publishedYear << endl;
    }
    return 0;
}
