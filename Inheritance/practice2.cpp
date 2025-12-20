#include <iostream>
using namespace std;

class Employee{
    public:
    int empId;
    string name;


    Employee(){
        empId = 0;
        name = "";
    }
};

class EmployeeSalary : public Employee{
    public:
    int basicSalary, HRA, DA;

    EmployeeSalary(){
        basicSalary = 0;
        HRA = 0;
        DA = 0;
    }

    void setDetails(){
        cout << "Enter Employee Id : " ; 
        cin >> empId ;
        cout << "Enter Employee Name : " ;
        cin >> name ; 
        cout << "Enter Employee BasicSalary : " ;
        cin >> basicSalary ; 
        cout << "Enter Employee HRA : " ;
        cin >> HRA ;
        cout << "Enter Employee DA : " ;
        cin >> DA ; 
    }

    void getDetails(){
        cout << "\n=== Employee Details ==="<< endl;
        cout << "Employee Id : "<< empId << endl ; 
        cout << "Employee Name : " << name << endl;
        cout << "Employee BasicSalary : " << basicSalary << endl ; 
        cout << "Employee HRA : " << HRA << endl;
        cout << "Employee DA : " << DA << endl;
    }

    void display(){
        int totalsalary;
        totalsalary = basicSalary + HRA + DA ;
        cout << "\nTotal Salary : "<< totalsalary ;
    }
};

int main (){
    EmployeeSalary Salary;
    Salary.setDetails();
    Salary.getDetails(); 
    Salary.display();
}