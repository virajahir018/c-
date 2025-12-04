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

    Parent obj[3]; // array of object

    obj[0].setDetails("Sachin",26);
    obj[1].setDetails("Manish",25);
    obj[2].setDetails("Vivek",24);

    obj[1].getDetails();
    obj[0].getDetails();
    obj[2].getDetails();

}