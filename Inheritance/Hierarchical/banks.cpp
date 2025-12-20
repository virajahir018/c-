#include <iostream>
using namespace std;

class RBI {
public:
       float rate;
       void getROI()
       {
        cout << "Rate of Interest : " << rate << "%" << endl;
       }
};

class SBI : public RBI{
    public:
    SBI (){ rate = 7.1; }
};

class BOB : public RBI{
    public:
    BOB (){ rate = 6.5; }
};

class ICICI : public RBI{
    public:
    ICICI (){ rate = 8.1; }
};

int main (){
   SBI s; BOB b; ICICI c;
   cout << "SBI "; s.getROI();
   cout << "BOB "; b.getROI();
   cout << "ICICI "; c.getROI();
}