#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    string sound;

public:
    void setData(string n, string s) {
        name = n;
        sound = s;
    }

    string getName() { 
        return name; 
    }
    string getSound() { 
        return sound; 
    }
};

class Dog : public Animal {
public:
    void makeSound() {
        cout << "Dog Sound: " << getSound() << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "Cat Sound: " << getSound() << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    d.setData("Dog", "Bark");
    c.setData("Cat", "Meow");

    d.makeSound();
    c.makeSound();

    return 0;
}
