#include <iostream>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) {
        name = n;
    }

    virtual void displayDetails() {
        cout << "Animal Name: " << name << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void displayDetails() override {
        cout << "Dog Name: " << name << ", Sound: Bark" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}

    void displayDetails() override {
        cout << "Cat Name: " << name << ", Sound: Meow" << endl;
    }
};

int main() {
    Animal* animals[2];

    animals[0] = new Dog("Buddy");
    animals[1] = new Cat("Kitty");

    for(int i = 0; i < 2; i++) {
        animals[i]->displayDetails();
    }

    return 0;
}
