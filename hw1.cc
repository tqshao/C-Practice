#include <iostream>
using namespace std;

bool accrueOneMonthsInterest(double &balanceAmt, const bool doPrintInfo);
bool accrueInterest(double &balanceAmt,const int numMonths, const bool doPrintEachMOnth);

int main()
{
  double accountBalance;
  int numMonths;
  char print;
  bool success;

  //NOTE: If this weren't just a "driver program" to test the real
  //      functionality of the project, the 997.50 literal value
  //      would be considered a "magic number"!!!!!
  accountBalance;

  cout << "Enter the initial balance of the account: "; 
  cin >> accountBalance;
  cout << "Enter the number of months to accrue interest? ";
  cin >> numMonths;
  cout << "Show month-by-month results - 'y' for yes, any other for no: ";
  cin >> print;
  success = accrueInterest(accountBalance, numMonths,
                           print == 'y' ? true : false);
  if (success == false) {cout << "Sorry, an error was detected!" << endl;}
  return 0;
}

bool accrueOneMonthsInterest(double &balanceAmt,
                             const bool doPrintInfo)
{
  double initBalance = balanceAmt;
  double interestRate;
  if (balanceAmt < 1000) {interestRate = 0.0015;}
  else if (balanceAmt >= 15000) {interestRate = 0.004;}
  else {interestRate = 0.00225;}

  balanceAmt += (balanceAmt * interestRate); 
  if (doPrintInfo)
  {
    cout << "Accuring interest for 1 month: "<<endl;
    cout << "Initial balance: " <<  initBalance << endl;
    cout << "Initial Rate: " << interestRate << endl;
    cout << "INterest accrued: " << balanceAmt - initBalance << endl;
    cout << "New balance: " << balanceAmt << endl;
  }
  return true;
}

bool accrueInterest(double &balanceAmt,
                    const int numMonths, 
                    const bool doPrintEachMOnth)
{
  if (numMonths < 0 || balanceAmt < 0) 
  {
    cout << "Balance or number of months is negative!" << endl;
    return false;
  }
  else 
  {
    double initBalance = balanceAmt;
    for (int i = 0; i < numMonths; ++i) 
      {
        accrueOneMonthsInterest(balanceAmt, doPrintEachMOnth); 
      }
      cout << "Interest accrued for" << numMonths<< "months!" << endl;
      cout << endl;
      cout << "Initial balance: " << initBalance << endl;
      cout << "Total interest accrued: " <<  balanceAmt - initBalance << endl;
      cout << "Final balance:" << balanceAmt << endl;
      return true;
  }

}