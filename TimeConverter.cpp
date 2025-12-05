#include <iostream>
using namespace std;

class TimeConverter {
public:

    void secondsToHHMMSS(int totalSeconds) {
        int hours = totalSeconds / 3600;
        totalSeconds %= 3600;

        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        cout << "HH:MM:SS = " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main() {
    TimeConverter tc;
    
        int totalSeconds;
        cout << "Enter total seconds : ";
        cin >> totalSeconds;
        tc.secondsToHHMMSS(totalSeconds);
    
    return 0;
}
