#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() {
        return 3.14 * radius * radius;
    }

    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    void draw() {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Shape* shapes[2];

    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);

    for(int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->area() << endl;
    }

    return 0;
}
