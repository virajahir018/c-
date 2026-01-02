#include <iostream>
using namespace std;

class BankAccount
{
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int number, string name, double b)
    {
        accountNumber = number;
        accountHolderName = name;
        balance = b;
    }

    virtual void display()
    {
        cout << "\n--- Account Details ---\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Account Name   : " << accountHolderName << endl;
        cout << "Account Balance: " << balance << endl;
    }

    void deposit()
    {
        double amount;
        cout << "Enter Deposit Amount : ";
        cin >> amount;

        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit Successful!\n";
        }
        else
        {
            cout << "Invalid Amount!\n";
        }
    }

    virtual void withdraw()
    {
        double amount;
        cout << "Enter Withdraw Amount : ";
        cin >> amount;

        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        }
        else
        {
            cout << "Insufficient Balance!\n";
        }
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
    double interestRate;

public:
    SavingsAccount(int number, string name, double b, double rate)
        : BankAccount(number, name, b)
    {
        interestRate = rate;
    }

    double calculateInterest()
    {
        return balance * interestRate / 100;
    }

    void display() override
    {
        BankAccount::display();
        cout << "Interest Rate  : " << interestRate << "%" << endl;
        cout << "Interest Amount: " << calculateInterest() << endl;
    }
};

class CheckingAccount : public BankAccount
{
    double overdraftLimit;

public:
    CheckingAccount(int number, string name, double b, double limit)
        : BankAccount(number, name, b)
    {
        overdraftLimit = limit;
    }

    void withdraw() override
    {
        double amount;
        cout << "Enter Withdraw Amount : ";
        cin >> amount;

        if (balance - amount >= -overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrawal Successful!\n";
        }
        else
        {
            cout << "Overdraft Limit Exceeded!\n";
        }
    }

    void display() override
    {
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount
{
    int term;
    double rate;

public:
    FixedDepositAccount(int number, string name, double b, int t, double r)
        : BankAccount(number, name, b)
    {
        term = t;
        rate = r;
    }

    double calculateInterest()
    {
        return(balance * rate * term) / ( 12 * 100);
    }

    void display() override
    {
        BankAccount::display();
        cout << "Term (Duration In Months) : " << term << endl;
        cout << "Interest Rate  : " << rate << "%" << endl;
        cout << "Interes Is : " << calculateInterest() << endl;
    }
};

int main()
{
    BankAccount *Bank = nullptr;
    int choice;

    do
    {
        cout << "\n===== BANK ACCOUNT MENU =====\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit\n";
        cout << "5. Withdraw\n";
        cout << "6. Display Account Info\n";
        cout << "0. Exit\n";
        cout << "Enter choice : ";
        cin >> choice;

        int number, years;
        string name;
        double balance, rate, limit;

        switch (choice)
        {
        case 1:
            if (Bank != nullptr) 
            delete Bank;

            cout << "Enter Account Number : ";
            cin >> number;
            cout << "Enter Account Name   : ";
            cin >> name;
            cout << "Enter Balance        : ";
            cin >> balance;
            cout << "Enter Interest Rate  : ";
            cin >> rate;

            Bank = new SavingsAccount(number, name, balance, rate);
            break;

        case 2:
            if (Bank != nullptr) 
            delete Bank;

            cout << "Enter Account Number : ";
            cin >> number;
            cout << "Enter Account Name   : ";
            cin >> name;
            cout << "Enter Balance        : ";
            cin >> balance;
            cout << "Enter Overdraft Limit: ";
            cin >> limit;

            Bank = new CheckingAccount(number, name, balance, limit);
            break;

        case 3:
            if (Bank != nullptr) 
            delete Bank;

            cout << "Enter Account Number : ";
            cin >> number;
            cout << "Enter Account Name   : ";
            cin >> name;
            cout << "Enter Deposit Amount : ";
            cin >> balance;
            cout << "Enter Term (Duration In Months) : ";
            cin >> years;
            cout << "Enter Interest Rate  : ";
            cin >> rate;

            Bank = new FixedDepositAccount(number, name, balance, years, rate);
            break;

        case 4:
            if (Bank != nullptr)
                Bank->deposit();
            else
                cout << "Create Account First!\n";
            break;

        case 5:
            if (Bank != nullptr)
                Bank->withdraw();
            else
                cout << "Create Account First!\n";
            break;

        case 6:
            if (Bank != nullptr)
                Bank->display();
            else
                cout << "No Account Found!\n";
            break;

        case 0:
            cout << "Thank You!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 0);

    if (Bank != nullptr)
        delete Bank;

    return 0;
}
