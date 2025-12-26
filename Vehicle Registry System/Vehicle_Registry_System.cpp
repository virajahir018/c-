#include <iostream>
using namespace std;

// ------------------ Vehicle ------------------

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
        cout << "\nEnter Vehicle Id : ";
        cin >> vehicleID;
        cin.ignore();

        cout << "Enter Vehicle Manufacturer : ";
        getline(cin, manufacturer);

        cout << "Enter Vehicle Model : ";
        getline(cin, model);

        cout << "Enter Vehicle Year : ";
        cin >> year;
        cin.ignore();
    }

    virtual void display(){
        cout << "Vehicle Id : " << vehicleID << endl;
        cout << "Manufacturer : " << manufacturer << endl;
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
    }

    int getID() const{
        return vehicleID;
    }

    virtual ~Vehicle(){
        totalVehicles--;
    }
};

int Vehicle::totalVehicles = 0;

// ------------------ Car ------------------

class Car : public Vehicle{
public:
    string fuelType;

    void setData() override{
        Vehicle::setData();
        cout << "Enter Fuel Type : ";
        cin >> fuelType;
    }

    void display() override{
        Vehicle::display();
        cout << "Fuel Type : " << fuelType << endl;
    }
};

// ------------------ Electric Car ------------------

class ElectricCar : public Car{
public:
    int batteryCapacity;

    void setData() override{
        Car::setData();
        cout << "Enter Battery Capacity : ";
        cin >> batteryCapacity;
    }

    void display() override{
        Car::display();
        cout << "Battery Capacity : " << batteryCapacity << endl;
    }
};

// ------------------ Vehicle Registry ------------------

class VehicleRegistry{
    Vehicle* vehicles[50];
    int count;

public:
    VehicleRegistry(){
        count = 0;
    }

    void addVehicle(Vehicle* v){
        if(count < 50){
            vehicles[count++] = v;
            cout << "\n** Vehicle Added Successfully **\n";
        } else {
            cout << "\nVehicle Registry Full!\n";
            delete v;
        }
    }

    void displayAll(){
        if(count == 0){
            cout << "\nNo Vehicles Available!\n";
            return;
        }

        cout << "\n--- Vehicle List ---\n\n";
        for(int i = 0; i < count; i++){
            vehicles[i]->display();
            cout << "------------------------\n\n";
        }
    }

    void searchById(int id) const {
        for(int i = 0; i < count; i++){
            if(vehicles[i]->getID() == id){
                cout << "\n--- Vehicle Found ---\n";
                vehicles[i]->display();
                return;
            }
        }
        cout << "\nID Not Found!\n";
    }

    ~VehicleRegistry(){
        for(int i = 0; i < count; i++){
            delete vehicles[i];
        }
    }
};

// ------------------ MAIN ------------------

int main(){
    VehicleRegistry vr;
    int choice;

    do{
        cout << "\n====== Vehicle Registry System ======\n\n";
        cout << "1. Add Car\n";
        cout << "2. Add Electric Car\n";
        cout << "3. View All Vehicles\n";
        cout << "4. Search Vehicle by ID\n";
        cout << "5. Total Vehicles\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        Vehicle* v = nullptr;
        int id;

        switch(choice){
        case 1:
            v = new Car();
            break;

        case 2:
            v = new ElectricCar();
            break;

        case 3:
            vr.displayAll();
            break;

        case 4:
            cout << "Enter Vehicle ID : ";
            cin >> id;
            vr.searchById(id);
            break;

        case 5:
            cout << "\nTotal Vehicles : " << Vehicle::totalVehicles << endl;
            break;

        case 6:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

        if (v) {
            v->setData();
            vr.addVehicle(v);
        }

    } while(choice != 6);

    return 0;
}
