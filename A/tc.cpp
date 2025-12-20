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

    int HHMMSStoseconds(int hours, int minutes, int seconds){
        return hours * 3600 + minutes * 60 + seconds;
    }
};

int main()
{

    Timeconverter tc;
    int totalseconds;
    int choice;

    cout<<"1. Convert Seconds to HH:MM:SS"<<endl;
    cout<< "2. Convert HH:MM:SS to Seconds"<<endl;
    cout<<"Enter your choice : ";
    cin >>choice;


    if (choice == 1)
    {
        cout << "Enter total second : ";
    cin >> totalseconds;
    tc.secondsToHHMMSS(totalseconds);
    }

    else if(choice == 2){
        int h,m,s;
        
        cout<<"Enter hours : ";
        cin>> h;

        
        cout<<"Enter minutes : ";
        cin>> m;

        
        cout<<"Enter seconds : ";
        cin>> s;

        int result = tc.HHMMSStoseconds(h,m,s);
        cout<<"Total seconds : " <<result<<endl;
    }

    else{

        cout << "Invalid choice!" << endl;
    }
    

    return 0;
}