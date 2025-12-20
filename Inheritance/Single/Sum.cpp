#include<iostream>
using namespace std;

class X{
public:
    int a,b,c;
};



class Y : public X{
    public:

    void setNum(){
        cout << "Enter Three Number : ";
        cin >> a >> b >> c ;
    }

    void getNum(){
        int cub;
        cub = ( a * a * a) + ( b * b * b) + ( c * c * c);
        cout << "Cub = " << cub ;
    }
};

int main (){

    Y y;
    y.setNum();
    y.getNum();

    return 0 ;
}