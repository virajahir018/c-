#include <iostream>
using namespace std;

class P{
    public:
    float temperature;
};

class Q : public P{
    public:
    float fahrenheit;

   void setTemperature(){
        cout << "Enter Temperature : " ;
        cin >> temperature ;
    }

    void toFahrenheit(){
        fahrenheit = (temperature * 9 / 5) + 32;
        cout << "Fahrenheit is : " << fahrenheit << endl;
    }
};

class R : public Q{
    public:

    void  toKelvin(){
        float kelvin;
        kelvin = (fahrenheit - 32) * 5 / 9 + 273.15;
        cout << "Kelvin is : " << kelvin ;
    }
};

int main (){
   R obj;

   obj.setTemperature();
   obj.toFahrenheit();
   obj.toKelvin();

   return 0 ;
}