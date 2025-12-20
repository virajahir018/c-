#include <iostream>
using namespace std;

class Vehicle {
    public:
    string brand;
    int speed;

    Vehicle(){
        brand  = "";
        speed = 0;
    }
};

class Car : public Vehicle{
    public:
    string fuelType;
    int seatingCapacity;

    Car (){
        fuelType = "";
        seatingCapacity = 0;
    }

    void getDetails(){
        cout << "Car Brand : " ;
        cin >> brand;
        cout << "Car Speed : " ;
        cin >> speed;
        cout << "Car FuelType  : " ;
        cin >> fuelType;
        cout << "Car SeatingCapacity : " ;
        cin >> seatingCapacity;
    }

     void setDetails(){
        cout << "\n\n=== Car Detail\n"<< endl;
        cout << "Car Brand : " << brand << endl;
        cout << "Car Speed : " << speed << endl;
        cout << "Car FuelType  : " << fuelType << endl;
        cout << "Car SeatingCapacity : " << seatingCapacity << endl;
        cout << "===";
    }
};

int main (){
    Car c;
    c.getDetails();
    c.setDetails();
}