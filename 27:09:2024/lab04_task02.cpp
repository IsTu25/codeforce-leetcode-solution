#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    string accountType;
    double currentBalance;
    const double minimumBalance;
    static int totalAccountsCreated;
    static int activeAccounts;
    static double totalSourceTaxCollected;

public:
    
    BankAccount(string accNum, string holderName, string accType, double curBalance, double minBalance)
        : accountNumber(accNum), accountHolderName(holderName), accountType(accType), currentBalance(curBalance), minimumBalance(minBalance) {
        totalAccountsCreated++;
        activeAccounts++;
        if (currentBalance < minimumBalance) {
            cout << "Error: Initial balance is less than minimum balance!" << endl;
            currentBalance = minimumBalance;
        }
    }

    
    ~BankAccount() {
        cout << "Account of Mr./Ms. " << accountHolderName << " with account no " << accountNumber 
             << " is destroyed with a balance of BDT " << currentBalance << endl;
        activeAccounts--;
    }

   
    void showAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: " << currentBalance << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }

    
    void showBalance() const {
        cout << "Current Balance: BDT " << currentBalance << endl;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Deposit amount must be greater than zero." << endl;
        } else {
            currentBalance += amount;
            cout << "Deposit successful! New balance: BDT " << currentBalance << endl;
        }
    }

    
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Withdrawal amount must be greater than zero." << endl;
        } else if (currentBalance - amount < minimumBalance) {
            cout << "Error! Withdrawal would breach the minimum balance." << endl;
        } else {
            currentBalance -= amount;
            cout << "Withdrawal successful! New balance: BDT " << currentBalance << endl;
        }
    }

    
    void giveInterest(double interestRate = 0.03) {
        double interest = currentBalance * interestRate;
        double sourceTax = interest * 0.10;
        totalSourceTaxCollected += sourceTax;
        currentBalance += (interest - sourceTax);
        cout << "Interest applied! New balance: BDT " << currentBalance << endl;
    }

    
    double getCurrentBalance() const {
        return currentBalance;
    }

    static int getTotalAccountsCreated() {
        return totalAccountsCreated;
    }

    static int getActiveAccounts() {
        return activeAccounts;
    }

    static double getTotalSourceTaxCollected() {
        return totalSourceTaxCollected;
    }
};


int BankAccount::totalAccountsCreated = 0;
int BankAccount::activeAccounts = 0;
double BankAccount::totalSourceTaxCollected = 0.0;


void display_stat() {
    cout << "Total number of BankAccount objects created: " << BankAccount::getTotalAccountsCreated() << endl;
    cout << "Total number of active BankAccount objects: " << BankAccount::getActiveAccounts() << endl;
    cout << "Total source tax collected: BDT " << BankAccount::getTotalSourceTaxCollected() << endl;
}


BankAccount Larger(const BankAccount& A, const BankAccount& B) {
    if (A.getCurrentBalance() > B.getCurrentBalance()) {
        return A;
    } else {
        return B;
    }
}


int main() {
    BankAccount acc1("12345", "John Doe", "Savings", 5000.0, 1000.0);
    BankAccount acc2("67890", "Jane Doe", "Current", 8000.0, 2000.0);

    acc1.showAccountInfo();
    acc1.deposit(2000);
    acc1.withdraw(1000);
    acc1.giveInterest();

    acc2.showAccountInfo();
    acc2.deposit(3000);
    acc2.withdraw(500);
    acc2.giveInterest(0.04);

    BankAccount largerAcc = Larger(acc1, acc2);
    cout << "The account with a larger balance belongs to: " << largerAcc.getCurrentBalance() << endl;

    display_stat();

    return 0;
}
