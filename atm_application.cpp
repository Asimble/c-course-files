#include <iostream>
using namespace std;

class User
{
private:
    string name;
    string password;

public:
    double balance = 0;

    User(string n, string p)
    {
        name = n;
        password = p;
    }

    bool CheckName(string enteredname)
    {
        if (enteredname == name)
        {
            cout << "Correct Name" << endl;
            return 1;
        }
        else
        {
            cout << "Invalid Name" << endl;
            return 0;
        }
    }

    bool CheckPassword(string enteredpassword)
    {
        if (enteredpassword == password)
        {
            cout << "Correct Password" << endl;
            return 1;
        }
        else
        {
            cout << "Wrong Password" << endl;
            return 0;
        }
    }
};

int StartMenu()
{
    cout << "*** Main menu ***" << endl;
    cout << "1-Balance" << endl;
    cout << "2-Deposit" << endl;
    cout << "3-Withdraw" << endl;
    cout << "4-Exit" << endl;
    cout << "Selection : " << endl;

    int option;
    cin >> option;

    return option;
}

int main()
{

    User user1 = User("Asim", "12345");
    string n, p;
    cout << "*** Welcome to ATM application ***" << endl;
    cout << "*** Enter Username and Password***" << endl;
    cin >> n >> p;
    if (user1.CheckName(n) && user1.CheckPassword(p))
    {
    start:
        int i;
        i = StartMenu();

        // Used Switch Statement
        switch (i)
        {
        case 1:
            cout << "Your current balance is " << user1.balance << endl;
        case 2:
        {
            double dep;
            cout << "Enter the amount to deposit" << endl;
            cin >> dep;
            user1.balance += dep;
            break;
        }
        case 3:
        {
            double wid;
            cout << "Enter the amount to withdraw : " << endl;
            cin >> wid;
            if (wid > user1.balance)
            {
                cout << "Insufficient balance" << endl;
            }
            else
            {
                user1.balance -= wid;
            }
            break;
        }
        case 4:
            break;
        }

        cout << "*** Would your like to continue ***" << endl;
        cout << "1- Yes" << endl;
        cout << "2- No" << endl;
        cout << "Selection : ";
        int in;
        cin >> in;
        if (in == 1)
        {
            system("cls"); // Used system("cls") to clear terminal
            goto start;    // Used goto function to get to the start where i want it to
        }
    }
}