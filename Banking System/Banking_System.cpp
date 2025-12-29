#include<iostream>
using namespace std;

class BankAccount{
    protected:
    int accountNumber;
    string accountHolderName;
    double balance;

    public:
    BankAccount(){
        accountNumber = 0;
        accountHolderName = "";
        balance = 0;
    }

    double deposit( double amount){
        cout << "Add Deposit : "; 
        cin >> amount;
        return balance += amount;
    }

    double withdraw( double amount){
        return balance -= amount;
    }

    double getBalance(){
        return balance;
    }

    
    double setAccountInfo(){
        cout << "Enter Account Number : "; 
        cin >> accountNumber;
        cin.ignore();

        cout << "Enter Account Name : "; 
        getline(cin, accountHolderName);

        cout << "Enter Account Balance : "; 
        cin >> balance;
        cin.ignore();
    }

    double displayAccountInfo(){
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Name : " << accountHolderName << endl;
        cout << "Account Balance : " << balance << endl;
    }
};

class SavingsAccount : public BankAccount{
    protected:
    double interestRate;
};

int main (){
    BankAccount Account;

    Account.setAccountInfo();
    Account.displayAccountInfo();
}