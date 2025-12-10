#include <iostream>
#include <cstring>
using namespace std;

// ================= Train Class =================
class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;   // static member

public:
    // Default Constructor
    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    // Parameterized Constructor
    Train(int num, const char* name, const char* src,
          const char* dest, const char* time) {
        trainNumber = num;
        strcpy(trainName, name);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);
        trainCount++;
    }

    // Destructor
    ~Train() {
        trainCount--;
    }

    // Input Method
    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    // Display Method
    void displayTrainDetails() const {
        cout << "\nTrain Number : " << trainNumber;
        cout << "\nTrain Name   : " << trainName;
        cout << "\nSource       : " << source;
        cout << "\nDestination  : " << destination;
        cout << "\nTime         : " << trainTime << endl;
    }

    // Getter for Train Number
    int getTrainNumber() const {
        return trainNumber;
    }

    // Static method
    static int getTrainCount() {
        return trainCount;
    }
};

// Static member initialization
int Train::trainCount = 0;

// ================= RailwaySystem Class =================
class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
            cout << "Train added successfully!\n";
        } else {
            cout << "Train list is full!\n";
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records found.\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++) {
            cout << "\n--- Train " << i + 1 << " ---";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) const {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "\nTrain Found:";
                trains[i].displayTrainDetails();
                return;
            }
        }
        cout << "Train not found!\n";
    }
};

// ================= Main Function =================
int main() {
    RailwaySystem rs;
    int choice, num;

    do {
        cout << "\n--- Railway System Menu ---";
        cout << "\n1. Add Train";
        cout << "\n2. Display All Trains";
        cout << "\n3. Search Train by Number";
        cout << "\n4. Total Train Count";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            rs.addTrain();
            break;

        case 2:
            rs.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number to search: ";
            cin >> num;
            rs.searchTrainByNumber(num);
            break;

        case 4:
            cout << "Total Train Objects: "
                 << Train::getTrainCount() << endl;
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
