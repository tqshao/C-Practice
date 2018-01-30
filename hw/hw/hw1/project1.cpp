/* EECS 402
   Project 1
   Shiyang Lu
   shiyoung@umich.edu
   This a basic project which implements functionality to accrue interest
   for an investment account.
*/

#include <iostream>
using namespace std;

bool accrueInterest(double &balanceAmt, 
                    const int numMonths, 
                    const bool doPrintEachMonth);
bool accrueOneMonthsInterest(double &balanceAmt, const bool doPrintInfo);


int main() {
    double balanceAmt;
    int numMonths;
    char print;

    cout << "Enter the initial balance of the account: ";
    cin >> balanceAmt;
    cout << "Enter the number of months to accrue interest: ";
    cin >> numMonths;
    cout << "Show month-by-month results - 'y' for yes, any other for no: ";
    cin >> print;

    bool success = accrueInterest(balanceAmt, numMonths, 
        print == 'y' ? true : false);
    if (!success) {
        cout << "Sorry, an error was detected.  Unable to provide results!" 
            << endl;
    }

    return 0;
}


bool accrueInterest(double &balanceAmt,
                    const int numMonths,
                    const bool doPrintEachMonth) {
    double initialBalance = balanceAmt;

    if (balanceAmt < 0) {
        cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= 0,"
            << "but the value " << balanceAmt << " was provided!" << endl;
        return false;
	}

    if (numMonths < 0) {
        cout << "ERROR in accrueInterest: numMonths must be > 0, but the value "
            << numMonths << " was provided!" << endl;
        return false;
    }

    for (int i = 0; i < numMonths; i++) {
        accrueOneMonthsInterest(balanceAmt, doPrintEachMonth);
    }

    cout << "Interest accrued for " << numMonths << " months!" << endl;
    cout << endl;
    cout << "Initial balance:" << initialBalance << endl;
    cout << "Total interest accrued: " << balanceAmt - initialBalance << endl;
    cout << "Final balance: " << balanceAmt << endl;

    return true;
}


bool accrueOneMonthsInterest(double &balanceAmt, const bool doPrintInfo) {
	if (balanceAmt < 0) {
		return false;
	}

	double interestRate;
	if (balanceAmt < 1000) {
		interestRate = 0.0015;
	} else if (balanceAmt < 15000) {
		interestRate = 0.00225;
	} else {
		interestRate = 0.004;
	}

	double initialBalance = balanceAmt;
	balanceAmt *= 1 + interestRate;

	if (doPrintInfo) {
		cout << "Accruing interest for 1 month:" << endl;
		cout << "  Initial balance: " << initialBalance << endl;
		cout << "  Initial rate: " << interestRate << endl;
		cout << "  Interest accrued: " << balanceAmt - initialBalance << endl;
		cout << "  New balance: " << balanceAmt << endl;
	}

	return true;
}
