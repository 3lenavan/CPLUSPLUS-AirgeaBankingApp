// Elena Van
// 10.4.2024
// Airgead Banking App

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Class to dealing with investment calculations
class Investment {
public:

    // These are the main variables that the user will provide, and they define the investment.
    Investment(double initialAmount, double monthlyDeposit, double annualInterest, int numYears) {
        m_initialAmount = initialAmount;
        m_monthlyDeposit = monthlyDeposit;
        m_annualInterest = annualInterest;
        m_numYears = numYears;
    }

    // This calculates how much interest will be earned each year without additional deposits.
    void calculateWithoutMonthlyDeposits() {
        double balance = m_initialAmount;
        for (int year = 1; year <= m_numYears; ++year) {
            double yearlyInterest = balance * (m_annualInterest / 100);
            balance += yearlyInterest;
            m_reportsWithoutDeposits.push_back({ year, balance, yearlyInterest }); // This line helps to store the result and report the vector 
        }
    }

    // This calculates the interest while considering the monthly deposits are added.
    void calculateWithMonthlyDeposits() {
        double balance = m_initialAmount;
        for (int year = 1; year <= m_numYears; ++year) {
            double yearlyInterest = 0.0;
            for (int month = 1; month <= 12; ++month) {
                balance += m_monthlyDeposit;

                // This calculates the monthly interest that is based on the current balance.
                double monthlyInterest = balance * ((m_annualInterest / 100) / 12);
                yearlyInterest += monthlyInterest;
                balance += monthlyInterest;
            }
            m_reportsWithDeposits.push_back({ year, balance, yearlyInterest });
        }
    }

    // This prints a table with the results when there are no monthly deposits.
    void displayReportWithoutMonthlyDeposits() const {
        cout << "\n===========================================================\n";
        cout << "   Balance and Interest Without Additional Monthly Deposits\n";
        cout << "===========================================================\n";
        cout << left << setw(6) << "Year" << setw(22) << "Year End Balance" << "Year End Earned Interest\n";
        cout << "-----------------------------------------------------------\n";

        // This for loop goes through each report then prints the year, balance, and interest using proper spacing and format
        for (const auto& report : m_reportsWithoutDeposits) {
            cout << left << setw(6) << report.year
                << "$" << setw(21) << fixed << setprecision(2) << report.yearEndBalance
                << "$" << report.yearEndInterest << endl;
        }
    }

    // This prints a table with the results when monthly deposits are included.
    void displayReportWithMonthlyDeposits() const {
        cout << "\n===========================================================\n";
        cout << "   Balance and Interest With Additional Monthly Deposits\n";
        cout << "===========================================================\n";
        cout << left << setw(6) << "Year" << setw(22) << "Year End Balance" << "Year End Earned Interest\n";
        cout << "-----------------------------------------------------------\n";
        
        for (const auto& report : m_reportsWithDeposits) {
            cout << left << setw(6) << report.year
                << "$" << setw(21) << fixed << setprecision(2) << report.yearEndBalance
                << "$" << report.yearEndInterest << endl;
        }
    }

    // Private varibles for initial investment, deposits, interest and the period of time
private:
    double m_initialAmount;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numYears;

    // Holds yearly report data
    struct YearlyReport {
        int year;
        double yearEndBalance;
        double yearEndInterest;
    };

    vector<YearlyReport> m_reportsWithoutDeposits;
    vector<YearlyReport> m_reportsWithDeposits;
};

// Function to get valid positive input from the user
double getPositiveInput(const string& prompt) {
    double value;
    do {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0) {
            cout << "Invalid input. Please enter a positive number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (value < 0);
    return value;
}

int main() {
    // Get user input
    cout << "======================================\n";
    cout << "********** Data Input **********\n";
    double initialAmount = getPositiveInput("Initial Investment Amount: $");
    double monthlyDeposit = getPositiveInput("Monthly Deposit: $");
    double annualInterest = getPositiveInput("Annual Interest (%): ");
    int numYears = static_cast<int>(getPositiveInput("Number of Years: "));

    // Create an Investment object
    Investment investment(initialAmount, monthlyDeposit, annualInterest, numYears);

    // Perform calculations
    investment.calculateWithoutMonthlyDeposits();
    investment.calculateWithMonthlyDeposits();

    // Display results
    investment.displayReportWithoutMonthlyDeposits();
    investment.displayReportWithMonthlyDeposits();

    return 0;
}
