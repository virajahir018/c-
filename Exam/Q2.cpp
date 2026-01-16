#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
    string address;

public:
    Person(string n, int a, string ad) {
        name = n;
        age = a;
        address = ad;
    }

    string getName() { 
        return name; 
    }
    int getAge() { 
        return age; 
    }
    string getAddress() { 
        return address; 
    }
};

int main() {
    int N = 3;

    Person p[] = {
        Person("Viraj", 20, "Amreli"),
        Person("Amit", 22, "Surat"),
        Person("Rahul", 25, "Vadodara")
    };

    for(int i = 0; i < N; i++) {
        cout << "\nPerson " << i+1 << endl;
        cout << "Name: " << p[i].getName() << endl;
        cout << "Age: " << p[i].getAge() << endl;
        cout << "Address: " << p[i].getAddress() << endl;
    }
    return 0;
}
