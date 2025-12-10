#include<iostream>
using namespace std;

class vehical{
    public :
    int srno;


    vehical (int srno){
        this->srno = srno;
    }

    void display(){
        cout<<"srno : "<<srno<<endl;
    }

    ~vehical (){
        cout<<"Destructer is called.."<<endl;
    }
};

int main (){

    vehical v1(111);
    vehical v2(222);

    v1.display();
    v2.display();
}