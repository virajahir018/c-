#include <iostream>
using namespace std;

class A {
    public:
    int n1;
    
    A(int a){
        n1 = a;
    }
};


class B : public A {
    public:
    int n2;
    
    B(int a, int b) : A(a){
        n2 = b;
    }
};


class C {
    public:
    int n3;
    
    C(int c){
        n3 = c;
    }
};


class D : public B, public C {
    public:
    int n4;
    
    D(int a, int b, int c, int d) : B(a, b), C(c){
        n4 = d;
    }

    void display(){
            int sum;
            sum = n1 + n2 + n3 + n4;
            cout << "Sum of All Number : " << sum ; 
    }
};

int main (){
    D d(1,2,3,4);
    d.display();
}