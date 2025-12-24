#include <iostream>
using namespace std;

/* Base Class */
class Person {
protected:
    int id;
    string name;
    int age;

public:
    Person(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }

    void setPerson(){
        cout << "\nEnter ID : " ; cin >> id;
        cout << "Enter Name : " ; cin >> name;
        cout << "Enter Age : " ; cin >> age;
    }

    void getPerson() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

/* Derived Class: Student */
class Student : public Person {
    string course;
    float cgpa;

public:
    Student(int i, string n, int a, string c, float g)
        : Person(i, n, a) {
        course = c;
        cgpa = g;
    }

    void setStudent() {
        setPerson();
        cout << "Course : "; cin >> course ;
        cout << "CGPA : "; cin >> cgpa ;
    }

    void getStudent() {
        cout << "=== Student Details"<<endl;
        getPerson();
        cout << "Course : " << course << endl;
        cout << "CGPA : " << cgpa << endl;
        cout << "===";
    }
};

/* Derived Class: Professor */
class Professor : public Person {
    string department;
    double salary;

public:
    Professor(int i, string n, int a, string d, double s)
        : Person(i, n, a) {
        department = d;
        salary = s;
    }

    void setProfessor() {
        setPerson();
        cout << "Department: "; cin >> department ;
        cout << "Salary: "; cin >> salary ;
    }

    void getProfessor() {
        cout << "=== Professor Details"<<endl;
        getPerson();
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
        cout << "===";
    }
};

/* Derived Class: TeachingAssistant */
class TeachingAssistant : public Person {
    string subject;
    int hours;

public:
    TeachingAssistant(int i, string n, int a, string sub, int h): Person(i, n, a){
        subject = sub;
        hours = h;
    }

    void setTA() {
        setPerson();
        cout << "Subject: "; cin >> subject;
        cout << "Working Hours: "; cin >> hours;
    }

    void getTA() {
        cout << "=== TeachingAssistant Details"<<endl;
        getPerson();
        cout << "Subject: " << subject << endl;
        cout << "Working Hours: " << hours << endl;
        cout << "===";
    }
};

/* Main Function */
int main() {
    Student s(0, "", 0, "", 0.0);
    Professor p(0, "", 0, "", 0.0);
    TeachingAssistant t(0, "", 0, "", 0);

    cout << "\n--- Student Details ---\n";
    s.setStudent();
    s.getStudent();

    cout << "\n--- Professor Details ---\n";
    p.setProfessor();
    p.getProfessor();


    cout << "\n--- Teaching Assistant Details ---\n";
    t.setTA();
    t.getTA();


    return 0;
}
