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
        balance = 0.0;
    }
    
    virtual void setData(){
        cout << "\nEnter Account Number : "; 
        cin >> accountNumber;
        cin.ignore();
        
        cout << "Enter Account Name : "; 
        getline(cin, accountHolderName);

        cout << "Enter Account Balance : "; 
        cin >> balance;
        cin.ignore();
    }

    virtual void display(){
        cout << "\n--- Account Details ---\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Name : " << accountHolderName << endl;
        cout << "Account Balance : " << balance << endl;
    }


    virtual void deposit(){
        double amount;
        cout << "Enter Deposit Amount : ";
        cin >> amount;
        cin.ignore();

       if (amount > 0)
       {
        balance += amount;
        cout <<"Deposit successful!\n";
       } else{
        cout << "Invalid amount!\n";
       } 
    }
    
    virtual void withdraw(){
        double amount;
        cout << "Enter Withdraw Amount : ";
        cin >> amount;
        cin.ignore();
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful\n";
        }else{
            cout << "Insufficient balance!\n";
        }
        
    }
    
    double getBalance(){
        return balance;
    }

    virtual~BankAccount(){}
};

class SavingsAccount : public BankAccount{
    protected:
    double interestRate;

    public:
    SavingsAccount(){
        interestRate = 0.0;
    }

    void setData() override {
        BankAccount::setData();
        cout << "Enter Interest Rate (%) : ";
        cin >> interestRate;
        cin.ignore();
    }

    void display() override{
        BankAccount::display();
        cout << "Interest Rate : " << interestRate << "%" << endl;
        cout << "Interest Is : " <<  calculateInterest() << endl;
    }

    double calculateInterest(){
        return balance * interestRate / 100;
    }
};

class CheckingAccount : public BankAccount {
    protected:
    double overdraftLimit;

    public:
    CheckingAccount(){
        overdraftLimit = 0.0;
    }

     void setData() override {
        BankAccount::setData();
        cout << "Enter Overdraft Limit : ";
        cin >> overdraftLimit;
        cin.ignore();
    }

    void display() override{
        BankAccount::display();
        cout << "Overdraft Limit : " << overdraftLimit << "%" << endl;
    }

    void withdraw() override{
        double amount;
        cout << "Enter Withdraw Amount : ";
        cin >> amount;
        cin.ignore();
        if (balance - amount >= -overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrawal Successful \n";
        } else {
            cout << "Overdraft Limit Exceeded\n";
        } 
    }
};

class FixedDepositAccount : public BankAccount{
    protected:
    double term;
    double rate;

    public:
    FixedDepositAccount(){
        term = 0.0;
        rate = 0.0;
    }

    void setData()override{
        BankAccount::setData();
        cout << "Enter Term (duration in months) : ";
         cin >> term;
        cin.ignore();
        cout << "Enter Rate : ";
        cin >> rate;
        cin.ignore();
    }

    void display()override{
        BankAccount::display();
        cout << "Term : " << term << endl;
        cout << "Rate : " << rate << endl;
        cout << "Interes Is : " << calculateInterest() << endl;
    }

    double calculateInterest(){
        return balance * rate * term / (12 * 100);
    }
};

int main (){
    BankAccount* Account = nullptr;
    int choice;

    do
    {
        cout << "\n===== BANK ACCOUNT MENU =====\n";
        cout << "\n1. Create Savings Account";
        cout << "\n2. Create Checking Account";
        cout << "\n3. Create Fixed Deposit Account";
        cout << "\n4. Deposit";
        cout << "\n5. Withdraw";
        cout << "\n6. Display Account Info";
        cout << "\n0. Exit";
        cout << "\nEnter choice : ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            delete Account;
            Account = new SavingsAccount();
            Account->setData();
            cout << "Savings Account Created!\n";
            break;  

        case 2:
            delete Account;
            Account = new CheckingAccount();
            Account->setData();
            cout << "Checking Account Created!\n";
            break;

        case 3:
            delete Account;
            Account = new FixedDepositAccount();
            Account->setData();
            cout << "Fixed Deposit Account Created!\n";
            break;  

        case 4:
            if (Account)
            {
                Account->deposit();
            }
            else{
                cout << "Create account first!\n";
            }
            break;

        case 5:
           if (Account)
            {
                Account->withdraw();
            }
            else{
                cout << "Create account first!\n";
            }
            break;
        
        case 6:
           if (Account)
            {
                Account->display();
            }
            else{
                cout << "Create account first!\n";
            }
            break;
        
        case 0:
            cout << "Thank You!";
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }

    } while (choice != 0);

    delete Account;
    return 0;
}