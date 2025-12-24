#include <iostream>
using namespace std;

class Vehicle{
    public:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

    static int totalVehicles;

    Vehicle(){
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }
};