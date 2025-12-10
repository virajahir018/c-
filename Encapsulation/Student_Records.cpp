#include <iostream>
#include <cstring>
using namespace std;

/* =======================
   Student Class
   ======================= */
class Student {
private:
    char* name;        // dynamically allocated string
    int rollNo;
    float gpa;

public:
    // Default constructor
    Student() {
        name = nullptr;
        rollNo = 0;
        gpa = 0.0f;
    }

    // Parameterized constructor
    Student(const char* n, int r, float g) {
        rollNo = r;
        gpa = g;

        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Copy constructor (DEEP COPY)
    Student(const Student& s) {
        rollNo = s.rollNo;
        gpa = s.gpa;

        if (s.name != nullptr) {
            name = new char[strlen(s.name) + 1];
            strcpy(name, s.name);
        } else {
            name = nullptr;
        }
    }

    // Getter methods
    const char* getName() const {
        return name;
    }

    int getRollNo() const {
        return rollNo;
    }

    float getGPA() const {
        return gpa;
    }

    // Display student details (using reference variable)
    void display(const Student& s) const {
        cout << "Roll No: " << s.rollNo
             << ", Name: " << s.name
             << ", GPA: " << s.gpa << endl;
    }

    // Destructor
    ~Student() {
        delete[] name;
    }
};

/* =======================
   StudentRecordManager Class
   ======================= */
class StudentRecordManager {
private:
    Student** students;   // dynamic array of Student pointers
    int capacity;
    int count;

public:
    // Constructor
    StudentRecordManager(int cap = 5) {
        capacity = cap;
        count = 0;
        students = new Student*[capacity];
    }

    // Add new student (using reference)
    void addStudent(const Student& s) {
        if (count < capacity) {
            students[count] = new Student(s); // copy constructor called
            count++;
        } else {
            cout << "Student list is full!" << endl;
        }
    }

    // Display all students
    void displayAll() const {
        cout << "\n--- Student Records ---\n";
        for (int i = 0; i < count; i++) {
            students[i]->display(*students[i]);
        }
    }

    // Search student by roll number
    void searchByRoll(int roll) const {
        for (int i = 0; i < count; i++) {
            if (students[i]->getRollNo() == roll) {
                cout << "\nStudent Found:\n";
                students[i]->display(*students[i]);
                return;
            }
        }
        cout << "\nStudent not found!" << endl;
    }

    // Destructor (Memory cleanup)
    ~StudentRecordManager() {
        for (int i = 0; i < count; i++) {
            delete students[i];
        }
        delete[] students;
    }
};

/* =======================
   Main Function (Testing)
   ======================= */
int main() {
    StudentRecordManager manager;

    Student s1("Rahul", 101, 8.5);
    Student s2("Anita", 102, 9.1);
    Student s3("Vikas", 103, 7.9);

    manager.addStudent(s1);
    manager.addStudent(s2);
    manager.addStudent(s3);

    manager.displayAll();

    manager.searchByRoll(102);
    manager.searchByRoll(110);

    return 0;
}
