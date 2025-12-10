#include <iostream>
using namespace std;

class Diamondcompanies
{
private:
    int comp_id;
    string comp_name;
    int comp_staff_quantity;
    double comp_revenue;
    int comp_import_raw_diamonds;
    int comp_export_diamonds;
    string comp_ceo;

public:
    Diamondcompanies(int id, string name, int staff, double revenue, int raw, int export_d, string ceo)
    {
        comp_id = id ;
        comp_name = name ;
        comp_staff_quantity = staff ;
        comp_revenue = revenue;
        comp_import_raw_diamonds = raw;
        comp_export_diamonds = export_d;
        comp_ceo = ceo;
    }

    void display (){
        cout<<"\n Company Information \n";
        cout<< " ID                                : "<<comp_id<<endl;
        cout<< " Comp_name                         : "<<comp_name<<endl;
        cout<< " Comp_staff_quantity               : "<<comp_staff_quantity<<endl;
        cout<< " Comp_revenue (per year)           : "<<comp_revenue<<endl;
        cout<< " Imported Raw Diamonds (per year)  : "<<comp_import_raw_diamonds<<endl;
        cout<< " Export Diamonds (per year)        : "<<comp_export_diamonds<<endl;
        cout<< " CEO                               : "<<comp_ceo<<endl;
    }
};

int main (){
    int n;
    cout<<" Enter number of Diamond Companies : ";
    cin>>n ;

    Diamondcompanies *companies[n];

    for (int i = 0; i < n; i++)
    {
       int id, staff, raw, export_d;
       string name, ceo;
       double revenue;

       cout << "\nEnter details for Company " << i + 1 << ":\n";

        cout << "Company ID : ";
        cin >> id;

        cout << "Company Name : ";
        cin >> name;

        cout << "Staff Quantity : ";
        cin >> staff;

        cout << "Annual Revenue : ";
        cin >> revenue;

        cout << "Imported Raw Diamonds (per year) : ";
        cin >> raw;

        cout << "Export Diamonds (per year) : ";
        cin >> export_d;

        cout << "CEO Name : ";
        cin >> ceo;

        companies[i] = new Diamondcompanies(id, name, staff, revenue, raw, export_d, ceo);

    }

    cout << "\n\n========== COMPANY DATA ==========\n";

    for (int i = 0; i < n; i++)
    {
       companies[i]->display();
    }
     return 0;
    
}