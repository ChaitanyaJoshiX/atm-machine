/*
Create A Object Oriented program based on the functions of an ATM Card.
Functions:
1. Activate Card
2. Deposit Money
3. Withdraw Money
4. Check Balance
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class ATMachine
{
  public:
  string name, cardnumber;
  int cardpin;
  char choice;
  double balance, amt;

  ATMachine() // Constructor to initialize wit default values
  {
    name = "";
    cardnumber = "";
    cardpin = 0;
    choice = '\u0000';
    balance = 1000.0;
    amt = 0.0;
  }

  void salutation()
  {
    cout << "=================================" << endl;
    cout << "\t  Pricson Bank " << endl;
    cout << "=================================" << endl;
    cout << "Good Day Sir/Madam!" << endl;
  }

  void activate() // Function to activate card
  {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    string temp;
    ifstream MyReadFile("cardnumber.txt"); // Reading file
    while (getline (MyReadFile, temp)) // Extracting card number from file
    {
      cardnumber = temp;
    }
    MyReadFile.close();
    cout << "Your card number is : " << cardnumber << endl;
    cout << "Set your 4 digit numeric pin : ";
    cin >> cardpin;
    cout << "Your Card is successfully activated!" << endl;
    cout << "Your account has INR 1000 by default" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  }

  void deposit() // Function to deposit money
  {
    cout << "Enter amount to be deposited : ";
    cin >> amt;
    balance += amt;
    cout << "Your account balance : INR " << balance << endl;
  }

  void withdraw() // Function to withdraw money
  {
    cout << "Enter amount to be withdrawn : ";
    cin >> amt;

    if(balance - amt == 0.0) // If the user withdraws all their money
    {
      balance -= amt;
      cout << "You have emptied your account balance" << endl;
    }

    else if(balance - amt < 0.0) // If the user tries to withdraw more than his balance
    {
      cout << "Insufficient funds!" << endl;
    }

    else
    {
      balance -= amt;
    }
    cout << "Your account balance : INR " << balance << endl;
  }

  void checkBalance() // Function to check balance
  {
    cout << "Your account balance : INR " << balance << endl;
  }

};

main()
{
  ATMachine obj; // Creating an object of ATMachine class
  obj.salutation(); // Calling the salutation method
  obj.activate(); // Calling the activate card method

  cout << "\tOptions" << endl;
  cout << "======================" << endl;
  cout << "A : Deposit cash" <<endl;
  cout << "B : Withdraw cash" <<endl;
  cout << "C : Check account balance" <<endl;
  cout << "D : End session" <<endl;
  cout << "======================" << endl;

  while(true)
  {
    cout << "Choice : ";
    cin >> obj.choice;

    if(obj.choice == 'A') // Check for amount depostion
    {
      obj.deposit();
    }
    else if(obj.choice == 'B') // Check for amount withdrawal
    {
      obj.withdraw();
    }
    else if(obj.choice == 'C')
    {
      obj.checkBalance();
    }
    else if(obj.choice == 'D')
    {
      break;
    }
    else
    {
      cout << "Invalid input! Only(A,B,C,D)" << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  }
  // Final messages
  cout << "-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
  cout << "SESSION ENDED" << endl;
  cout << "THANK YOU FOR USING PRICSON BANK ATM, GOOD DAY" << endl;
  cout << "-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x" << endl;
}
