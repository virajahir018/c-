#include<iostream>
#include <cstring>
using namespace std;

class Student{
    private:
    char* name;
    int    rollnumber;
    double GPA;

     public:
    Student(){
        name       = nullptr;
        rollnumber = 0;
        GPA        = 0.0;
    }

    Student(const char* n, int r, double g){
        rollnumber = r;
        GPA        = g;

        name = new char[strlen(n)+ 1];
        strcpy(name, n);
    }

    Student(const Student &s){
        rollnumber = s.rollnumber;
        GPA = s.GPA;

        name = new char[strlen(s.name)+ 1];
        strcpy(name, s.name);
    }

    const char* getname(){
        return name;
    } 

    int getrollnumber(){
        return rollnumber;
    }

    double getGPA(){
        return GPA;
    }

    void display(const Student &s)const{
        cout<<"Roll No. : "<<rollnumber
        <<", Name: "<<name
        <<", GPA : "<<GPA<<endl; 
    }
    ~Student(){
        delete[] name;
    }
};

class StudentRecordManager{
    private:

    Student** Students;
    int capacity;
    int count;

public:
    StudentRecordManager(int cap = 5){
        capacity = cap;
        count    = 0;
        Students = new Student*[capacity];
    }

    void addStudent(const Student& s){
        if (count < capacity)
        {
           Students[count] = new Student(s);
           count++;
        }
        else{
            cout<<" Student list is Full "<<endl;
        }
        
    }

    void displayAll(){
          cout << "\n--- Student Records ---\n"<<endl;
        for (int i = 0; i < count; i++)
        {
           
            Students[i]->display(*Students[i]);
        }
            return;

    }

    void searchByRoll(int roll)const{
        for (int i = 0; i < count; i++)
        {
            if (Students[i]->getrollnumber() == roll)
            {
                cout<< "\nStudent Found : \n";
                Students[i]->display(*Students[i]);
                return;
            }      
        }      
        cout << "\nStudent not found!" << endl;  
    }

    // void searchByRoll(int roll) const {
    //     for (int i = 0; i < count; i++) {
    //         if (Students[i]->getrollnumber() == roll) {
    //             cout << "\nStudent Found : \n";
    //             Students[i]->display(*Students[i]);
    //             return;
    //         }
    //     }
    //     cout << "\nStudent not found!" << endl;
    // }

    ~StudentRecordManager(){
        for (int i = 0; i < count; i++)
        {
            delete Students[i];
        }
        delete [] Students;
        
    }

};

int main (){
    StudentRecordManager m;

    Student s1("Rahul", 18, 9.2);
    Student s2("Raj", 19, 8);
    Student s3("Nikunj",20,7.9);

    m.addStudent(s1);
    m.addStudent(s2);
    m.addStudent(s3);

    m.displayAll();

    m.searchByRoll(18);
    m.searchByRoll(20);

    return 0;
}