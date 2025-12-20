#include <iostream>
using namespace  std;

class Person {
    public:
    string name ;
    int age;

    Person(string n, int a){
        name = n;
        age = a;
    }
};

class Student : public Person{
    public:
    int rollno, marks;

    Student(string n, int a, int r, int m) : Person(n, a){
        rollno = r;
        marks = m;
    }

    void display(){
        cout << "Student Name : " << name << endl 
        << "Student Age : " << age << endl
        << "Student RollNumber : " << rollno << endl
        << "Student Marks : " << marks ;  
    }
};

int main (){
    Student s1("Sa", 22, 18, 100);
    s1.display();

    return 0;
}