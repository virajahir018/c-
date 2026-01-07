#include <iostream>
using namespace std;

#define MAX_ITEMS 10

class LibraryItems
{
private:
    string title;
    string author;
    string dueDate;

public:
    LibraryItems(string t = "", string a = "", string d = "")
    {
        title = t;
        author = a;
        dueDate = d;
    }

    string getTitle() { return title; }

    string getAuthor() { return author; }

    string getDuedate() { return dueDate; }

    void setTitle(string t) {
        if (t.empty()) throw runtime_error("Title Cannot be Empty!");
        title = t;
    }

    void setAuthor(string a) {
        if (a.empty()) throw runtime_error("Author Cannot be Empty");
        author = a;
    }

    void setDuedate(string d) {
        if (d.empty()) {
            dueDate = "";
            return;
        }

        if (d.length() != 10 || d[2] != '-' || d[5] != '-')
            throw runtime_error("Invalid date format! Use DD-MM-YYYY");
        dueDate = d;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual ~LibraryItems(){}
};

class Book : public LibraryItems {
    private:
};

class DVD : public LibraryItems {
    private:  
    string duration;
    
    public:
    DVD(string d = ""){
        duration = d;
    }

    void checkOut() override{

    }
    void returnItem() override;
    void displayDetails() const override;
};

class Magazine : public LibraryItems {
    private: 
};

int main(){
    LibraryItems* libraryItems[MAX_ITEMS];
}