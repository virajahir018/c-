#include<iostream>
using namespace std;

class FastFoodcafe {
    private:

    int cafe_id;
    string cafe_name;
    string cafe_type;
    int cafe_rating;
    string cafe_location;
    int cafe_establish_year;
    int cafe_staff_quantity;

    static string country;

    
    public :
    FastFoodcafe (int id, string name, string type, int rating, string location, int establish_year, int staff_quantity){

        this-> cafe_id = id;
        this-> cafe_name = name;
        this-> cafe_type = type;
        this-> cafe_rating = rating;
        this-> cafe_location = location;
        this-> cafe_establish_year = establish_year;
        this-> cafe_staff_quantity = staff_quantity;
    }

    void display (){
        cout<< " Id              : "<< cafe_id<< endl;
        cout<< " Name            : "<< cafe_name<< endl;
        cout<< " Type            : "<< cafe_type<< endl;
        cout<< " Rating          : "<< cafe_rating<< endl;
        cout<< " Location        : "<< cafe_location<< endl;
        cout<< " Establish Year  : "<< cafe_establish_year<< endl;
        cout<< " Staff Quantity  : "<< cafe_staff_quantity<< endl;
        cout <<" Country         : "<< country << endl;
    } 
};

string FastFoodcafe::country = "India";

int main (){
    int n;
    cout<< "Enter Numbers of Fast Food cafe : ";
    cin>> n ;

    FastFoodcafe * cafe[n];

    for (int i = 0; i < n; i++)
    {
        int id, rating, year, quantity;
        string name, type, location;

        cout<< "\nEnter Details of Cafe : "<< i + 1<<endl;

        cout<< "Cafe Id : ";
        cin>> id ;

        
        cout<< "Cafe Name : ";
        cin>> name ;

        
        cout<< "Cafe Type (like a Rooftop or Normal) : ";
        cin>> type ;

        
        cout<< "Cafe Rating (like 1 Star, 2 Start, ..., 5 Star) : ";
        cin>> rating ;

        
        cout<< "Cafe Location (City Name) : ";
        cin>> location ;

        
        cout<< "Cafe Establish Year: ";
        cin>> year ;

        
        cout<< "Cafe Staff Quantity: ";
        cin>> quantity ;

        cafe[i] = new FastFoodcafe (id, name, type, rating, location, year, quantity);
    }

    cout << "\n\n========== COMPANY DATA =========="<<endl;

    for (int i = 0; i < n; i++)
    {
        cafe[i]->display();
        cout<<endl;
    }
    
    return 0;
    
}