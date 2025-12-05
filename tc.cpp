#include <iostream>
using namespace std;

class Timeconverter
{
public:
    void secondsToHHMMSS(int totalseconds)
    {
        int hours = totalseconds / 3600;
        totalseconds %= 3600;

        int minutes = totalseconds / 60;
        int seconds = totalseconds % 60;

        cout << "HH:MM:SS = " << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main()
{

    Timeconverter tc;
    int totalseconds;

    cout << "Enter total second : ";
    cin >> totalseconds;
    tc.secondsToHHMMSS(totalseconds);

    return 0;
}