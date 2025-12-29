#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

    Vehicle() {
        totalVehicles++;
    }

    Vehicle(int id, string mfg, string mdl, int y) {
        vehicleID = id;
        manufacturer = mfg;
        model = mdl;
        year = y;
        totalVehicles++;
    }

    ~Vehicle() {
        totalVehicles--;
    }

  
    int getVehicleID() { return vehicleID; }

   void display() {
        cout << "ID : "  << vehicleID<< " \nManufacturer : " << manufacturer<< ", \nModel : " << model<< ", \nYear : " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;


class Car : public Vehicle {
public:
    string fuelType;

    Car(int id, string mfg, string mdl, int y, string fuel): Vehicle(id, mfg, mdl, y) {
        fuelType = fuel;
    }

};

class ElectricCar : public Car {
public:
    int batteryCapacity;

    ElectricCar(int id, string mfg, string mdl, int y, string fuel, int battery): Car(id, mfg, mdl, y, fuel) {
        batteryCapacity = battery;
    }

};

class SportsCar : public ElectricCar {
    public:
    int topSpeed;

    SportsCar(int id, string mfg, string mdl, int y, string fuel, int battery, int speed): ElectricCar(id, mfg, mdl, y, fuel, battery) {
        topSpeed = speed;
    }

};


class Sedan : public Car {
public:
    Sedan(int id, string mfg, string mdl, int y, string fuel): Car(id, mfg, mdl, y, fuel) {}
};

class SUV : public Car {
public:
    SUV(int id, string mfg, string mdl, int y, string fuel): Car(id, mfg, mdl, y, fuel) {}
};


class Aircraft {

public:
    int flightRange;

    Aircraft(int range) {
        flightRange = range;
    }


};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string mfg, string mdl, int y, string fuel, int range): Car(id, mfg, mdl, y, fuel), Aircraft(range) {}

};


class VehicleRegistry {
    Vehicle *vehicles[50];
    int count;

public:
    VehicleRegistry() {
        count = 0;
    }

    void addVehicle(Vehicle* v) {
        vehicles[count++] = v;
    }

    void displayAll() {
        for (int i = 0; i < count; i++) {
            vehicles[i]->display();
            cout << "------------------------" << endl;
        }
    }

    void searchByID(int id) {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                vehicles[i]->display();
                return;
            }
        }
        cout << "Vehicle not found!" << endl;
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\nVehicle Registry Menu\n";
        cout << "1. Add Sedan\n";
        cout << "2. Add SUV\n";
        cout << "3. Add Electric Sports Car\n";
        cout << "4. View All Vehicles\n";
        cout << "5. Search by ID\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        int id, year, battery, speed;
        string mfg, model, fuel;

        switch (choice) {
        case 1:
            cout << "Enter ID : ";
            cin >> id ;
            cout << "Enter Manufacturer : ";
            cin >> mfg ;
            cout << "Enter Model : ";
            cin >> model  ;
            cout << "Enter Year : ";
            cin >> year ;
            cout << "Enter Fuel : ";
            cin >> fuel; 
            registry.addVehicle(new Sedan(id, mfg, model, year, fuel));
            break;

        case 2:
            cout << "Enter ID : ";
            cin >> id ;
            cout << "Enter Manufacturer : ";
            cin >> mfg ;
            cout << "Enter Model : ";
            cin >> model  ;
            cout << "Enter Year : ";
            cin >> year ;
            cout << "Enter Fuel : ";
            cin >> fuel; 
            registry.addVehicle(new SUV(id, mfg, model, year, fuel));
            break;

        case 3:
           cout << "Enter ID : ";
            cin >> id ;
            cout << "Enter Manufacturer : ";
            cin >> mfg ;
            cout << "Enter Model : ";
            cin >> model  ;
            cout << "Enter Year : ";
            cin >> year ;
            cout << "Enter Fuel : ";
            cin >> fuel; 
            cout << "Enter Battery : ";
            cin >> battery;
            cout << "Enter Speed : ";
            cin >> speed;
            registry.addVehicle(new SportsCar(id, mfg, model, year, fuel, battery, speed));
            break;

        case 4:
            registry.displayAll();
            break;

        case 5:
            cout << "Enter Vehicle ID: ";
            cin >> id;
            registry.searchByID(id);
            break;
        }
    } while (choice != 0);

    cout << "Total Vehicles: " << Vehicle::totalVehicles << endl;
    return 0;
}