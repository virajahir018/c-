#include <iostream>
using namespace std;

class vehical
{
public:
    int *srno;

    vehical(int srno)
    {
        this->srno = new int;
        *this->srno = srno;
    }

    void display()
    {
        cout << "srno :" << *srno << endl;
    }

    ~vehical(){
        cout<<"Destructor called.."<<endl;
        cout<<"SRNO : "<<*srno<<endl; 
        delete srno;
    }
};

int main (){

    vehical *v1 = new vehical(111);

    v1->display();

    delete v1;
  
}