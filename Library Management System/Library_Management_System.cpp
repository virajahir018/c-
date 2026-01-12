#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

#define MAX_ITEMS 10

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t="", string a="", string d="") {
        title = t;
        author = a;
        dueDate = d;
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(string t) {
        if(t.empty())
            throw runtime_error("Title cannot be empty!");
        title = t;
    }

    void setAuthor(string a) {
        if(a.empty())
            throw runtime_error("Author cannot be empty!");
        author = a;
    }

    void setDueDate(string d) {
        dueDate = d;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    int pages;

public:
    Book(string t, string a, string d, int p)
        : LibraryItem(t, a, d) {
        if(p <= 0)
            throw runtime_error("Invalid page count!");
        pages = p;
    }

    void checkOut() override {
        cout << "Book checked out successfully.\n";
    }

    void returnItem() override {
        cout << "Book returned successfully.\n";
    }

    void displayDetails() const override {
        cout << "\n[BOOK]"
             << "\nTitle  : " << getTitle()
             << "\nAuthor : " << getAuthor()
             << "\nDue    : " << getDueDate()
             << "\nPages  : " << pages << endl;
    }
};

class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d) {
        if(dur <= 0)
            throw runtime_error("Invalid duration!");
        duration = dur;
    }

    void checkOut() override {
        cout << "DVD checked out successfully.\n";
    }

    void returnItem() override {
        cout << "DVD returned successfully.\n";
    }

    void displayDetails() const override {
        cout << "\n[DVD]"
             << "\nTitle    : " << getTitle()
             << "\nDirector : " << getAuthor()
             << "\nDue Date : " << getDueDate()
             << "\nDuration : " << duration << " mins\n";
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d) {
        if(issue <= 0)
            throw runtime_error("Invalid issue number!");
        issueNumber = issue;
    }

    void checkOut() override {
        cout << "Magazine checked out successfully.\n";
    }

    void returnItem() override {
        cout << "Magazine returned successfully.\n";
    }

    void displayDetails() const override {
        cout << "\n[MAGAZINE]"
             << "\nTitle  : " << getTitle()
             << "\nEditor : " << getAuthor()
             << "\nDue    : " << getDueDate()
             << "\nIssue  : " << issueNumber << endl;
    }
};

int main() {
    LibraryItem* library[MAX_ITEMS];
    int count = 0;
    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Book";
        cout << "\n2. Add DVD";
        cout << "\n3. Add Magazine";
        cout << "\n4. Display All Items";
        cout << "\n5. Check Out Item";
        cout << "\n6. Return Item";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        try {
            if(choice == 1 && count < MAX_ITEMS) {
                string t,a,d; int p;
                cout << "Title: "; cin >> t;
                cout << "Author: "; cin >> a;
                cout << "Due Date: "; cin >> d;
                cout << "Pages: "; cin >> p;
                library[count++] = new Book(t,a,d,p);
            }
            else if(choice == 2 && count < MAX_ITEMS) {
                string t,a,d; int dur;
                cout << "Title: "; cin >> t;
                cout << "Director: "; cin >> a;
                cout << "Due Date: "; cin >> d;
                cout << "Duration: "; cin >> dur;
                library[count++] = new DVD(t,a,d,dur);
            }
            else if(choice == 3 && count < MAX_ITEMS) {
                string t,a,d; int issue;
                cout << "Title: "; cin >> t;
                cout << "Editor: "; cin >> a;
                cout << "Due Date: "; cin >> d;
                cout << "Issue Number: "; cin >> issue;
                library[count++] = new Magazine(t,a,d,issue);
            }
            else if(choice == 4) {
                for(int i = 0; i < count; i++)
                    library[i]->displayDetails();
            }
            else if(choice == 5) {
                int id;
                cout << "Enter item index: ";
                cin >> id;
                if(id >= 0 && id < count)
                    library[id]->checkOut();
                else
                    cout << "Invalid item index!\n";
            }
            else if(choice == 6) {
                int id;
                cout << "Enter item index: ";
                cin >> id;
                if(id >= 0 && id < count)
                    library[id]->returnItem();
                else
                    cout << "Invalid item index!\n";
            }
        }
        catch(exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while(choice != 0);

    for(int i = 0; i < count; i++)
        delete library[i];

    cout << "Program Ended Safely.\n";
    return 0;
}
