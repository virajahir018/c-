#include <iostream>
using namespace std;

class Person {
    public:
    string name ;
    int age ;
};

class Student : public Person{
    public:
    int rollno;
    float mark1, mark2, mark3;
};

class Result : public Student{
    public:
    float total, percentage;

    void getDetails(){
        cout << "Enter Name : "; cin >> name;
        cout << "Enter Age : "; cin >> age;
        cout << "Enter RollNumber : "; cin >> rollno;
        cout << "Enter Mark1 : "; cin >> mark1 ;
        cout << "Enter Mark2 : "; cin >> mark2 ;
        cout << "Enter Mark3 : "; cin >> mark3;
    }

    void setDetails(){
        total = mark1 + mark2 + mark3;
        percentage = total * 100 / 300;
        
        cout << "\n\n=== Student Detail\n\n";
        cout << "Name : " << name <<endl;
        cout << "Age : " << age <<endl;
        cout << "RollNumber : " << rollno <<endl;
        cout << "\nMark1 : " << mark1  <<endl;
        cout << "Mark2 : " << mark2 <<endl ;
        cout << "Mark3 : " << mark3  <<endl;

        cout << "\nTotal Mark : " << total << endl;
        cout << "Percentage : " << percentage << "%"<< endl;
        cout << "===";
    }
};

int main (){
    Result r;
    r.getDetails();
    r.setDetails();
}