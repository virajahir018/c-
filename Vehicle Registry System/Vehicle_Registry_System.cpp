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

        totalVehicles++;
    }
    
    virtual void setData(){
        cout << "Enter Vehicle Id : " ; cin >> vehicleID ;  
        cout << "Enter Vehicle Manufacturer : " ; cin >> manufacturer ;  
        cout << "Enter Vehicle Model : " ; cin >> model ;  
        cout << "Enter Vehicle Year : " ; cin >> year ;  
    }
    
    virtual void display(){
        cout << " Vehicle Id : " << vehicleID << endl;  
        cout << " Vehicle Manufacturer : " << manufacturer << endl;  
        cout << " Vehicle Model : " << model << endl;  
        cout << " Vehicle Year : " << year << endl;  
    }
    
    int getID(){
        return vehicleID;
    }
        
    virtual ~Vehicle(){
        totalVehicles--;
    }
};

int Vehicle :: totalVehicles = 0;

class Car : public Vehicle{
    public:
    string fuelType;

    void setData()override{
        Vehicle::setData();
        cout << "Enter FuelType : "; cin >> fuelType ;
    }

    void display() override{
        Vehicle::display();
        cout << "FuelType : " << fuelType << endl;
    }
};

class ElectricCar :  public  Car {
    public:
    int batteryCapacity;

    void setElectriCar(){
        Car::setData();
        cout << "Enter BatteryCapacity : "; cin >> batteryCapacity;
    }

    void display() override{
        Car::display();
        cout << "BatteryCapacity : "<< batteryCapacity << endl;
    }
};

class Aircraft{
    public:
    int flightRange;

    void setAircraft(){
        cout << "Enter FlightRange : "; cin >> flightRange;
    }

    void display(){
        cout << "FlightRange : "<< flightRange << endl;
    }
};

class FlyingCar {

};

class SportsCar : public ElectricCar{
    public:
    int topSpeed;

    void setSportsCar(){
        setElectriCar();
        cout << "Enter TopSpeed : "; cin >> topSpeed;
    }

     void display(){
        ElectricCar::display();
        cout << "Enter TopSpeed : "<< topSpeed << endl;
    }
};

class Sedan : public Car{

    void display() override{
        Car::display();
    }
};

class SUV : public Car{

};


class VehicleRegistry{
    Vehicle* vehicles[50];
    int count;

    public:

    VehicleRegistry(){
        count = 0;
    }

    void addVehicle(Vehicle* v){
        if (count < 50)
        {
            vehicles[count++] = v;
        }
        
    }

    void displayAll(){
        for (int i = 0; i < count; i++)
        {
            vehicles[i]->display();
            cout << "\n";
        }
    }

    void searchById(int id){
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getID() == id)
            {
                vehicles[i]->display();
                return;
            }
        }
        cout << "ID Not Found ! \n";
    }

    ~VehicleRegistry(){
        for (int i = 0; i < count; i++)
        {
            delete  vehicles[i];
        }
    }
};

int main (){
    VehicleRegistry vr;
    int choice;

    do
    {
        cout << "\n1. Add Car\n";
        cout << "2. Add Electric Car\n";
        cout << "3. View All\n";
        cout << "4. Search by ID\n";
        cout << "5. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;

        Vehicle* v = nullptr;
        int id;
    
        switch (choice)
        {
        case 1:
            v = new Car();
            v->setData();
            vr.addVehicle(v);
            break;
        
        default:
            break;
        }
    } while (choice != 5);
    
}