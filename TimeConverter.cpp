#include <iostream>
using namespace std;

class TimeConverter {
public:

    // Convert seconds to HH:MM:SS
    void secondsToHHMMSS(int totalSeconds) {
        int hours = totalSeconds / 3600;
        totalSeconds %= 3600;

        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS => " << hours << ":" << minutes << ":" << seconds << endl;
    }

    // Convert HH:MM:SS to total seconds
    int HHMMSSToSeconds(int hours, int minutes, int seconds) {
        return hours * 3600 + minutes * 60 + seconds;
    }
};

int main() {
    TimeConverter tc;
    int choice;

    cout << "1. Convert Seconds to HH:MM:SS" << endl;
    cout << "2. Convert HH:MM:SS to Seconds" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int totalSeconds;
        cout << "Enter total seconds: ";
        cin >> totalSeconds;

        tc.secondsToHHMMSS(totalSeconds);
    }

    else if (choice == 2) {
        int h, m, s;

        cout << "Enter hours: ";
        cin >> h;

        cout << "Enter minutes: ";
        cin >> m;

        cout << "Enter seconds: ";
        cin >> s;

        int result = tc.HHMMSSToSeconds(h, m, s);
        cout << "Total seconds = " << result << endl;
    }

    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
