#include <iostream>
#include <cstring>
using namespace std;

class Train {
private:
    int Tnumber;
    char Tname[50];
    char source[50];
    char destination[50];
    char Ttime[10];

    static int Tcount;

public:
    Train() {
        Tnumber = 0;
        strcpy(Tname, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(Ttime, "");
        Tcount++;
    }

    Train(int number, const char* name, const char* src,
          const char* desti, const char* time) {
        Tnumber = number;
        strcpy(Tname, name);
        strcpy(source, src);
        strcpy(destination, desti);
        strcpy(Ttime, time);
        Tcount++;
    }

    ~Train() {
        Tcount--;
    }

    void inputTrainDetails() {
        cout << "Enter Train Number : ";
        cin >> Tnumber;
        cin.ignore();

        cout << "Enter Train Name : ";
        cin.getline(Tname, 50);

        cout << "Enter Train Source : ";
        cin.getline(source, 50);

        cout << "Enter Train Destination : ";
        cin.getline(destination, 50);

        cout << "Enter Train Time : ";
        cin.getline(Ttime, 10);
    }

    void displayTrainsDetails() const {
        cout << "Train Number : " << Tnumber << endl;
        cout << "Train Name : " << Tname << endl;
        cout << "Train Source : " << source << endl;
        cout << "Train Destination : " << destination << endl;
        cout << "Train Time : " << Ttime << endl << endl;
    }

    int getTnumber() const {
        return Tnumber;
    }

    static int getTcount() {
        return Tcount;
    }
};

int Train::Tcount = 0;


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
            cout << "** Train added Successfully **\n";
        } else {
            cout << "Train list is full!\n";
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No Train Found\n";
            return;
        }

        for (int i = 0; i < totalTrains; i++) {
            cout << "\nTrain " << i + 1<< " :" << endl;
            trains[i].displayTrainsDetails();
        }
    }

    void searchTrainsByNumber(int number) const {
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTnumber() == number) {
                cout << "\n-- Train Found --\n\n";
                trains[i].displayTrainsDetails();
                return;
            }
        }
        cout << "Train Not Found\n";
    }
};


int main() {
    RailwaySystem RS;
    int choice, num;

    do {
        cout << "\n=== Railway Reservation System Menu ===\n\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            RS.addTrain();
            break;

        case 2:
            RS.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number : ";
            cin >> num;
            RS.searchTrainsByNumber(num);
            break;

        case 4:
            cout << "Exiting the program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
