#include<iostream>
using namespace std;

// class create
class Parent{
    private:
    string name;
    int age;

    public:
    // setter method
    void setDetails(string name, int age){
        this->name = name;
        this->age = age;
    }

    // getter method
    void getDetails(){
        cout<<"Your name : "<<name<<endl;
        cout<<"Your age : "<<age<<endl;
    }

};

int main(){

    // object create

    Parent obj,obj2;

    obj.setDetails("A",22);
    obj.getDetails();

    obj2.setDetails("B",24);
    obj2.getDetails();


}