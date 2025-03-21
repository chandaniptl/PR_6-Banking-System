#include<iostream>
using namespace std;

class BankAccount
{
    public:
    int acc_no;
    string acc_holder_name;
    double balance;

    BankAccount()
    {
        acc_no=100101;
        acc_holder_name="Chandani";
        balance=50000;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout<<"Invalid Deposite Amount!"<<endl;
            return;
        }
        balance += amount;
        cout<<"Deposit Successful!"<<endl;
        cout<<"Current Balance:"<<balance<<endl; 
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout<<"Invalid Withdrawal Amount!"<<endl;
        }
        else if (amount > balance)
        {
            cout<<"Insufficient Balance! Withdrawal Denied"<<endl;
        }
        else{
            balance -= amount;
            cout<<"Withdrawal Successful!"<<endl;
            cout<<"Balance:"<<balance<<endl;
        }  
    }

    void getBalance()
    {
        cout<<"Current Balance:"<<balance<<endl;
    }

    void displayAccount()
    {
        cout<<"Account Number:"<<acc_no<<endl;
        cout<<"Acount Holder Name:"<<acc_holder_name<<endl;
        cout<<"Balance:"<<balance<<endl;
    }
};

class SavingsAccount : public BankAccount
{
    public:
    double interestRate;

    SavingsAccount()
    {
        interestRate=2.0;
    }

    void calculateInterest()
    {
        double interest = (balance * interestRate) / 100;
        balance += interest;
        cout<<"Interest Amount:"<<interest<<endl;
        cout<<"New Balance After Adding Interest:"<<balance<<endl;
    }
};

class CheckingAccount : public BankAccount
{
    public:
    int overdraft_limit;

    CheckingAccount()
    {
        overdraft_limit=40000;
    }

    void displayOverdraftLimit()
    {
        cout<<"Overdraft Limit:"<<overdraft_limit<<endl;
    }
};

class FixedDepositAccount : public BankAccount
{
    public:
    int term;
    double interest_rate;
    double fixed_balance;

    FixedDepositAccount()
    {
        term = 12;
        interest_rate=5;
        fixed_balance=0;
    }

    void depositeToFD(double amount, int month)
    {
        if (amount <= 0 || month <= 0)
        {
            cout<<"Invalid Amount!"<<endl;
            return;
        }
        fixed_balance=amount;
        term=month;
    }

    void calculateInterestFD()
    {
        double interest = (fixed_balance * interest_rate * term) / 100;
        fixed_balance += interest;
        cout<<"Fixed Deposite Interest Amount:"<<interest<<endl;
        cout<<"Total Balance In Fixed Deposit:"<<fixed_balance<<endl;
    }
};

int main()
{
    int choice;
    SavingsAccount s1;
    CheckingAccount c1;
    FixedDepositAccount f1;

    do
    {
        cout<<endl;
        cout<<"*** Banking System ***"<<endl;
        cout<<"1. Deposite"<<endl;
        cout<<"2. Withdraw"<<endl;
        cout<<"3. Check Balance"<<endl;
        cout<<"4. Display Account Info"<<endl;
        cout<<"5. Calculate Interest"<<endl;
        cout<<"6. Check Overdraft Limit"<<endl;
        cout<<"7. Deposit to Fixed Deposit"<<endl;
        cout<<"8. Exit"<<endl;

        cout<<endl;
        cout<<"Enter Your Choice:";
        cin>>choice;

        double amount;
        int term;

        switch (choice)
        {
        case 1:
            cout<<"Enter Deposit Amount:";
            cin>>amount;
            s1.deposit(amount);
            break;

            case 2:
            cout<<"Enter Withdrawal Amount:";
            cin>>amount;
            s1.withdraw(amount);
            break;

            case 3:
            s1.getBalance();
            break;

            case 4:
            s1.displayAccount();
            break;

            case 5:
            s1.calculateInterest();
            break;

            case 6:
            c1.displayOverdraftLimit();
            break;

            case 7:
            cout<<"Enter Fixed Deposit Amount:";
            cin>>amount;
            cout<<"Enter Term Duration:";
            cin>>term;
            f1.depositeToFD(amount,term);
            f1.calculateInterestFD();
            break;

            case 8:
            cout<<"Exit The Current Program!!";
            break;

        
        default:
        cout<<"Invalid Choice! Please Tray Again"<<endl;
            break;
        }
    } while (choice != 8);
    return 0;
}